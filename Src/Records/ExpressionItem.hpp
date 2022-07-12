#pragma once

#include "..\Enums\ChunkType.hpp"

namespace MathEngine
{
	class ExpressionItem
	{
	public:

		ExpressionItem(ChunkType chunkType);

		ExpressionItem(const ExpressionItem& other) = delete;
		ExpressionItem(ExpressionItem&& other) = delete;

		ExpressionItem& operator=(ExpressionItem&& other) = delete;
		ExpressionItem& operator=(const ExpressionItem& other) = delete;

		const ChunkType& GetChunkType()
		{
			return _chunkType;
		}

	private:
		ChunkType _chunkType;
	};

}//namespace MathEngine