// Copyright 2021 GN
#include "Factory.h"
#include <iostream>
int main() {
    std::string name_1 = "Tanya";
    std::string name_2 = "John";
    std::string name_3 = "Julie";
    std::string name_4 = "Mikhail";
    std::string name_5 = "Stan";
    std::string name_6 = "Maksim";
    std::string name_7 = "Mabel";
    std::string name_8 = "Emilia";
    std::string name_9 = "Sophia";
    std::string name_10 = "Elin";
    std::string name_11 = "Francis";
    std::string name_12 = "Lara";
    std::string name_13 = "Willie";
    std::string name_14 = "Ivan";
    std::string name_15 = "Hana";

    Project project_1;
    Project project_2;
    Project project_3;
    Project project_4;
    Project project_5;
    Project project_6;

    project_1.setID("project_1");
    project_2.setID("project_2");
    project_3.setID("project_3");
    project_4.setID("project_4");
    project_5.setID("project_5");
    project_6.setID("project_6");

    project_1.setbudget(100000);
    project_2.setbudget(200000);

    project_1.setNumOfTasks(10);
    project_2.setNumOfTasks(20);

    Programmer pr1(1, name_1, 70000, &project_1);
    Programmer pr2(2, name_2, 70000, &project_2);
    Programmer pr3(3, name_3, 70000, &project_1);
    Programmer pr4(4, name_4, 70000, &project_2);
    Programmer pr5(5, name_5, 70000, &project_1);
    Programmer pr6(6, name_6, 70000, &project_2);
    Programmer pr7(7, name_7, 70000, &project_1);

    SeniorManager sm_1(8, name_8, &project_1);

    ProjectManager pm_1(9, name_9, &project_2);
    ProjectManager pm_2(10, name_10, &project_1);

    Tester ts_1(11, name_11, 50000, &project_1);
    Tester ts_2(12, name_12, 50000, &project_2);
    Tester ts_3(13, name_13, 50000, &project_1);
    Tester ts_4(14, name_14, 50000, &project_2);

    TeamLeader tl_1(15, name_15, 90000, &project_1);

    project_1.setNumOfWorkers(5);
    project_2.setNumOfWorkers(4);

    std::cout << "Tasks per person (Project1):" \
    << project_1.getNumOfTasksPerPerson() << std::endl;
    std::cout << "Tasks per person (Project2):" \
    << project_2.getNumOfTasksPerPerson() << std::endl;

    std::cout << "Worker info:";
    pr1.printInfo();
    std::cout << std::endl;
    std::cout << "Worker info:";
    ts_1.printInfo();
    std::cout << std::endl;
    pr1.setWorkTime(1);
    ts_1.setWorkTime(1);
    tl_1.setWorkTime(1);
    sm_1.setWorkTime(1);
    pm_1.setWorkTime(1);
    tl_1.addSubordinate();
    tl_1.addSubordinate();
    sm_1.addSubordinates();
    sm_1.addSubordinates();
    sm_1.addSubordinates();
    sm_1.addSubordinates();
    pm_1.addSubordinates();
    pm_1.addSubordinates();
    pm_1.addSubordinates();
    pm_1.addSubordinates();
    pr1.calc();
    ts_1.calc();
    tl_1.calc();
    sm_1.calc();
    pm_1.calc();
    std::cout << std::endl << "Work time=1; No bonuses" \
    << std::endl;
    std::cout <<\
    "Programmer,Tester:salary+part of budget(0.01)"\
    << std::endl;
    std::cout <<\
    "Team Leader:salary+part of budget+1000 for each subordinate"\
    << std::endl;
    std::cout <<\
    "Senior Manager,Team Leader:salary+1000 for each subordinate"\
    << std::endl;
    std::cout << "Payement (programmer):"\
    << pr1.getPayment() << std::endl;
    std::cout << "Payement (tester):" \
    << ts_1.getPayment() << std::endl;
    std::cout << "Payement (team leader):" \
    << tl_1.getPayment() << std::endl;
    std::cout << "Payement (senior manager):" \
    << sm_1.getPayment() << std::endl;
    std::cout << "Payement (project manager):" \
    << pm_1.getPayment() << std::endl;
    pr1.addBonus();
    tl_1.addSubordinate();

    pr1.calc();
    tl_1.calc();
    std::cout << std::endl <<\
    "Worktime=1;Programmer gets bonus;Team Leader gets additional subordinate"\
    << std::endl;
    std::cout << "Payement (programmer):" \
    << pr1.getPayment() << std::endl;
    std::cout << "Payement (tester):" \
    << ts_1.getPayment() << std::endl;
    std::cout << "Payement (team leader):" \
    << tl_1.getPayment() << std::endl;
    std::cout << "Payement (senior manager):" \
    << sm_1.getPayment() << std::endl;
    std::cout << "Payement (project manager):" \
    << pm_1.getPayment() << std::endl;

    project_1.setbudget(500000);
    pr1.calc();
    ts_1.calc();
    tl_1.calc();
    sm_1.calc();
    pm_1.calc();
    std::cout << std::endl <<\
    "Worktime=1;Project budget increased from 100000to500000"\
    << std::endl;
    std::cout << "Payement (programmer):" << pr1.getPayment() \
    << std::endl;
    std::cout << "Payement (tester):" << ts_1.getPayment() \
    << std::endl;
    std::cout << "Payement (team leader):" << tl_1.getPayment() \
    << std::endl;
    std::cout << "Payement (senior manager):" << sm_1.getPayment() \
    << std::endl;
    std::cout << "Payement (project manager):" << pm_1.getPayment() \
    << std::endl;

    pr1.setWorkTime(2);
    ts_1.setWorkTime(2);
    tl_1.setWorkTime(2);
    sm_1.setWorkTime(2);
    pm_1.setWorkTime(2);
    pr1.calc();
    ts_1.calc();
    tl_1.calc();
    sm_1.calc();
    pm_1.calc();
    std::cout << std::endl << "---Work time=2---" << std::endl;
    std::cout << "Payement (programmer):" << pr1.getPayment() \
    << std::endl;
    std::cout << "Payement (tester):" << ts_1.getPayment() \
    << std::endl;
    std::cout << "Payement (team leader):" << tl_1.getPayment() \
    << std::endl;
    std::cout << "Payement (senior manager):" << sm_1.getPayment() \
    << std::endl;
    std::cout << "Payement (project manager):" << pm_1.getPayment() \
    << std::endl;
}
