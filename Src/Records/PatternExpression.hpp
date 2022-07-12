#pragma once

#include "ExpressionItem.hpp"
#include "..\Enums\ChunkType.hpp"
#include <string>

namespace MathEngine
{
	class PatternExpression : ExpressionItem
	{
	public:
		PatternExpression(ChunkType chunkType, std::string pattern);

		PatternExpression(const PatternExpression& other) = delete;
		PatternExpression(PatternExpression&& other) = delete;

		PatternExpression& operator=(PatternExpression&& other) = delete;
		PatternExpression& operator=(const PatternExpression& other) = delete;

		const std::string& GetPattern()
		{
			return _pattern;
		}

	private:
		std::string _pattern;
	};

}//namespace MathEngine