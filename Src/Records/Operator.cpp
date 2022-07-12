#pragma once

#include "Operator.hpp"

namespace MathEngine
{
	Operator::Operator(
		ExpressionType type,
		int order,
		Associativity associativity
	) :
		PatternExpression(type), _order{ order }, _associativity{associativity}
	{

	}

}//namespace MathEngine