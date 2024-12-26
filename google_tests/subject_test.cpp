#include "../../src/headers/logic/Observer.h"
#include "../../src/headers/logic/Subject.h"
#include <gtest/gtest.h>
#include <memory>

class TestObserver : public Logic::Observer {
public:
    bool updated = false;

    void update() override { updated = true; }
};

class TestSubject : public Logic::Subject {
public:
    using Logic::Subject::notify;
};

TEST(SubjectTest, AttachAndNotifyObserver) {
    TestSubject subject;
    auto observer = std::make_shared<TestObserver>();

    subject.attach(observer);
    subject.notify();

    ASSERT_TRUE(observer->updated);
}

TEST(SubjectTest, DetachObserver) {
    TestSubject subject;
    auto observer = std::make_shared<TestObserver>();

    subject.attach(observer);
    subject.detach(observer);
    observer->updated = false;
    subject.notify();

    ASSERT_FALSE(observer->updated);
}