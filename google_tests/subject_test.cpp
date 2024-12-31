#include "../../include/logic/Observer.h"
#include "../../include/logic/Subject.h"
#include <gtest/gtest.h>
#include <memory>

class TestObserver : public Logic::Observer {
public:
    bool updated = false;

    void update() override { updated = true; }
};

TEST(SubjectTest, AttachAndNotifyObserver) {
    Logic::Subject subject;
    auto observer = std::make_shared<TestObserver>();

    subject.attach(observer);
    subject.notify();

    ASSERT_TRUE(observer->updated);
}

TEST(SubjectTest, DetachObserver) {
    Logic::Subject subject;
    auto observer = std::make_shared<TestObserver>();

    subject.attach(observer);
    subject.detach(observer);
    observer->updated = false;
    subject.notify();

    ASSERT_FALSE(observer->updated);
}