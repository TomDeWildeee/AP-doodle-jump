#include "../../include/logic/Subject.h"
#include "../../include/logic/ViewObserver.h"
#include <gtest/gtest.h>
#include <memory>

class TestObserver : public Logic::ViewObserver {
public:
    bool updated = false;

    void updateEntityView() override { updated = true; }
};

TEST(SubjectTest, AttachAndNotifyObserver) {
    Logic::Subject subject;
    auto observer = std::make_shared<TestObserver>();

    subject.attachViewObserver(observer);
    subject.notifyEntityUpdate();

    ASSERT_TRUE(observer->updated);
}

TEST(SubjectTest, DetachObserver) {
    Logic::Subject subject;
    auto observer = std::make_shared<TestObserver>();

    subject.attachViewObserver(observer);
    subject.detachViewObserver(observer);
    observer->updated = false;
    subject.notifyEntityUpdate();

    ASSERT_FALSE(observer->updated);
}