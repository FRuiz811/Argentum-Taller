#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "../common/Point.h"

class Camera {
private:
    Window& window;
    float width, height; //Limites del mapa
    float scale; //Escala de pixel/metro 
    Point* playerTarget = nullptr; //Jugador en el cual se debe centrar la camara.
    Point positionScreen;
    SDL_Rect cam;

    void limits(Point* destiny);
public:
    Camera(Window& window, float widthMap, float heightMap);

    SDL_Rect getCamera(); 

    float getCameraWidth() const;

    float getCameraHeight() const;

    Point getCameraPosition() const;
    
    float getScale() const;

    void setPlayer(Point* player);

    void update(Point destiny);
    
    Point calculateGlobalPosition(Point coordinates);

    ~Camera();
};

#endif 
