#pragma once

#include "..\Enums\ChunkType.hpp"
#include "ChunkExpression.hpp"
#include "PatternExpression.hpp"
#include <iostream>

namespace MathEngine
{
	class SequenceNumberOperation : ChunkExpression
	{
	public:
		SequenceNumberOperation(
			ChunkType chunkType,
			PatternExpression& patternExp,
			float* sequenceMemory,
			int size,
			int expectedParamsCount
			//TODO pool arrays
		);

		~SequenceNumberOperation();

		SequenceNumberOperation(const SequenceNumberOperation& other) = delete;
		SequenceNumberOperation(SequenceNumberOperation&& other) = delete;

		SequenceNumberOperation& operator=(SequenceNumberOperation&& other) = delete;
		SequenceNumberOperation& operator=(const SequenceNumberOperation& other) = delete;

		const int& GetSize()
		{
			return _size;
		}

		const float& GetSequenceMemory()
		{
			return *_sequenceMemory;
		}

		const int& GetExpectedParamsCount()
		{
			return _expectedParamsCount;
		}

		const PatternExpression& GetPatternExp()
		{
			return _patternExp;
		}

	private:
		float* _sequenceMemory;
		int _size;
		int _expectedParamsCount;
		PatternExpression& _patternExp;
		//TODO pool arrays
	};

}//namespace MathEngine