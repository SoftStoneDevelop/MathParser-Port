#pragma once

#include "ChunkExpression.hpp"
#include <istream>

namespace MathEngine
{
	ChunkExpression::ChunkExpression(
		ChunkType type,
		ExpressionItem* expressionItem
	) : _expressionItem{ expressionItem }, _type{type}
	{

	}

}//namespace MathEngine