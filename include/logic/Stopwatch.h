#ifndef DOODLE_JUMP_STOPWATCH_H
#define DOODLE_JUMP_STOPWATCH_H

#include <chrono>
namespace Logic {

class Stopwatch {
public:
    static Stopwatch& getInstance();

    [[nodiscard]] float getDeltaTime() const;
    void start();
    void tick();

private:
    Stopwatch();
    float deltaTime = 0.0f;

    // Found high_resolution_clock online, not sure if it's the best choice
    std::chrono::steady_clock::time_point lastTime;
};

} // namespace Logic

#endif // DOODLE_JUMP_STOPWATCH_H
