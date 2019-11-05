#include <iostream>
#include "..\command_parser.hpp"

using namespace std;

using toy_robot::command_parser::CommandParser;
using toy_robot::command_parser::Command;
using toy_robot::command_parser::CommandId;
using toy_robot::command_parser::CommandParamsType;
using toy_robot::command_parser::Face;

void test__place_0_0_north() {
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

void test__place_0_0_north_with_spaces() {
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

void test__move() {
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

void test__left() {
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

void test__right() {
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

void test__report() {
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

	test__place_0_0_north();
	test__place_0_0_north_with_spaces();
	test__move();
	test__left();
	test__right();
	test__report();

	return 0;
}
