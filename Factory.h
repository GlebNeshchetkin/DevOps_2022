// Copyright 2021 GN
#ifndef FACTORY_H_
#define FACTORY_H_

#include <vector>
#include "Manager.h"
#include "Engineer.h"
#include "Personal.h"

class Factory {
 private:
    std::vector<Employee*>factory_employees;

 public:
    void createStaff();
};

#endif  // FACTORY_H_
