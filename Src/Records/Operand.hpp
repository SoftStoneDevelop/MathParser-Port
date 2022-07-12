#pragma once

#include "..\Enums\ChunkType.hpp"
#include "ExpressionItem.hpp"

namespace MathEngine
{
	class Operand : ExpressionItem
	{
	public:
		Operand(ChunkType chunkType);

		Operand(const Operand& other) = delete;
		Operand(Operand&& other) = delete;

		Operand& operator=(Operand&& other) = delete;
		Operand& operator=(const Operand& other) = delete;
	};

}//namespace MathEngine