#pragma once

#include "..\Enums\ChunkType.hpp"

namespace MathEngine
{
	class ExpressionItem
	{
	public:

		ExpressionItem(ExpressionType type);

		ExpressionItem(const ExpressionItem& other) = delete;
		ExpressionItem(ExpressionItem&& other) = delete;

		ExpressionItem& operator=(ExpressionItem&& other) = delete;
		ExpressionItem& operator=(const ExpressionItem& other) = delete;

		const ExpressionType& GetType() const
		{
			return _type;
		}

	private:
		ExpressionType _type;
	};

}//namespace MathEngine