/**
 * @file Camera.h
 * @brief Defines the game's camera system for viewport management
 */

#ifndef DOODLE_JUMP_CAMERA_H
#define DOODLE_JUMP_CAMERA_H

namespace Logic {

/**
 * @class Camera
 * @brief Manages the game's viewport
 */
class Camera {
public:
    /**
     * @brief Constructs a camera with specified dimensions
     * @param width Viewport width
     * @param height Viewport height
     */
    Camera(float width, float height);

    /**
     * @brief Updates camera position
     * @param newY New vertical position
     */
    void update(float newY);

    /**
     * @brief Checks if a point is visible in the camera
     * @param y Vertical position to check
     * @return True if visible, false otherwise
     */
    [[nodiscard]] bool isVisible(float y) const;

    /**
     * @brief Gets current camera Y position
     * @return Current vertical position
     */
    [[nodiscard]] float getY() const;

    /**
     * @brief Gets the buffer zone for visibility checks
     * @return Buffer zone size
     */
    [[nodiscard]] float getBufferzone() const;

private:
    float width;
    float height;
    float y;
    float minY;
    float maxY;
    float bufferZone = height / 2 + 200.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_CAMERA_H
