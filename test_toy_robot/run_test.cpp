//!
//! @file run_test.cpp
//!
//! @brief toy robot unit tests file
//!
//! @copyright Yuval Cohen 2019
//!

#include <iostream>
#include "..\toy_robot.hpp"

using namespace std;

using toy_robot::ToyRobot;
using toy_robot::Face;

void test__PLACE_0_0_NORTH__MOVE__REPORT() {
	ToyRobot<5,5> toy_robot;

	cout << "PLACE 0,0,NORTH" << endl;
	toy_robot.Place(0, 0, Face::kNorth);
	cout << "MOVE" << endl;
	toy_robot.Move();
	cout << "REPORT" << endl;
	uint32_t x;
	uint32_t y;
	Face face;
	if (toy_robot.Report(&x, &y, &face) && (x == 0) && (y == 1) && (face == Face::kNorth)) {
		cout << "Output: " << x << "," << y << ",NORTH" << endl;
		cout << "Test #1 [OK]\n\n";
	}
	else {
		cout << "Test #1 [FAIL]\n\n";
	}
}

void test__PLACE_0_0_NORTH__LEFT__REPORT() {
	ToyRobot<5, 5> toy_robot;

	cout << "PLACE 0,0,NORTH" << endl;
	toy_robot.Place(0, 0, Face::kNorth);
	cout << "LEFT" << endl;
	toy_robot.Left();
	cout << "REPORT" << endl;
	uint32_t x;
	uint32_t y;
	Face face;
	if (toy_robot.Report(&x, &y, &face) && (x == 0) && (y == 0) && (face == Face::kWest)) {
		cout << "Output: " << x << "," << y << ",WEST" << endl;
		cout << "Test #2 [OK]\n\n";
	}
	else {
		cout << "Test #2 [FAIL]\n\n";
	}
}

int main() {

	cout << endl << "Toy Robot Unit Tests" << endl;

	test__PLACE_0_0_NORTH__MOVE__REPORT();
	test__PLACE_0_0_NORTH__LEFT__REPORT();

	return 0;
}
