#pragma once

#include "Function.hpp"

namespace MathEngine
{
	Function::Function(
		ChunkType chunkType,
		int order,
		Associativity associativity,
		int parametrsCount
	) :
		PatternExpression(chunkType), _order{ order }, _associativity{ associativity }, _parametrsCount{parametrsCount}
	{

	}

}//namespace MathEngine