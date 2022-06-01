// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"
#include "Employee.cpp"
#include "Engineer.cpp"
#include "Factory.cpp"
#include "Manager.cpp"
#include "Personal.cpp"
#include "Employee.h"
#include "Engineer.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(TestProgrammer_1, Test_1) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	Programmer pr(10, name_, 70000, &project_1);
	EXPECT_EQ(1, pr.getPos());
}

TEST(TestProgrammer_2, Test_3) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	Programmer pr(10, name_, 100, &project_1);
	pr.setWorkTime(2);
	pr.addBonus();
	pr.calc();
	EXPECT_EQ(10400, pr.getPayment());
}

TEST(TestProgrammer_3, Test_4) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	Programmer pr(10, name_, 100, &project_1);
	pr.setWorkTime(2);
	pr.calc();
	EXPECT_EQ(400, pr.getPayment());
}

TEST(TestTester_1, Test_5) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	Tester pr(10, name_, 100, &project_1);
	pr.setWorkTime(2);
	pr.calc();
	EXPECT_EQ(400, pr.getPayment());
}

TEST(TestTester_2, Test_6) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	Tester pr(10, name_, 100, &project_1);
	pr.setWorkTime(2);
	pr.newError();
	pr.calc();
	EXPECT_EQ(500, pr.getPayment());
}

TEST(TestTeamLeader_1, Test_7) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	TeamLeader pr(10, name_, 200, &project_1);
	pr.setWorkTime(2);
	pr.calc();
	EXPECT_EQ(800, pr.getPayment());
}

TEST(TestTeamLeader_2, Test_8) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(20000);
	TeamLeader pr(10, name_, 200, &project_1);
	pr.setWorkTime(2);
	pr.addSubordinate();
	pr.calc();
	EXPECT_EQ(1800, pr.getPayment());
}

TEST(TestProjectManager_1, Test_9) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(2000000);
	ProjectManager pr(10, name_, &project_1);
	pr.setWorkTime(2);
	pr.addSubordinates();
	pr.addSubordinates();
	pr.calc();
	EXPECT_EQ(184000, pr.getPayment());
}

TEST(TestSeniorManager_1, Test_10) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(2000000);
	SeniorManager pr(10, name_, &project_1);
	pr.setWorkTime(2);
	pr.addSubordinates();
	pr.addSubordinates();
	pr.calc();
	EXPECT_EQ(164000, pr.getPayment());
}

TEST(TestSeniorManager_2, Test_11) {
	std::string name_ = "Ivanov Ivan";
	Project project_1;
	project_1.setID("project_1");
	project_1.setbudget(2000000);
	SeniorManager pr(10, name_, &project_1);
	pr.setWorkTime(2);
	pr.addSubordinates();
	pr.addSubordinates();
	int sub = pr.getSubordinates();
	EXPECT_EQ(2, sub);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
