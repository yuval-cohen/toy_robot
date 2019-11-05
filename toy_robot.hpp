//!
//! @file toy_robot_base.hpp
//!
//! @brief toy robot header file
//!
//! @copyright Yuval Cohen 2019
//!

#pragma once

#include "toy_robot_base.hpp"

namespace toy_robot {

	/**
	* @class ToyRobot
	* Toy Robot class
	*/
	class ToyRobot : public ToyRobotBase {
	public:
		/**
		* Constructor
		*/
		ToyRobot() : placed_{false}, x_{ 0 }, y_{ 0 }, face_{ Face::kNorth } {
		}

		/**
		* Destructor
		*/
		~ToyRobot() = default;

		bool Place(uint32_t x, uint32_t y, Face face) override {
			return false;
		}

		bool Move() override {
			return false;
		}

		bool Left() override {
			return false;
		}

		bool Right() override {
			return false;
		}

		bool Report(uint32_t *x, uint32_t *y, Face *face) override {
			return false;
		}

	private:
		bool placed_;
		uint32_t x_;
		uint32_t y_;
		Face face_;
	};

}  // namespace toy_robot
