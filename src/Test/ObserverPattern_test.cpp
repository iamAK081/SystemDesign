#include "ObserverPattern.h"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

// Mock observer for testing
class TestObserver : public Observer {
public:
    std::vector<std::string> messages;
    void update(const std::string& message) override {
        messages.push_back(message);
    }
};

TEST(ObserverPattern, AttachAndNotify) {
    auto subject = std::make_shared<ConcreteSubject>();
    auto observer1 = std::make_shared<TestObserver>();
    auto observer2 = std::make_shared<TestObserver>();

    subject->attach(observer1);
    subject->attach(observer2);

    subject->createMessage("Test Message");

    EXPECT_EQ(observer1->messages.size(), 1);
    EXPECT_EQ(observer2->messages.size(), 1);
    EXPECT_EQ(observer1->messages[0], "Test Message");
    EXPECT_EQ(observer2->messages[0], "Test Message");
}

TEST(ObserverPattern, DetachObserver) {
    auto subject = std::make_shared<ConcreteSubject>(); // <-- FIXED: Added this line
    auto observer1 = std::make_shared<TestObserver>();
    auto observer2 = std::make_shared<TestObserver>();

    subject->attach(observer1);
    subject->attach(observer2);

    subject->detach(observer1);
    subject->createMessage("Detached Message");

    EXPECT_EQ(observer1->messages.size(), 0);
    EXPECT_EQ(observer2->messages.size(), 1);
    EXPECT_EQ(observer2->messages[0], "Detached Message");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}