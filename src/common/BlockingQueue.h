#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>
#include <stdexcept>

#define ERRORMSG "No hay elementos en la cola y no se bloquea al realizar el pop"

//La clase Blocking Queue permite un acceso controlado a los recursos
//encolados para que cada uno de los jugadores saquen un numero a la vez.
template<typename ITEM>
class BlockingQueue {
private:
	std::queue<ITEM> blocking_queue;
    mutable std::mutex m;
    std::condition_variable cv;
	bool blockAtPop;
    
public:
	//Constructores para la clase Blocking Queue, se permite el constructor
	//por movimiento, no asi por copia dado que no nos interesa que una queue
	//sea copiada.
	BlockingQueue(bool blockPop) : blockAtPop(blockPop){}

	BlockingQueue(BlockingQueue &&other) {
		std::unique_lock<std::mutex> lock(m);
    	this->blocking_queue = std::move(other.blocking_queue);
	}

    BlockingQueue& operator=(BlockingQueue &&other) {
		std::unique_lock<std::mutex> lock(m);
   		this->blocking_queue = std::move(other.blocking_queue);
    	return *this;
	}
	
	//Se realiza el pop del primer elemento de la queue y lo retorna. En caso 
	//de que esté vacía, se queda esperando a que aparezca una nueva unidad
	//del recurso. En caso de que la queue esté cerrada lanza una excepción.
	ITEM pop() {
		std::unique_lock<std::mutex> lock(m);
		while(blocking_queue.empty() && blockAtPop){
			cv.wait(lock);
		}
		if (blocking_queue.empty() && !blockAtPop)
			throw std::out_of_range(ERRORMSG);
		ITEM value(std::move(blocking_queue.front()));
		blocking_queue.pop();
		return value;
	}

	//Se pushea el value en la cola bloqueante. Luego notifica a todos aquellos
	//que estén esperando.
	void push(ITEM value) {
		std::unique_lock<std::mutex> lock(m);
		blocking_queue.push(std::move(value));
		cv.notify_all();
	}
	
	bool empty() const {
		std::unique_lock<std::mutex> lock(m);
		return this->blocking_queue.empty();
	}

	~BlockingQueue(){}

	BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue &operator=(const BlockingQueue&) = delete;
};

#endif
