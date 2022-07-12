#pragma once

#include "..\Enums\ChunkType.hpp"
#include "ChunkExpression.hpp"
#include "Operand.hpp"
#include <iostream>

namespace MathEngine
{
	class ChunkNumber : ChunkExpression
	{
	public:
		ChunkNumber(
			ChunkType chunkType,
			float number,
			Operand& operand
		);

		ChunkNumber(const ChunkNumber& other) = delete;
		ChunkNumber(ChunkNumber&& other) = delete;

		ChunkNumber& operator=(ChunkNumber&& other) = delete;
		ChunkNumber& operator=(const ChunkNumber& other) = delete;

		const float& GetNumber()
		{
			return _number;
		}

		const Operand& GetOperand()
		{
			return _operand;
		}

	private:
		float _number;
		Operand& _operand;
	};

}//namespace MathEngine