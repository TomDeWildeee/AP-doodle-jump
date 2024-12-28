#ifndef DOODLE_JUMP_CAMERA_H
#define DOODLE_JUMP_CAMERA_H

namespace Logic {

class Camera {
public:
    Camera(float width, float height);
    void update(float newY);
    void worldToScreen(float& x, float& y) const;
    [[nodiscard]] bool isVisible(float y) const;
    [[nodiscard]] float getY() const;

private:
    float width;
    float height;
    float y;
    float minY;
    float maxY;
};

} // namespace Logic

#endif // DOODLE_JUMP_CAMERA_H
