#pragma once

#include "ChunkNumber.hpp"

namespace MathEngine
{
	ChunkNumber::ChunkNumber(
		float number,
		std::shared_ptr<Operand> operand
	) : ChunkExpression(ChunkType::Number, std::move(operand)), _number{ number }
	{

	}

}//namespace MathEngine