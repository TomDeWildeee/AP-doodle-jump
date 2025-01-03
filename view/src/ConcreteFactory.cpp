#include "../include/ConcreteFactory.h"
#include "../include/BGTileView.h"
#include "../include/BonusView.h"
#include "../include/PlatformView.h"
#include "../include/PlayerView.h"
#include "GameException.h"

namespace View {

std::shared_ptr<Logic::Player> ConcreteFactory::createPlayer(const std::pair<float, float>& coords) {
    if (coords.first < 0 || coords.first > 480) {
        throw Logic::InvalidCoordinatesException("Player coordinates out of bounds");
    }
    std::shared_ptr<Logic::Player> player = std::make_shared<Logic::Player>(coords);
    std::shared_ptr<PlayerView> playerView = std::make_shared<PlayerView>(player);
    player->attachViewObserver(playerView);
    views.push_back(playerView);
    return player;
}

std::shared_ptr<Logic::Platform> ConcreteFactory::createPlatform(const std::pair<float, float>& coords,
                                                                 Logic::PlatformType type) {
    if (coords.first < 0 || coords.first > 480) {
        throw Logic::InvalidCoordinatesException("Platform coordinates out of bounds");
    }
    std::shared_ptr<Logic::Platform> platform = std::make_shared<Logic::Platform>(coords, type);
    std::shared_ptr<PlatformView> platformView = std::make_shared<PlatformView>(platform);
    platform->attachViewObserver(platformView);
    views.push_back(platformView);
    return platform;
}

std::shared_ptr<Logic::BGTile> ConcreteFactory::createBGTile(const std::pair<float, float>& coords) {
    if (coords.first < 0 || coords.first > 480) {
        throw Logic::InvalidCoordinatesException("BGTile coordinates out of bounds");
    }
    std::shared_ptr<Logic::BGTile> bgTile = std::make_shared<Logic::BGTile>(coords);
    std::shared_ptr<BGTileView> bgTileView = std::make_shared<BGTileView>(bgTile);
    bgTile->attachViewObserver(bgTileView);
    views.insert(views.begin(), bgTileView);
    return bgTile;
}

std::shared_ptr<Logic::Bonus> ConcreteFactory::createBonus(const std::pair<float, float>& coords,
                                                           Logic::BonusType type) {
    if (coords.first < 0 || coords.first > 480) {
        throw Logic::InvalidCoordinatesException("Bonus coordinates out of bounds");
    }
    std::shared_ptr<Logic::Bonus> bonus = std::make_shared<Logic::Bonus>(coords, type);
    std::shared_ptr<BonusView> bonusView = std::make_shared<BonusView>(bonus);
    bonus->attachViewObserver(bonusView);
    views.push_back(bonusView);
    return bonus;
}
std::vector<std::shared_ptr<EntityView>>& ConcreteFactory::getViews() { return views; }

void ConcreteFactory::cleanupViews(float maxY) {

    views.erase(
        std::remove_if(views.begin(), views.end(), [maxY](const auto& view) { return view->isOffScreen(maxY); }),
        views.end());
}

ConcreteFactory::~ConcreteFactory() = default;

} // namespace View