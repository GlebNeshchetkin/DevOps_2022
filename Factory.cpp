// Copyright 2021 GN
#include "Factory.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

void Factory::createStaff() {
    srand(time(NULL));
    std::vector<Employee*> employees;
    std::ifstream in("employees-1.txt");
    std::vector<Project*> projects;
    std::string row;
    while (std::getline(in, row)) {
        std::string id, name, pos, salary, project;
        std::istringstream f(row);

        std::getline(f, id, ',');
        std::getline(f, name, ',');
        std::getline(f, pos, ',');
        std::getline(f, salary, ',');



        if (pos == "Programmer") {
            std::getline(f, project, ',');
            Project pr;
            pr.setID(project);
            pr.setbudget(100000);
            projects.push_back(&pr);
            Programmer* tmp = new Programmer(std::stoi(id),
                name, std::stoi(salary), &pr);
            employees.push_back(tmp);
        }

        if (pos == "Tester") {
            std::getline(f, project, ',');
            Project pr;
            pr.setID(project);
            pr.setbudget(100000);
            projects.push_back(&pr);
            Tester* tmp = new Tester(std::stoi(id),
                name, std::stoi(salary), &pr);
            employees.push_back(tmp);
        }

        if (pos == "TeamLeader") {
            std::getline(f, project, ',');
            Project pr;
            pr.setID(project);
            pr.setbudget(100000);
            projects.push_back(&pr);
            TeamLeader* tmp = new TeamLeader(std::stoi(id),
                name, std::stoi(salary), &pr);
            employees.push_back(tmp);
        }

        if (pos == "ProjectManager") {
            std::getline(f, project, ',');
            Project pr;
            pr.setID(project);
            pr.setbudget(100000);
            projects.push_back(&pr);
            ProjectManager* tmp = new ProjectManager(std::stoi(id), name, &pr);
            employees.push_back(tmp);
        }

        if (pos == "SeniorManager") {
            std::getline(f, project, ',');
            Project pr;
            pr.setID(project);
            pr.setbudget(100000);
            projects.push_back(&pr);
            SeniorManager* tmp = new SeniorManager(std::stoi(id), name, &pr);
            employees.push_back(tmp);
        }

    }
    in.close();
    factory_employees = employees;
}
