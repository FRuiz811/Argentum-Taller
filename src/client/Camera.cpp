#include "Camera.h"
#include <algorithm>
#include <SDL2/SDL.h>

#define WIDTHSEGMENT 8

Camera::Camera(Window& window, float widthMap, float heightMap) : window(window),
    width(widthMap), height(heightMap), scale(1.0f) {
    this->positionScreen = Point(0.0,float(this->window.getHeight())/2.0);
    this->cam = {(this->window.getWidth()/WIDTHSEGMENT)*2,60,(this->window.getWidth()/WIDTHSEGMENT)*6, this->window.getHeight()-60};
}

float Camera::getCameraWidth() const {
    return float(this->window.getWidth());
}

float Camera::getCameraHeight() const {
    return float(this->window.getHeight());
}

SDL_Rect Camera::getCamera() {
    return this->cam;
}

float Camera::getScale() const{
    return this->scale;
}

Point Camera::getCameraPosition() const {
    return this->positionScreen;
}

void Camera::setPlayer(Point* player){
    this->playerTarget = player;
}

void Camera::limits(Point* destiny) {
    if (this->playerTarget != nullptr) {  
        float limitWidth = ((this->window.getWidth()/WIDTHSEGMENT)*6) / 2.0f;
        float limitHeight = (this->window.getHeight()-60) / 2.0f;

        destiny->y = std::max(destiny->y,limitHeight);
        destiny->y = std::min(destiny->y, this->height-limitHeight);
        destiny->x= std::min(destiny->x, this->width-limitWidth);
        destiny->x= std::max(destiny->x, limitWidth);
    }

}

Point Camera::calculateGlobalPosition(Point coordinates) const {
    float x = this->cam.x + coordinates.x;
    float y = this->cam.y + coordinates.y;
    return Point(x,y);
}

void Camera::update(Point destiny) {
    limits(&destiny);
    this->cam.x = destiny.x;
    this->cam.y = destiny.y;
    this->cam.h = this->window.getHeight();
    this->cam.w = this->window.getWidth();
    this->positionScreen.x = this->cam.x - (((this->window.getWidth()/WIDTHSEGMENT)*6) / 2.0f);
    this->positionScreen.y = this->cam.y - ((this->window.getHeight() - 60) / 2.0f);
    SDL_Rect display = {(this->window.getWidth()/WIDTHSEGMENT) * 2,60,
            (this->window.getWidth()/WIDTHSEGMENT) * 6,this->window.getHeight() - 60};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &display);
}

Camera::~Camera()= default;