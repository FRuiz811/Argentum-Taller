#ifndef CHRONO_H
#define CHRONO_H
#include <chrono>

class Chrono {
private:
    std::chrono::high_resolution_clock::time_point time;
public:
    Chrono();
    
    //Devuelve la cantidad de milisegundos que hubo entre 2 llamadas a esta 
    //funcion o con la creación del cronómetro.
    double lap();

    ~Chrono();
};

#endif
