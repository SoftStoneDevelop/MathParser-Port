#pragma once

#include "Operator.hpp"

namespace MathEngine
{
	Operator::Operator(
		ChunkType chunkType,
		int order,
		Associativity associativity
	) :
		PatternExpression(chunkType), _order{ order }, _associativity{associativity}
	{

	}

}//namespace MathEngine