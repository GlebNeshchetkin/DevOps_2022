#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum position {
    TESTER,
    PROGRAMMER,
    TEAMLEADER,
    PROJECTMANAGER,
    SENIORMANAGER,
};

class Employee {
private:
    int id;
    std::string name;
    int worktime = 0;
    int payment = 0;
    int total_stage = 0;

protected:
    position spec;

public:
    explicit Employee(int id_, std::string name_) {
        id = id_;
        name = name_;
    }
    int getWorkTime();
    std::string getName();
    void setWorkTime(int worktime_);
    void incTotalStage();
    void setPayment(int payment_);
    int getTotalStage();
    int getID();
    int getPayment();
    position getPos();
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};

#endif
