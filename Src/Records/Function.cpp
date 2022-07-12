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
		PatternExpression(type), _order{ order }, _associativity{ associativity }, _parametrsCount{parametrsCount}
	{

	}

}//namespace MathEngine