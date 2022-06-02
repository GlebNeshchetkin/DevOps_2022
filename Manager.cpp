// Copyright 2021 GN
#include "Manager.h"
#include <iostream>
int ProjectManager::getSubordinates() {
    return subordinates;
}
int SeniorManager::getSubordinates() {
    return subordinates;
}
int ProjectManager::calcHeads() {
    return getSubordinates() * 1000;
}
int SeniorManager::calcHeads() {
    return getSubordinates() * 1000;
}
void ProjectManager::calc() {
    setPayment(this->getWorkTime() * (90000 + calcHeads()));
}
void SeniorManager::calc() {
    setPayment(this->getWorkTime() * (80000 + calcHeads()\
    + calcProAdditions()));
}
void ProjectManager::printInfo() {
    std::cout << getName() + " " + std::to_string(getID());
}
int ProjectManager::calcBudgetPart(float part_, int budget_) {
    return part_ * budget_;
}
/*int ProjectManager::calcProAdditions() {
    return 1000 * getSubbordinates();
}*/
int SeniorManager::calcProAdditions() {
    return 1000 * projects.size();
}
