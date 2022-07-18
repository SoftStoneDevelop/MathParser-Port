#pragma once

#include "SequenceNumberOperation.hpp"

namespace MathEngine
{
	SequenceNumberOperation::SequenceNumberOperation(
		std::shared_ptr<PatternExpression> patternExp,
		float* sequenceMemory,
		int size,
		int expectedParamsCount
		//TODO pool arrays
	) :
		ChunkExpression(ChunkType::SequenceNumberOperation, std::move(patternExp)),
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