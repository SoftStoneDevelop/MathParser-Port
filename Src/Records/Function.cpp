#pragma once

#include "Function.hpp"

namespace MathEngine
{
	Function::Function(
		ChunkType chunkType,
		std::string pattern,
		int order,
		Associativity associativity,
		int parametrsCount
	) :
		PatternExpression(chunkType, std::move(pattern)), _order{ order }, _associativity{ associativity }, _parametrsCount{parametrsCount}
	{

	}

}//namespace MathEngine