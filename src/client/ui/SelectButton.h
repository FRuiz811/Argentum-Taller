#ifndef SELECTBUTTON_H
#define SELECTBUTTON_H

#include "Button.h"

class SelectButton: public Button {
private:
    int id;
public:
    SelectButton(SDL_Renderer* renderer,SDL_Rect position, const TextureManager& manager, int id);

    virtual bool inside(int x, int y);

    virtual void render();

    void onClick();

    int getId();

    virtual void updatePosition(SDL_Rect position);

    void setViewport(SDL_Rect viewport);

    ~SelectButton();
};

#endif