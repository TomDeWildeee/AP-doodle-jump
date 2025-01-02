#ifndef DOODLE_JUMP_RANDOM_H
#define DOODLE_JUMP_RANDOM_H

#include <random>
namespace Logic {

class Random {
public:
    static Random& getInstance();
    float getFloat(float min, float max);
    int getInt(int min, int max);

private:
    Random();
    // Found mt19937 online, not sure if it's the best choice
    // https://dassencio.org/78
    std::mt19937 generator;
};

} // namespace Logic

#endif // DOODLE_JUMP_RANDOM_H
