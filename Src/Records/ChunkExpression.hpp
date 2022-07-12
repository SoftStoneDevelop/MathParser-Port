#pragma once

#include "ExpressionItem.hpp"

namespace MathEngine
{
	class ChunkExpression
	{
	public:
		ChunkExpression(
			ExpressionItem* expressionItem
		);

		ChunkExpression(const ChunkExpression& other) = delete;
		ChunkExpression(ChunkExpression&& other) = delete;

		ChunkExpression& operator=(ChunkExpression&& other) = delete;
		ChunkExpression& operator=(const ChunkExpression& other) = delete;

		const ExpressionItem* GetExpression() const
		{
			return _expressionItem;
		}

	private:
		ExpressionItem* _expressionItem;
	};

}//namespace MathEngine