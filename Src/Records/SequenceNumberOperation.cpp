#pragma once

#include "SequenceNumberOperation.hpp"

namespace MathEngine
{
	SequenceNumberOperation::SequenceNumberOperation(
		ChunkType chunkType,
		PatternExpression& patternExp,
		float* sequenceMemory,
		int size,
		int expectedParamsCount
		//TODO pool arrays
	) :
		ChunkExpression(chunkType),
		_sequenceMemory{ sequenceMemory },
		_size{ size },
		_expectedParamsCount{ expectedParamsCount },
		_patternExp{ patternExp }
		//TODO pool arrays
	{

	}

	SequenceNumberOperation::~SequenceNumberOperation()
	{
		//TODO release sequenceMemory to the _PoolArrays
	}

}//namespace MathEngine