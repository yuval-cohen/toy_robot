//!
//! @file toy_robot_base.hpp
//!
//! @brief toy robot interface file
//!
//! @copyright Yuval Cohen 2019
//!

#pragma once
#include  <cstdint>
#include "face.hpp"

namespace toy_robot {

	/**
	* @class ToyRobotBase
	* Command toy robot abstract base class
	*/
	class ToyRobotBase {
	public:
		virtual bool Place(uint32_t x, uint32_t y, Face face) = 0;
		virtual bool Move() = 0;
		virtual bool Left() = 0;
		virtual bool Right() = 0;
		virtual bool Report(uint32_t *x, uint32_t *y, Face *face) = 0;
	};

}  // namespace toy_robot
