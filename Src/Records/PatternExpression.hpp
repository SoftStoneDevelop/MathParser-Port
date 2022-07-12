#pragma once

#include "ExpressionItem.hpp"
#include "..\Enums\ChunkType.hpp"
#include <string>

namespace MathEngine
{
	class PatternExpression : public ExpressionItem
	{
	public:
		PatternExpression(ExpressionType type);

		PatternExpression(const PatternExpression& other) = delete;
		PatternExpression(PatternExpression&& other) = delete;

		PatternExpression& operator=(PatternExpression&& other) = delete;
		PatternExpression& operator=(const PatternExpression& other) = delete;

	private:
	};

}//namespace MathEngine