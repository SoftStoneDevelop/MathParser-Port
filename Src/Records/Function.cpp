#pragma once

#include "Function.hpp"

namespace MathEngine
{
	Function::Function(
		ExpressionType type,
		int order,
		Associativity associativity,
		int parametrsCount
	) :
		PatternExpression(type, order, associativity), _parametrsCount{parametrsCount}
	{

	}

}//namespace MathEngine