#include <iostream>
#include "command_parser.hpp"
#include "toy_robot.hpp"

using namespace std;

using toy_robot::command_parser::CommandParser;
using toy_robot::ToyRobot;

int main() {

	CommandParser command_parser;
	ToyRobot tory_robot;

	cout << "Toy Robot" << endl;

	return 0;
}
