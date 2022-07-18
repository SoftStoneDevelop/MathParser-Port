#pragma once

#include "ExpressionItem.hpp"
#include <memory>

namespace MathEngine
{
	class ChunkExpression
	{
	public:
		ChunkExpression(
			ChunkType type,
			std::shared_ptr<ExpressionItem> expressionItem
		);

		ChunkExpression(const ChunkExpression& other) = delete;
		ChunkExpression(ChunkExpression&& other) = delete;

		ChunkExpression& operator=(ChunkExpression&& other) = delete;
		ChunkExpression& operator=(const ChunkExpression& other) = delete;

		ExpressionItem* GetExpression() const
		{
			return _expressionItem.get();
		}

		std::shared_ptr<ExpressionItem> GetSharedExpression() const
		{
			return _expressionItem;
		}

		const ChunkType& GetType() const
		{
			return _type;
		}

	private:
		std::shared_ptr<ExpressionItem> _expressionItem;
		ChunkType _type;
	};

}//namespace MathEngine