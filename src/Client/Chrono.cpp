#include "Chrono.h"

Chrono::Chrono() {
    this->time = std::chrono::high_resolution_clock::now();
}

double Chrono::lap() {
    std::chrono::high_resolution_clock::time_point now = 
        std::chrono::high_resolution_clock::now();
    
    double dt = std::chrono::duration_cast<std::chrono::duration<double>>(now - time).count();
    this->time = now;
    return dt;
}

Chrono::~Chrono() {}