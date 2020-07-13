#ifndef NPCINTERFACE_H
#define NPCINTERFACE_H

#include "../../common/Identificators.h"
#include <SDL2/SDL.h>
#include "../Window.h"
#include "../TextureManager.h"
#include <memory>
#include "../Player.h"
#include "../Font.h"
#include "RaisedButton.h"

class NPCInterface {
protected:
    NPCInfo information;
    SDL_Texture* texture = nullptr;
    Window* window;
    const TextureManager& manager;
    Player* player;
    Font font;
    std::shared_ptr<RaisedButton> createButtonAction(ActionsProfessionID action,SDL_Rect rect);
public:
    NPCInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player);

    virtual void render() = 0;

    void update(NPCInfo npcInfo);

    virtual InputInfo handleClick(int x, int y, int itemSelected) = 0;

    ~NPCInterface();

};


#endif
