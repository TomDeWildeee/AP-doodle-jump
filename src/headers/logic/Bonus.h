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
    [[nodiscard]] BonusType getType() const;
    void activate(const std::shared_ptr<Player>& player);

private:
    BonusType type;
    bool active = true;
};

} // namespace Logic

#endif // DOODLE_JUMP_BONUS_H
