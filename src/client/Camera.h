#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "../common/Point.h"

//Clase destinada a mantener centrada la camara del juego sobre
//el jugador que es seteado como target.

class Camera {
private:
    Window& window;
    float width, height; //Limites del mapa
    float scale; 
    Point* playerTarget = nullptr; //Jugador en el cual se debe centrar la camara.
    Point positionScreen; //
    SDL_Rect cam; //Dimensiones de la cámara.
    
    //Ajusta la posición destiny para que nunca se pase de los límites del mapa.
    void limits(Point* destiny);
public:
    Camera(Window& window, float widthMap, float heightMap);

    SDL_Rect getCamera() const;  

    float getCameraWidth() const;

    float getCameraHeight() const;

    Point getCameraPosition() const;
    
    float getScale() const;

    void setPlayer(Point* player);

    void render(Point destiny);

    //Devuelve verdadero en caso de que el click haya sido realizado
    //dentro del Viewport de la camara.
    bool clickInMap(Point coordinates) const;
    
    //Devuelve un Point de acuerdo a las coordenadas globales,
    //sacandole el relativo de la camara.
    Point calculateGlobalPosition(Point coordinates) const;

    //Devuelve la distancia que hay entre el Point coordinates y
    //el target que tiene ajustado la cámara.
    int distanceFromTarget(Point coordinates) const;

    ~Camera();
};

#endif 
