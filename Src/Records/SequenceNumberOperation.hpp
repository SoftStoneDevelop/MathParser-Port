#pragma once

#include "..\Enums\ChunkType.hpp"
#include "ChunkExpression.hpp"
#include "PatternExpression.hpp"

namespace MathEngine
{
	class SequenceNumberOperation : public ChunkExpression
	{
	public:
		SequenceNumberOperation(
			std::shared_ptr<PatternExpression> patternExp,
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

		const int& GetSize() const
		{
			return _size;
		}

		float* GetSequenceMemory() const
		{
			return _sequenceMemory;
		}

		const int& GetExpectedParamsCount() const
		{
			return _expectedParamsCount;
		}

	private:
		float* _sequenceMemory;
		int _size;
		int _expectedParamsCount;
		std::shared_ptr<PatternExpression> _patternExp;
		//TODO pool arrays
	};

}//namespace MathEngine