#pragma once

#include "ChunkExpression.hpp"

namespace MathEngine
{
	ChunkExpression::ChunkExpression(
		ChunkType type,
		std::shared_ptr<ExpressionItem> expressionItem
	) : _expressionItem{ std::move(expressionItem) }, _type{ type }
	{

	}

}//namespace MathEngine