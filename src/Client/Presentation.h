#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "Window.h"
#include "TextureManager.h"

class Presentation {
private:
    Window& window;
    TextureManager& manager;
public:
    Presentation(Window& window, TextureManager& manager);

    void run();

    ~Presentation();

};

#endif
