#include "Random.h"
#include <random>

float Random::getFloat(float minRand, float maxRand) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(minRand, maxRand);
    return dist(mt);
}

int Random::get(int minRand, int maxRand) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minRand, maxRand);
    return dist(mt);
}
