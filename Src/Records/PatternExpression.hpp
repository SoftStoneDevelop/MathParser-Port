#pragma once

#include "ExpressionItem.hpp"
#include "..\Enums\ChunkType.hpp"
#include "Enums/Associativity.hpp"
#include <string>

namespace MathEngine
{
	class PatternExpression : public ExpressionItem
	{
	public:
		PatternExpression(
			ExpressionType type,
			int order,
			Associativity associativity
		);

		PatternExpression(const PatternExpression& other) = delete;
		PatternExpression(PatternExpression&& other) = delete;

		PatternExpression& operator=(PatternExpression&& other) = delete;
		PatternExpression& operator=(const PatternExpression& other) = delete;

		const Associativity& GetAssociativity() const
		{
			return _associativity;
		}

		const int& GetOrder() const
		{
			return _order;
		}

	private:
		int _order;
		Associativity _associativity;
	};

}//namespace MathEngine