#pragma once

#include "PatternExpression.hpp"
#include "..\Enums\Associativity.hpp"
#include "..\Enums\ChunkType.hpp"
#include <string>

namespace MathEngine
{
	class Operator : public PatternExpression
	{
	public:
		Operator(
			ExpressionType type,
			int order,
			Associativity associativity
		);

		Operator(const Operator& other) = delete;
		Operator(Operator&& other) = delete;

		Operator& operator=(Operator&& other) = delete;
		Operator& operator=(const Operator& other) = delete;
	};

}//namespace MathEngine