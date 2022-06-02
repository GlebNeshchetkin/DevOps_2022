// Copyright 2021 GN
#ifndef PERSONAL_H_
#define PERSONAL_H_
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
    int salary;

 public:
    explicit Personal(int id_, std::string name_,
        int salary_) : Employee(id_, name_) {
        salary = salary_;
    }
    int getSalary();
    virtual int calcBase(int salary_, int worktime_);
    virtual int calcBonus() { return 0; }
    virtual void printInfo();
};

#endif  // PERSONAL_H_
