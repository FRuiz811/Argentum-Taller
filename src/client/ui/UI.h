#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "../Window.h"
#include "../../common/Point.h"
#include "../MusicManager.h"
#include "../Player.h"
#include "../Font.h"
#include "SelectButton.h"
#include "RaisedButton.h"
#include "ArrowButton.h"
#include <vector>
#include "NPCInterface.h"
union SDL_Event;

//Clase encargada de renderizar el estado general de todo el jugador.

class UI {
private:
    Player* playerTarget = nullptr; //Jugador del cual debe mostrar estadisticas.
    Window& window;
    const TextureManager& manager;
    const MusicManager& mixer;
    Font font;
    //Interfaz del NPC con el que se está interactuando
    std::shared_ptr<NPCInterface> npc{nullptr};

    std::vector<SDL_Texture*> texts; //Textos que se muestran en la interfaz
    std::vector<SDL_Texture*> info; //Informacion de los stats del jugador
    std::vector<std::shared_ptr<RaisedButton>> buttonsInventory; //Botones del inventario
    std::vector<ItemsInventoryID> itemsID; //Id de los items que estén disponibles en el inventario
    std::vector<std::shared_ptr<SelectButton>> buttonsItems; //Items mostrados en el inventario
    std::vector<std::shared_ptr<SelectButton>> buttonsBuild; //Items mostrados en el equipamiento
    std::shared_ptr<RaisedButton> unequipButton;

    NPCInfo informationNPC;
    int widthSegment;
    int itemSelected{-1};
    int buildSelected{-1};
    int maxExpPreviousLevel{0};
    int maxExpActualLevel{0};

    //Son las funciones encargadas de actualizar el estado general del jugador
    void updateStates();
    void updateHealth();
    void updateMana();
    void updateGold();
    void updateLevelAndExpirience();
    void deleteInfo();

    //Actualiza el inventario del jugador, mostrando por pantalla los items y 
    //botones que este tiene disponible para equiparse, vender o tirar.
    void updateInventory();
    void updateItems();
    
    //Actualiza el equipamiento del jugador en caso de que este no esté interactuando
    //En caso de que su estado sea de interactuar, graficará lo que el profesional
    //tenga para mostrar y permitira realizar las acciones disponibles.
    void updateEquipment();
    void updateInteract();
    void updateBuild();

    void createTexts();
    
public:
    UI(Window& window, Player* player, const TextureManager& manager, const MusicManager& mixer);

    void render();
    
    //Función llamada para actualizar la información del NPC con el que se está
    //interactuando.
    void setNPCInfo(NPCInfo info);

    //Realiza el manejo de los eventos de click.
    //Actualizará el item seleccionado en el inventario, permitirá realizar la 
    //acción correspondiente a cada botón o delegará ese manejo al NPCInterface
    //correspondiente
    InputInfo handleClick(SDL_Event& event);

    ~UI();
};

#endif