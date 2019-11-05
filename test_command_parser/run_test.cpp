//!
//! @file run_test.cpp
//!
//! @brief command parser unit tests file
//!
//! @copyright Yuval Cohen 2019
//!

#include <iostream>
#include "..\command_parser.hpp"

using namespace std;

using toy_robot::command_parser::CommandParser;
using toy_robot::command_parser::Command;
using toy_robot::command_parser::CommandId;
using toy_robot::command_parser::CommandParamsType;
using toy_robot::Face;

void test__PLACE_0_0_NORTH() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "PLACE 0,0,NORTH" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kPlace &&
		command.params_type == CommandParamsType::kTwoNumericOneFace &&
		command.params.two_u32_numeric_one_face_param.x == 0 &&
		command.params.two_u32_numeric_one_face_param.y == 0 &&
		command.params.two_u32_numeric_one_face_param.face == Face::kNorth) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__place_0_0_north() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "place 0,0,north" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kPlace &&
		command.params_type == CommandParamsType::kTwoNumericOneFace &&
		command.params.two_u32_numeric_one_face_param.x == 0 &&
		command.params.two_u32_numeric_one_face_param.y == 0 &&
		command.params.two_u32_numeric_one_face_param.face == Face::kNorth) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__PLACE_1_2_SOUTH() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "PLACE 1,2,SOUTH" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kPlace &&
		command.params_type == CommandParamsType::kTwoNumericOneFace &&
		command.params.two_u32_numeric_one_face_param.x == 1 &&
		command.params.two_u32_numeric_one_face_param.y == 2 &&
		command.params.two_u32_numeric_one_face_param.face == Face::kSouth) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__PLACE_0_0_NORTH_with_spaces() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ " PLACE  0 , 0 , NORTH " };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kPlace &&
		command.params_type == CommandParamsType::kTwoNumericOneFace &&
		command.params.two_u32_numeric_one_face_param.x == 0 &&
		command.params.two_u32_numeric_one_face_param.y == 0 &&
		command.params.two_u32_numeric_one_face_param.face == Face::kNorth) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__MOVE() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "MOVE" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kMove &&
		command.params_type == CommandParamsType::kNone) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__move_with_spaces() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "  move   " };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kMove &&
		command.params_type == CommandParamsType::kNone) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__LEFT() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "LEFT" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kLeft &&
		command.params_type == CommandParamsType::kNone) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__RIGHT() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "RIGHT" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kRight &&
		command.params_type == CommandParamsType::kNone) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

void test__REPORT() {
	CommandParser command_parser;
	Command command;

	auto commad_str{ "REPORT" };
	cout << "Testing Command \"" << commad_str << "\" ";
	if (command_parser.ParseCommand(commad_str, &command) &&
		command.id == CommandId::kReport &&
		command.params_type == CommandParamsType::kNone) {

		cout << "[OK]" << endl;
	}
	else {
		cout << "[FAIL]" << endl;
	}
}

int main() {

	cout << endl << "Command Parser Unit Test" << endl;

	CommandParser command_parser;
	Command command;

	test__PLACE_0_0_NORTH();
	test__place_0_0_north();
	test__PLACE_1_2_SOUTH();
	test__PLACE_0_0_NORTH_with_spaces();
	test__MOVE();
	test__move_with_spaces();
	test__LEFT();
	test__RIGHT();
	test__REPORT();

	return 0;
}
