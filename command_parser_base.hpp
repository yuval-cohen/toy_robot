//!
//! @file command_parser_base.hpp
//!
//! @brief command parser interface file
//!
//! @copyright Yuval Cohen 2019
//!

#pragma once

#include "command_defs.hpp"

namespace toy_robot {
namespace command_parser {

	/**
	* @class CommandParserBase
	* Command Parser abstract base class
	*/
	class CommandParserBase {
	public:
		virtual bool ParseCommand(const char *command_str, Command *command) = 0;
	};

}  // namespace command_parser
}  // namespace toy_robot