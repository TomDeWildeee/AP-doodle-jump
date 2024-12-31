#ifndef DOODLE_JUMP_ENTITYMODEL_H
#define DOODLE_JUMP_ENTITYMODEL_H

#include "Subject.h"
namespace Logic {
class EntityModel : public Logic::Subject {
public:
    explicit EntityModel(const std::pair<float, float>& coords);
    ~EntityModel() override;

    virtual void update(float deltaTime) = 0;

    [[nodiscard]] const std::pair<float, float>& getCoords() const;
    [[nodiscard]] const std::pair<float, float>& getVelocity() const;

    void setCoords(const std::pair<float, float>& pair);
    void setVelocity(const std::pair<float, float>& pair);

protected:
    std::pair<float, float> coords;
    std::pair<float, float> velocity;
};
} // namespace Logic

#endif // DOODLE_JUMP_ENTITYMODEL_H
