#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "Point.h"

class Camera {
private:
    Window& window;
    float width, height; //Limites del mapa
    float scale; //Escala de pixel/metro 
    Point* player = nullptr; //Jugador en el cual se debe centrar la camara.
    Point positionScreen;
    SDL_Rect cam;
public:
    Camera(Window& window, float widthMap, float heightMap);

    SDL_Rect getCamera(); 

    float getCameraWidth() const;

    float getCameraHeight() const;

    Point getCameraPosition() const;
    
    float getScale() const;

    void limits(Point* destiny);

    void setPlayer(Point* player);

    void update(float dt);
    
    void moveTo(Point destiny);

    ~Camera();
};

#endif 
