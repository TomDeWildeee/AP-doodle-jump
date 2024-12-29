#ifndef DOODLE_JUMP_CONCRETEFACTORY_H
#define DOODLE_JUMP_CONCRETEFACTORY_H

#include "../logic/EntityFactory.h"
#include "EntityView.h"
namespace View {

class ConcreteFactory : public Logic::EntityFactory {
public:
    std::shared_ptr<Logic::Player> createPlayer(const std::pair<float, float>& coords) override;
    std::shared_ptr<Logic::Platform> createPlatform(const std::pair<float, float>& coords,
                                                    Logic::PlatformType type) override;
    std::shared_ptr<Logic::BGTile> createBGTile(const std::pair<float, float>& coords) override;
    std::shared_ptr<Logic::Bonus> createBonus(const std::pair<float, float>& coords, Logic::BonusType type) override;

    std::vector<std::shared_ptr<EntityView>>& getViews();
    void cleanupViews(float maxY) override;

private:
    std::vector<std::shared_ptr<EntityView>> views;
};

} // namespace View

#endif // DOODLE_JUMP_CONCRETEFACTORY_H
