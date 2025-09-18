#include "ObserverPattern.h"
#include <iostream>
#include <algorithm>

// ConcreteSubject implementations
void ConcreteSubject::attach(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void ConcreteSubject::detach(std::shared_ptr<Observer> observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ConcreteSubject::notify(const std::string& message) {
    for (const auto& observer : observers) {
        observer->update(message);
    }
}

void ConcreteSubject::createMessage(const std::string& message) {
    std::cout << "Subject: " << message << std::endl;
    notify(message);
}

// ConcreteObserver implementations
ConcreteObserver::ConcreteObserver(const std::string& name) : name(name) {}

void ConcreteObserver::update(const std::string& message) {
    std::cout << "Observer " << name << " received message: " << message << std::endl;
}

// Main function

/**/
int main() {
    auto subject = std::make_shared<ConcreteSubject>();

    auto observer1 = std::make_shared<ConcreteObserver>("A");
    auto observer2 = std::make_shared<ConcreteObserver>("B");

    subject->attach(observer1);
    subject->attach(observer2);

    subject->createMessage("Hello Observers!");

    subject->detach(observer1);

    subject->createMessage("Observer A has been detached.");

    return 0;
}
