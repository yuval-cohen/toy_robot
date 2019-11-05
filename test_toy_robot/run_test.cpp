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

/*
 * PLACE 0,0,NORTH
 * MOVE
 * REPORT
 * Output: 0,1,NORTH
*/
void test__1() {
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

/*
 * PLACE 0,0,NORTH
 * LEFT
 * REPORT
 * Output: 0,0,WEST
*/
void test__2() {
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
/*
 * PLACE 1, 2, EAST
 * MOVE
 * MOVE
 * LEFT
 * MOVE
 * REPORT
 * Output : 3, 3, NORTH
*/
void test__3() {
	ToyRobot<5, 5> toy_robot;

	cout << "PLACE 1, 2, EAST" << endl;
	toy_robot.Place(1, 2, Face::kEast);
	cout << "MOVE" << endl;
	toy_robot.Move();
	cout << "MOVE" << endl;
	toy_robot.Move();
	cout << "LEFT" << endl;
	toy_robot.Left();
	cout << "MOVE" << endl;
	toy_robot.Move();
	cout << "REPORT" << endl;
	uint32_t x;
	uint32_t y;
	Face face;
	if (toy_robot.Report(&x, &y, &face) && (x == 3) && (y == 3) && (face == Face::kNorth)) {
		cout << "Output: " << x << "," << y << ",NORTH" << endl;
		cout << "Test #3 [OK]\n\n";
	}
	else {
		cout << "Test #3 [FAIL]\n\n";
	}
}

int main() {

	cout << endl << "Toy Robot Unit Tests" << endl;

	test__1();
	test__2();
	test__3();

	return 0;
}
