#include "../headers/view/ConcreteFactory.h"
#include "../headers/view/BGTileView.h"
#include "../headers/view/BonusView.h"
#include "../headers/view/PlatformView.h"
#include "../headers/view/PlayerView.h"
#include <iostream>

namespace View {

std::shared_ptr<Logic::Player> ConcreteFactory::createPlayer(const std::pair<float, float>& coords) {
    std::shared_ptr<Logic::Player> player = std::make_shared<Logic::Player>(coords);
    std::shared_ptr<PlayerView> playerView = std::make_shared<PlayerView>(player);
    player->attach(playerView);
    views.push_back(playerView);
    return player;
}

std::shared_ptr<Logic::Platform> ConcreteFactory::createPlatform(const std::pair<float, float>& coords,
                                                                 Logic::PlatformType type) {
    std::shared_ptr<Logic::Platform> platform = std::make_shared<Logic::Platform>(coords, type);
    std::shared_ptr<PlatformView> platformView = std::make_shared<PlatformView>(platform);
    platform->attach(platformView);
    views.push_back(platformView);
    return platform;
}

std::shared_ptr<Logic::BGTile> ConcreteFactory::createBGTile(const std::pair<float, float>& coords) {
    std::shared_ptr<Logic::BGTile> bgTile = std::make_shared<Logic::BGTile>(coords);
    std::shared_ptr<BGTileView> bgTileView = std::make_shared<BGTileView>(bgTile);
    bgTile->attach(bgTileView);
    views.push_back(bgTileView);
    return bgTile;
}

std::shared_ptr<Logic::Bonus> ConcreteFactory::createBonus(const std::pair<float, float>& coords,
                                                           Logic::BonusType type) {
    std::shared_ptr<Logic::Bonus> bonus = std::make_shared<Logic::Bonus>(coords, type);
    std::shared_ptr<BonusView> bonusView = std::make_shared<BonusView>(bonus);
    bonus->attach(bonusView);
    views.push_back(bonusView);
    return bonus;
}
std::vector<std::shared_ptr<EntityView>>& ConcreteFactory::getViews() { return views; }

// This took way too long to find out
void ConcreteFactory::cleanupViews(float maxY) {
    views.erase(
        std::remove_if(views.begin(), views.end(), [maxY](const auto& view) { return view->isOffScreen(maxY); }),
        views.end());
}

} // namespace View