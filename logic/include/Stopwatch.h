/**
 * @file Stopwatch.h
 * @brief Singleton class for game timing
 */

#ifndef DOODLE_JUMP_STOPWATCH_H
#define DOODLE_JUMP_STOPWATCH_H

#include <chrono>
namespace Logic {

/**
 * @class Stopwatch
 * @brief Manages game timing and delta time calculations
 */
class Stopwatch {
public:
    /**
     * @brief Gets singleton instance
     * @return Reference to Stopwatch instance
     */
    static Stopwatch& getInstance();

    /**
     * @brief Gets time elapsed since last tick
     * @return Delta time in seconds
     */
    [[nodiscard]] float getDeltaTime() const;

    /**
     * @brief Starts the stopwatch
     */
    void start();

    /**
     * @brief Updates delta time
     */
    void tick();

private:
    Stopwatch();
    float deltaTime = 0.0f;

    std::chrono::steady_clock::time_point lastTime;
};

} // namespace Logic

#endif // DOODLE_JUMP_STOPWATCH_H
