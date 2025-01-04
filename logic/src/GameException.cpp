#include "../include/GameException.h"

#include <utility>

namespace Logic {
GameException::GameException(std::string message) : message(std::move(message)) {}

const char* GameException::what() const noexcept { return message.c_str(); }

ResourceLoadException::ResourceLoadException(const std::string& resource)
    : GameException("Could not load resource: " + resource) {}

InvalidCoordinatesException::InvalidCoordinatesException(const std::string& message)
    : GameException("Invalid coordinates: " + message) {}

NotInitializedException::NotInitializedException(const std::string& message)
    : GameException("Not initialized: " + message) {}

} // namespace Logic
