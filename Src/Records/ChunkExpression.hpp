#pragma once

#include "Enums/ChunkType.hpp"

namespace MathEngine
{
	class ChunkExpression
	{
	public:
		ChunkExpression(
			ChunkType chunkType
		);

		ChunkExpression(const ChunkExpression& other) = delete;
		ChunkExpression(ChunkExpression&& other) = delete;

		ChunkExpression& operator=(ChunkExpression&& other) = delete;
		ChunkExpression& operator=(const ChunkExpression& other) = delete;

		const ChunkType& GetChunkType()
		{
			return _chunkType;
		}

	private:
		ChunkType _chunkType;
	};

}//namespace MathEngine