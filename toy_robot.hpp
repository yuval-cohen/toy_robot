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
	* @template parameter X grid size (>= 1)
	* @template parameter Y grid size (>= 1)
	*/
	template <uint32_t X, uint32_t Y>
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

		/**
		* Place
		* @brief place toy robot on grid
		* @param x coordinate
		* @param y coordinate
		* @param face north/south/east/west
		* @return true - place successful, false - otherwise
		*/
		bool Place(uint32_t x, uint32_t y, Face face) override {
			if (x < X && y < Y) {
				x_ = x;
				y_ = y;
				face_ = face;

				placed_ = true;
				return true;
			}
			return false;
		}

		/**
		* Place
		* @brief move toy robot one unit forward in the direction it is currently facing
		* @return false - robot not placed, true - otherwise
		*/
		bool Move() override {
			if (!placed_) {
				return false;
			}

			switch (face_) {
			case Face::kNorth:
				if (y_ + 1 < Y) {
					y_++;
				}
				break;

			case Face::kSouth:
				if (y_ > 0) {
					y_--;
				}
				break;

			case Face::kEast:
				if (x_ + 1 < X) {
					x_++;
				}
				break;

			case Face::kWest:
				if (x_ > 0) {
					x_--;
				}
				break;

			default:
				placed_ = false;
				return false;

			}
			return true;
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
