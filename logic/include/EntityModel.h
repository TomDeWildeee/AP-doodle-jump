/**
 * @file EntityModel.h
 * @brief Base class for all game entities
 */

#ifndef DOODLE_JUMP_ENTITYMODEL_H
#define DOODLE_JUMP_ENTITYMODEL_H

#include "Subject.h"

namespace Logic {

/**
 * @class EntityModel
 * @brief Abstract base class for all game entities
 *
 * Provides common functionality for position, velocity and observer pattern implementation
 */
class EntityModel : public Logic::Subject {
public:
    /**
     * @brief Constructs an entity at specified coordinates
     * @param coords Initial x,y coordinates
     */
    explicit EntityModel(const std::pair<float, float>& coords);
    ~EntityModel() override;

    /**
     * @brief Updates entity state
     * @param deltaTime Time elapsed since last update
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Gets current coordinates
     * @return Current x,y position
     */
    [[nodiscard]] const std::pair<float, float>& getCoords() const;

    /**
     * @brief Gets current velocity
     * @return Current velocity vector
     */
    [[nodiscard]] const std::pair<float, float>& getVelocity() const;

    /**
     * @brief Sets entity coordinates
     * @param pair New x,y coordinates
     */
    void setCoords(const std::pair<float, float>& pair);

    /**
     * @brief Sets entity velocity
     * @param pair New velocity vector
     */
    void setVelocity(const std::pair<float, float>& pair);

protected:
    std::pair<float, float> coords;
    std::pair<float, float> velocity;
};
} // namespace Logic

#endif // DOODLE_JUMP_ENTITYMODEL_H
