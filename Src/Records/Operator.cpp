#pragma once

#include "Operator.hpp"

namespace MathEngine
{
	Operator::Operator(
		ChunkType chunkType,
		std::string pattern,
		int order,
		Associativity associativity
	) :
		PatternExpression(chunkType, std::move(pattern)), _order{ order }, _associativity{associativity}
	{

	}

}//namespace MathEngine