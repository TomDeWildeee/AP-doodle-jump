#ifndef DOODLE_JUMP_GAMEEXCEPTION_H
#define DOODLE_JUMP_GAMEEXCEPTION_H
#include <exception>
#include <string>
namespace Logic {

class GameException : public std::exception {
public:
    explicit GameException(std::string message);
    [[nodiscard]] const char* what() const noexcept override;

private:
    std::string message;
};

class ResourceLoadException : public GameException {
public:
    explicit ResourceLoadException(const std::string& resource);
};

class InvalidCoordinatesException : public GameException {
public:
    explicit InvalidCoordinatesException(const std::string& message);
};

class NotInitializedException : public GameException {
public:
    explicit NotInitializedException(const std::string& message);
};

} // namespace Logic

#endif // DOODLE_JUMP_GAMEEXCEPTION_H
