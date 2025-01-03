/**
 * @file BGTile.h
 * @brief Background tile entity class for the game's background elements
 */

#ifndef DOODLE_JUMP_BGTILE_H
#define DOODLE_JUMP_BGTILE_H

#include "EntityModel.h"

namespace Logic {

/**
 * @class BGTile
 * @brief Represents a background tile in the game
 *
 * Background tiles are static visual elements that make up the game's background
 */
class BGTile : public EntityModel {
public:
    /**
     * @brief Constructs a BGTile at specified coordinates
     * @param coords The x,y coordinates for the tile's position
     */
    explicit BGTile(const std::pair<float, float>& coords);

    /**
     * @brief Updates the tile's state
     * @param deltaTime Time elapsed since last update
     */
    void update(float deltaTime) override;
};

} // namespace Logic

#endif // DOODLE_JUMP_BGTILE_H
