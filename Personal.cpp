// Copyright 2021 GN
#include "Employee.h"
#include "Personal.h"
#include <iostream>
int Personal::getSalary() {
    return salary;
}
int Personal::calcBase(int salary_, int worktime_) {
    return salary_ * worktime_;
}
void Personal::printInfo() {
    std::cout << getName() + " " + std::to_string(getID());
}
