#pragma once

#include "PatternExpression.hpp"

namespace MathEngine
{
	PatternExpression::PatternExpression(
		ExpressionType type,
		int order,
		Associativity associativity
	) : ExpressionItem(type)
	{

	}

}//namespace MathEngine