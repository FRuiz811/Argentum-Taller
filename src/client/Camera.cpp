#include "Camera.h"
#include <algorithm>
#include <SDL2/SDL.h>

#define WIDTHSEGMENT 8
#define TOPBARHEIGHT 60

Camera::Camera(Window& window, float widthMap, float heightMap) : window(window),
    width(widthMap), height(heightMap), scale(1.0f) {
    this->positionScreen = Point(0.0,float(this->window.getHeight())/2.0);
    this->cam = {(this->window.getWidth()/WIDTHSEGMENT)*2,TOPBARHEIGHT,(this->window.getWidth()/WIDTHSEGMENT)*6, this->window.getHeight()-TOPBARHEIGHT};
}

float Camera::getCameraWidth() const {
    return float(this->window.getWidth());
}

float Camera::getCameraHeight() const {
    return float(this->window.getHeight());
}

SDL_Rect Camera::getCamera() const {
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
        float limitHeight = (this->window.getHeight()-TOPBARHEIGHT) / 2.0f;

        destiny->y = std::max(destiny->y,limitHeight);
        destiny->y = std::min(destiny->y, this->height-limitHeight);
        destiny->x= std::min(destiny->x, this->width-limitWidth);
        destiny->x= std::max(destiny->x, limitWidth);
    }

}

Point Camera::calculateGlobalPosition(Point coordinates) const {
    float x = coordinates.x +(positionScreen.x-cam.x);
    float y = coordinates.y + (positionScreen.y-cam.y);
    return Point(x,y);
}

bool Camera::clickInMap(Point coordinates) const {
    bool inMap = false;
    if (coordinates.x > cam.x && coordinates.x < cam.x+cam.w &&
        coordinates.y > cam.y && coordinates.y < cam.y+cam.h)
        inMap = true;
    return inMap;
}

void Camera::render(Point destiny) {
    limits(&destiny);
    this->cam = {(this->window.getWidth()/WIDTHSEGMENT)*2,TOPBARHEIGHT,(this->window.getWidth()/WIDTHSEGMENT)*6,
                this->window.getHeight()-TOPBARHEIGHT};
    this->positionScreen.x = destiny.x - (((this->window.getWidth()/WIDTHSEGMENT)*6) / 2.0f);
    this->positionScreen.y = destiny.y - ((this->window.getHeight() - TOPBARHEIGHT) / 2.0f);
    SDL_Rect display = {(this->window.getWidth()/WIDTHSEGMENT) * 2,TOPBARHEIGHT,
            (this->window.getWidth()/WIDTHSEGMENT) * 6,this->window.getHeight() - TOPBARHEIGHT};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &display);
}

int Camera::distanceFromTarget(Point coordinates) const {
    return this->playerTarget->distance(coordinates);
}

Camera::~Camera()= default;