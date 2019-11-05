//!
//! @file command_parser.cpp
//!
//! @brief command parser implementation file
//!
//! @copyright Yuval Cohen 2019
//!

#include "command_str.hpp"
#include "command_parser.hpp"
#include <cstring>
#include <cstdlib>

namespace toy_robot {
namespace command_parser {

	bool CommandParser::ParseCommand(const char *command_str, Command *command) {
		auto command_str_len = strlen(command_str);
		size_t current_parse_idx{ 0 };

		//  (1) skip any initial spaces (space or tab)
		auto parse_ok = SkipSpaces(command_str, command_str_len, &current_parse_idx);

		// (2) parse the actual command
		if (parse_ok) {
			parse_ok = ParseCommandStrWithParams(
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

	bool CommandParser::ParseCommandStrWithParams(const char *command_str, size_t command_str_len, size_t *current_parse_idx, Command *command) {
		if (*current_parse_idx < command_str_len) {
			auto place_command_str_len = strlen(strings::kPlaceCommandStr);
			auto move_command_str_len = strlen(strings::kMoveCommandStr);
			auto left_command_str_len = strlen(strings::kLeftCommandStr);
			auto right_command_str_len = strlen(strings::kRightCommandStr);
			auto report_command_str_len = strlen(strings::kReportCommandStr);

			if (strncmp(command_str + *current_parse_idx, strings::kPlaceCommandStr,
				place_command_str_len) == 0) {
				*current_parse_idx += place_command_str_len;

				uint32_t x;
				if (ParseU32Numeric(command_str, current_parse_idx, &x)) {
					uint32_t y;
					if (ParseU32Numeric(command_str, current_parse_idx, &y)) {
						Face face;
						if (ParseFaceString(command_str, command_str_len, current_parse_idx, &face)) {
							command->id = CommandId::kPlace;
							command->params_type = CommandParamsType::kTwoNumericOneFace;
							command->params.two_u32_numeric_one_face_param.x = x;
							command->params.two_u32_numeric_one_face_param.y = y;
							command->params.two_u32_numeric_one_face_param.face = face;

							return true;
						}
					}
				}
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kMoveCommandStr,
				move_command_str_len) == 0) {
				*current_parse_idx += move_command_str_len;

				command->id = CommandId::kMove;
				command->params_type = CommandParamsType::kNone;

				return true;
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kLeftCommandStr,
				left_command_str_len) == 0) {
				*current_parse_idx += left_command_str_len;

				command->id = CommandId::kLeft;
				command->params_type = CommandParamsType::kNone;

				return true;
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kRightCommandStr,
				right_command_str_len) == 0) {
				*current_parse_idx += right_command_str_len;

				command->id = CommandId::kRight;
				command->params_type = CommandParamsType::kNone;

				return true;
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kReportCommandStr,
				report_command_str_len) == 0) {
				*current_parse_idx += report_command_str_len;

				command->id = CommandId::kReport;
				command->params_type = CommandParamsType::kNone;

				return true;
			}
		}

		return false;
	}

	bool CommandParser::ParseU32Numeric(const char *command_str, size_t *current_parse_idx, uint32_t *n) {
		auto start_str = command_str + (*current_parse_idx);
		if (start_str) {
			auto end_str = strstr(start_str, strings::kParamsSeparator);
			if (end_str) {
				uint32_t x;
				if (StrToU32(start_str, &x)) {
					*n = x;
					*current_parse_idx += (end_str)-(command_str + *current_parse_idx);
					return true;
				}
			}
		}

		return false;
	}

	bool CommandParser::ParseFaceString(const char *command_str, size_t command_str_len, size_t *current_parse_idx, Face *face) {
		if (*current_parse_idx < command_str_len) {
			auto face_north_str_len = strlen(strings::kFaceNorthStr);
			auto face_south_str_len = strlen(strings::kFaceSouthStr);
			auto face_east_str_len = strlen(strings::kFaceEastStr);
			auto face_west_str_len = strlen(strings::kFaceWestStr);

			if (strncmp(command_str + *current_parse_idx, strings::kFaceNorthStr, face_north_str_len) == 0) {
				*current_parse_idx += face_north_str_len;
				*face = Face::kNorth;
				return true;
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kFaceSouthStr, face_south_str_len) == 0) {
				*current_parse_idx += face_south_str_len;
				*face = Face::kSouth;
				return true;
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kFaceEastStr, face_east_str_len) == 0) {
				*current_parse_idx += face_east_str_len;
				*face = Face::kEast;
				return true;
			}
			else if (strncmp(command_str + *current_parse_idx, strings::kFaceWestStr, face_west_str_len) == 0) {
				*current_parse_idx += face_west_str_len;
				*face = Face::kWest;
				return true;
			}
		}

		return false;
	}

	bool CommandParser::StrToU32(const char *start, uint32_t *u32) {
		if (start) {
			char *str_end;
			constexpr int kBaseDecimal{ 10 };
			*u32 = strtoul(start, &str_end, kBaseDecimal);
			if (*u32 != 0 || start != str_end) {
				return true;
			}
		}

		return false;
	}

}  // namespace command_parser
}  // namespace toy_robot
