//!
//! @file command_parser.hpp
//!
//! @brief command parser header file
//!
//! @copyright Yuval Cohen 2019
//!

#pragma once

#include "command_defs.hpp"
#include "command_parser_base.hpp"


namespace toy_robot {
namespace command_parser {

	/**
	* @class CommandParser
	* Command Parser class
	*/
	class CommandParser : public CommandParserBase {
	public:
		/**
		* Constructor
		*/
		CommandParser() = default;

		/**
		* Destructor
		*/
		~CommandParser() = default;

		/**
		* @brief Parse command string
		* @param input command string (null terminated)
		* @param output command data
		* @return true - command successfully parsed; false - otherwise
		*/
		bool ParseCommand(const char *command_str, Command *command) override;

	private:
		bool SkipSpaces(const char *command_str, size_t cmd_str_len, size_t *current_parse_idx);
		bool ParseCommandStrWithParams(const char *command_str, size_t command_str_len, size_t *current_parse_idx, Command *command);
		bool ParseU32Numeric(const char *command_str, size_t *current_parse_idx, uint32_t *n);
		bool ParseParamSeparator(const char *command_str, size_t command_str_len, size_t *current_parse_idx);
		bool ParseFaceString(const char *command_str, size_t command_str_len, size_t *current_parse_idx, Face *face);

		bool StrToU32(const char *start, uint32_t *u32);
	};

}  // namespace command_parser
}  // namespace toy_robot
