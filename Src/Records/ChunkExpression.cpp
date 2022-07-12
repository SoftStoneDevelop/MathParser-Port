#pragma once

#include "ChunkExpression.hpp"
#include <istream>

namespace MathEngine
{
	ChunkExpression::ChunkExpression(
		ExpressionItem* expressionItem
	) : _expressionItem{ expressionItem }
	{

	}

}//namespace MathEngine