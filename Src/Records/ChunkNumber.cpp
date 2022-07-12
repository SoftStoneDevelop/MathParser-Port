#pragma once

#include "ChunkNumber.hpp"

namespace MathEngine
{
	ChunkNumber::ChunkNumber(
		float number,
		Operand* operand
	) : ChunkExpression(operand), _number{number}
	{

	}

}//namespace MathEngine