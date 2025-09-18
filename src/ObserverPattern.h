#pragma once
#include <string>
#include <memory>
#include <vector>

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify(const std::string& message) = 0;
};

// Concrete Subject
class ConcreteSubject : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
public:
    void attach(std::shared_ptr<Observer> observer) override;
    void detach(std::shared_ptr<Observer> observer) override;
    void notify(const std::string& message) override;
    void createMessage(const std::string& message);
};

// Concrete Observer
class ConcreteObserver : public Observer {
private:
    std::string name;
public:
    ConcreteObserver(const std::string& name);
    void update(const std::string& message) override;
};