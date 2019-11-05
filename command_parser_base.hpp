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

	/**
	* @class CommandParserBase
	* Command Parser abstract base class
	*/
	class CommandParserBase {
		virtual bool ParseCommand(const char *command_str, Command *command) = 0;
	};

}  // namespace toy_robot