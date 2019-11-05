//!
//! @file command_parser.cpp
//!
//! @brief command parser implementation file
//!
//! @copyright Yuval Cohen 2019
//!

#include "command_parser.hpp"
#include <cstring>

namespace toy_robot {
namespace command_parser {

	bool CommandParser::ParseCommand(const char *command_str, Command *command) {
		auto command_str_len = strlen(command_str);
		size_t current_parse_idx{ 0 };

		//  (1) skip any initial spaces (space or tab)
		auto parse_ok = SkipSpaces(command_str, command_str_len, &current_parse_idx);

		// (2) parse the actual command
		if (parse_ok) {
			parse_ok = ParseCommand(
				command_str, command_str_len, &current_parse_idx, command);

			if (parse_ok) {
				//  (3) skip any trailing spaces (space or tab)
				SkipSpaces(command_str, command_str_len, &current_parse_idx);

				parse_ok = (current_parse_idx == command_str_len - 1);
			}
		}

		return parse_ok;
	}

	bool CommandParser::SkipSpaces(const char *command_str,
		size_t cmd_str_len, size_t *current_parse_idx) {
		while (*current_parse_idx < cmd_str_len) {
			if (command_str[*current_parse_idx] == ' ' || command_str[*current_parse_idx] == '\t') {
				*current_parse_idx++;
			}
			else {
				break;
			}
		}
		return true;
	}

	bool CommandParser::ParseCommand(const char *command_str, size_t command_str_len, size_t *current_parse_idx, Command *command) {
		return false;
	}

}  // namespace command_parser
}  // namespace toy_robot
