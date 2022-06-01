// Copyright 2021 GN
#ifndef ENGINEER_H_
#define ENGINEER_H_
#include <string>
#include <vector>
#include "Personal.h"

class Project {
 private:
    std::string id;
    int budget;
    int num_of_tasks;
    int num_of_workers;

 public:
    void setID(std::string id_) {
        id = id_;
    }
    void setbudget(int budget_) {
        budget = budget_;
    }
    void setNumOfTasks(int tasks_) {
        num_of_tasks = tasks_;
    }
    void setNumOfWorkers(int workers_ = 0) {
        num_of_workers = workers_;
    }
    void addWorker() {
        num_of_workers++;
    }
    std::string getID() {
        return id;
    }
    int getBudget() {
        return budget;
    }
    int getNumOfTasks() {
        return num_of_tasks;
    }
    int getNumOfWorkers() {
        return num_of_workers;
    }
    int getNumOfTasksPerPerson() {
        if (num_of_workers != 0)
            return num_of_tasks / num_of_workers;
        else
            return 0;
    }
};

class Engineer : public ProjectBudget, public Personal {
 private:
    Project* project;

 public:
    explicit Engineer(int id_, std::string name_,
        int salary_, Project* project_)
        : Personal(id_, name_, salary_) {
        project = project_;
    }
    virtual int calcBudgetPart(float part_, int budget_);
    virtual void calc();
    virtual void printInfo();
    int getBudget_() {
        return project->getBudget();
    }
    Project* getProject();
    Project& getProject_();
};

class Programmer : public Engineer {
 private:
    bool bonus = 0;
 public:
    explicit Programmer(int id_, std::string name_,
        int salary_, Project* project_)
        : Engineer(id_, name_, salary_, project_) {
        spec = PROGRAMMER;
    }
    void addBonus() { bonus = 1; }
    virtual int calcProAdditions();
};

class Tester : public Engineer {
 private:
    int errors = 0;

 public:
    explicit Tester(int id_, std::string name_,
        int salary_, Project* project_)
        : Engineer(id_, name_, salary_, project_) {
        spec = TESTER;
    }
    void newError() {
        errors++;
    }
    int getErrorsNumber();
    virtual int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
 private:
    int subordinates = 0;

 public:
    explicit TeamLeader(int id_, std::string name_,
        int salary_, Project* project_)
        : Programmer(id_, name_, salary_, project_) {
        spec = TEAMLEADER;
    }
    int getSubordinates();
    virtual int calcHeads();
    virtual void calc();
    virtual int calcProAdditions() { return 0; }
    void addSubordinate() {
        subordinates++;
    }
};

#endif // ENGINEER_H_
