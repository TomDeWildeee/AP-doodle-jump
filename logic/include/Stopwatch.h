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

    std::chrono::steady_clock::time_point lastTime;
};

} // namespace Logic

#endif // DOODLE_JUMP_STOPWATCH_H
