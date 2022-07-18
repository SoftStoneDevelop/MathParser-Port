#pragma once

#include "PatternExpression.hpp"
#include "..\Enums\Associativity.hpp"
#include "..\Enums\ChunkType.hpp"
#include <string>

namespace MathEngine
{
	class Function : public PatternExpression
	{
	public:
		Function(
			ExpressionType type,
			int order,
			Associativity associativity,
			int parametrsCount
		);

		Function(const Function& other) = delete;
		Function(Function&& other) = delete;

		Function& operator=(Function&& other) = delete;
		Function& operator=(const Function& other) = delete;

		const int& GetParametrsCount() const
		{
			return _parametrsCount;
		}

	private:
		int _parametrsCount;
	};

}//namespace MathEngine