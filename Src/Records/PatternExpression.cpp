#pragma once

#include "PatternExpression.hpp"

namespace MathEngine
{
	PatternExpression::PatternExpression(
		ExpressionType type,
		int order,
		Associativity associativity
	) : ExpressionItem(type), _order{order}, _associativity{associativity}
	{

	}

}//namespace MathEngine