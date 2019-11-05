//!
//! @file face.hpp
//!
//! @brief Face definitions
//!
//! @copyright Yuval Cohen 2019
//!

#pragma once
#include  <cstdint>

namespace toy_robot {

	/*
	* @brief Face type
	*/
	enum class Face : uint8_t {
		kNorth,
		kSouth,
		kEast,
		kWest
	};

}  // namespace toy_robot
