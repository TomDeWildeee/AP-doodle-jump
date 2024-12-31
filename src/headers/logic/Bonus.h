#ifndef DOODLE_JUMP_BONUS_H
#define DOODLE_JUMP_BONUS_H

#include "EntityModel.h"
#include "Player.h"
namespace Logic {

enum class BonusType { SPRING, JETPACK };

class Bonus : public EntityModel {
public:
    Bonus(const std::pair<float, float>& coords, BonusType type);

    void update(float deltaTime) override;
    void activate(const std::shared_ptr<Player>& player);

    [[nodiscard]] BonusType getType() const;
    [[nodiscard]] bool isActive() const;

private:
    bool active = false;
    BonusType type;
    std::weak_ptr<Player> activePlayer;

    float jetpackForce = -800.0f;
    float jetpackDuration = 2.0f;
    float jetpackTimer = 0.0f;
};

} // namespace Logic

#endif // DOODLE_JUMP_BONUS_H
