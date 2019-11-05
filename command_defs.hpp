//!
//! @file command_defs.hpp
//!
//! @brief command parser command definitions
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

namespace command_parser {

	/*
	* @brief Command identifiers known to command parser
	*/
	enum class CommandId : uint8_t {
		kNone,
		kPlace,
		kMove,
		kLeft,
		kRight,
		kReport
	};

	/*
	* @brief Command Parameters Type
	*/
	enum class CommandParamsType : uint8_t {
		kNone,  // no params
		kTwoNumericOneFace
	};

	/*
	* @brief structure for no Parameters
	*/
	struct EmptyParams {};

	/*
	* @brief structure for two numberic and one face parameter
	*/
	struct TwoU32OneFaceParams {
		uint32_t x;
		uint32_t y;
		Face face;
	};


	/*
	* @brief union of all different command parameters
	*/
	union CommandParams {
		EmptyParams no_param;
		TwoU32OneFaceParams two_u32_numeric_one_face_param;
	};


	/*
	* @brief command class
	*/
	struct Command {
		/*
		* @brief c'tor w/ command id defaults to none
		*/
		explicit Command(CommandId id_ = CommandId::kNone) :
			id{ id_ }, params_type{ CommandParamsType::kNone }, params{}
		{}

		/*
		* @brief c'tor for two numeric command and one face
		*/
		Command(CommandId id_, uint32_t x_, uint32_t y_, Face face_) :
			id{ id_ }, params_type{ CommandParamsType::kTwoNumericOneFace}
		{
			params.two_u32_numeric_one_face_param.x = x_;
			params.two_u32_numeric_one_face_param.y = y_;
			params.two_u32_numeric_one_face_param.face = face_;
		}

		CommandId id;
		CommandParamsType params_type;
		CommandParams params;
	};

}  // namespace command_parser
}  // namespace toy_robot
