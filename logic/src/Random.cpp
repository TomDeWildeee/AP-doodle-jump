#include "../include/Random.h"

namespace Logic {

Random::Random() : generator(std::random_device()()) {}

Random& Random::getInstance() {
    static Random instance;
    return instance;
}

float Random::getFloat(float min, float max) {
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}

int Random::getInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
} // namespace Logic