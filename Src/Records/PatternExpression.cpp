#pragma once

#include "PatternExpression.hpp"

namespace MathEngine
{
	PatternExpression::PatternExpression(ChunkType chunkType, std::string pattern) : 
		ExpressionItem(chunkType),
		_pattern{std::move(pattern)}
	{

	}

}//namespace MathEngine