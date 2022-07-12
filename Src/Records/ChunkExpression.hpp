#pragma once

#include "ExpressionItem.hpp"

namespace MathEngine
{
	class ChunkExpression
	{
	public:
		ChunkExpression(
			ChunkType type,
			ExpressionItem* expressionItem
		);

		ChunkExpression(const ChunkExpression& other) = delete;
		ChunkExpression(ChunkExpression&& other) = delete;

		ChunkExpression& operator=(ChunkExpression&& other) = delete;
		ChunkExpression& operator=(const ChunkExpression& other) = delete;

		ExpressionItem* GetExpression() const
		{
			return _expressionItem;
		}

		const ChunkType& GetType() const
		{
			return _type;
		}

	private:
		ExpressionItem* _expressionItem;
		ChunkType _type;
	};

}//namespace MathEngine