#pragma once

#include "ChunkNumber.hpp"

namespace MathEngine
{
	ChunkNumber::ChunkNumber(
		ChunkType chunkType,
		float number,
		Operand& operand
	) : ChunkExpression(chunkType), _number{number}, _operand{ operand }
	{

	}

}//namespace MathEngine