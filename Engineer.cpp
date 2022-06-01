#include "Factory.h"
#include "Engineer.h"
#include <iostream>
Project* Engineer::getProject() {
    return project;
}
Project& Engineer::getProject_() {
    return *project;
}
int Engineer::calcBudgetPart(float part_, int budget_) {
    return static_cast<int>(part_ * budget_);
}
void Engineer::calc() {
    Project* pr__ = this->getProject();
    setPayment(calcBase(getSalary(), getWorkTime())
        + calcBudgetPart(0.01, getProject()->getBudget()) + calcProAdditions());
}
int Programmer::calcProAdditions() {
    if (bonus == 1) { return 10000; }
    return 0;
}
int Tester::calcProAdditions() {
    return getErrorsNumber() * 100;
}
int Tester::getErrorsNumber() {
    return errors;
}
int TeamLeader::getSubordinates() {
    return subordinates;
}
void TeamLeader::calc() {
    Project* pr__ = this->getProject();
    setPayment(calcBase(getSalary(), getWorkTime()) +
        calcBudgetPart(0.02, getProject()->getBudget()) + calcHeads());
}
int TeamLeader::calcHeads() {
    return getSubordinates() * 1000;
}
void Engineer::printInfo() {
    Project* pr__ = this->getProject();
    std::cout << getName() + " " + std::to_string(getID())
        + " " + getProject()->getID();
}
