//!
//! @file main.cpp
//!
//! @brief toy robot demo application file
//!
//! @copyright Yuval Cohen 2019
//!
#include <iostream>
#include <string>
#include "command_parser.hpp"
#include "toy_robot.hpp"

using namespace std;

using toy_robot::command_parser::CommandParser;
using toy_robot::command_parser::Command;
using toy_robot::command_parser::CommandId;
using toy_robot::ToyRobot;
using toy_robot::Face;

const char *GetFaceString(Face face) {
	switch (face) {
	case Face::kNorth:
		return "NORTH";

	case Face::kSouth:
		return "SOUTH";

	case Face::kEast:
		return "EAST";

	case Face::kWest:
		return "WEST";

	default:
		return "ERROR";
	}
}

int main() {

	CommandParser command_parser;
	Command command;
	ToyRobot<5,5> toy_robot;

	std::cout << "Toy Robot Demo" << endl;
	std::cout << "==============" << endl;
	std::cout << "Commands:" << endl;
	std::cout << "PLACE x,y,f" << endl;
	std::cout << "MOVE" << endl;
	std::cout << "LEFT" << endl;
	std::cout << "RIGHT" << endl;
	std::cout << "q or quit to exit" << endl;

	string input_line;

	while (input_line != "quit" && input_line != "q") {
		getline(cin, input_line);
		if (command_parser.ParseCommand(input_line.c_str(), &command)) {
			switch (command.id) {
			case CommandId::kPlace:
			{
				auto &x = command.params.two_u32_numeric_one_face_param.x;
				auto &y = command.params.two_u32_numeric_one_face_param.y;
				auto &face = command.params.two_u32_numeric_one_face_param.face;
				toy_robot.Place(x, y, face);
			}
			break;

			case CommandId::kMove:
				toy_robot.Move();
				break;

			case CommandId::kLeft:
				toy_robot.Left();
				break;

			case CommandId::kRight:
				toy_robot.Right();
				break;

			case CommandId::kReport:
			{
				uint32_t x;
				uint32_t y;
				Face face;
				if (toy_robot.Report(&x, &y, &face)) {
					std::cout << ">> Output: " << x << "," << y << "," << GetFaceString(face) << endl;
				}
				else {
					std::cout << ">> ROBOT NOT PLACED" << endl;
				}
			}
			break;
			}
		}
	}

	return 0;
}
