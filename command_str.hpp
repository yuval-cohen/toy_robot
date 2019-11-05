//!
//! @file command_str.hpp
//!
//! @brief command strings header
//!
//! @copyright Yuval Cohen 2019
//!

#pragma once

#include "command_defs.hpp"

namespace toy_robot {
namespace command_parser {
namespace strings {

	static constexpr const char *kPlaceCommandStr = "PLACE";
	static constexpr const char *kMoveCommandStr = "MOVE";
	static constexpr const char *kLeftCommandStr = "LEFT";
	static constexpr const char *kRightCommandStr = "RIGHT";
	static constexpr const char *kReportCommandStr = "REPORT";

	static constexpr const char *kFaceNorthStr = "NORTH";
	static constexpr const char *kFaceSouthStr = "SOUTH";
	static constexpr const char *kFaceEastStr = "EAST";
	static constexpr const char *kFaceWestStr = "WEST";

	static constexpr const char *kParamsSeparator = ",";

}  // namespace strings
}  // namespace command_parser
}  // namespace toy_robot
