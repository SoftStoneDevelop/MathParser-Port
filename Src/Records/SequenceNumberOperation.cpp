#pragma once

#include "SequenceNumberOperation.hpp"

namespace MathEngine
{
	SequenceNumberOperation::SequenceNumberOperation(
		PatternExpression* patternExp,
		float* sequenceMemory,
		int size,
		int expectedParamsCount
		//TODO pool arrays
	) :
		ChunkExpression(ChunkType::SequenceNumberOperation, patternExp),
		_sequenceMemory{ sequenceMemory },
		_size{ size },
		_expectedParamsCount{ expectedParamsCount }
		//TODO pool arrays
	{

	}

	SequenceNumberOperation::~SequenceNumberOperation()
	{
		//TODO release sequenceMemory to the _PoolArrays
	}

}//namespace MathEngine