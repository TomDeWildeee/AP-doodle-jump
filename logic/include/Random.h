/**
 * @file Random.h
 * @brief Singleton class for random number generation
 */

#ifndef DOODLE_JUMP_RANDOM_H
#define DOODLE_JUMP_RANDOM_H

#include <random>
namespace Logic {

/**
 * @class Random
 * @brief Provides random number generation functionality using Mersenne Twister (mt19937)
 */
class Random {
public:
    /**
     * @brief Gets singleton instance
     * @return Reference to Random singleton
     */
    static Random& getInstance();

    /**
     * @brief Generates random float in range
     * @param min Minimum value
     * @param max Maximum value
     * @return Random float between min and max
     */
    float getFloat(float min, float max);

    /**
     * @brief Generates random integer in range
     * @param min Minimum value
     * @param max Maximum value
     * @return Random integer between min and max
     */
    int getInt(int min, int max);

private:
    Random();
    // Found mt19937 online, not sure if it's the best choice
    // https://dassencio.org/78
    std::mt19937 generator;
};

} // namespace Logic

#endif // DOODLE_JUMP_RANDOM_H
