#pragma once

#include "Operator.hpp"

namespace MathEngine
{
	Operator::Operator(
		ExpressionType type,
		int order,
		Associativity associativity
	) :
		PatternExpression(type, order, associativity)
	{

	}

}//namespace MathEngine