#include "../include/Stopwatch.h"

namespace Logic {

Stopwatch::Stopwatch() = default;

Stopwatch& Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

void Stopwatch::start() { lastTime = std::chrono::steady_clock::now(); }

float Stopwatch::getDeltaTime() const { return deltaTime; }

void Stopwatch::tick() {

    // Compute delta time between frames and update last time to current time for next frame calculation
    auto currentTime = std::chrono::steady_clock::now();
    deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
    lastTime = currentTime;
}

} // namespace Logic