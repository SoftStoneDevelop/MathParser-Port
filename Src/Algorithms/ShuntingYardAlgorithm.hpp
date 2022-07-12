#pragma once

#include "..\Enums\Associativity.hpp"
#include "..\Enums\ChunkType.hpp"
#include "../Records/ChunkExpression.hpp"
#include "../Records/ExpressionItem.hpp"

#include <queue>
#include <string>
#include <stack>
#include <sstream>

namespace MathEngine
{
	class ShuntingYardAlgorithm
	{
	public:
		
		/// <summary>
		/// Convert infix notation to RPN <see cref="https://en.wikipedia.org/wiki/Shunting_yard_algorithm"/>
		/// </summary>
		/// <param name="chars">Input math expression in infix notation</param>
		/// <param name="charsLength">length chars array</param>
		/// <param name="output">Output data in the peverse polish notation <see cref="https://en.wikipedia.org/wiki/Reverse_Polish_notation"/></param>
		static void ToRVNOpt(
			const char* chars,
			const int& charsLength,
			std::queue<ChunkExpression*>& output
		);

		static void PrintRVNAndDequeueAll(
			std::queue<ChunkExpression*>& rvn,
			std::stringstream& strStream
		);

	private:
		
		/// <summary>
		/// Enqueue to Output queue and apply optimization
		/// </summary>
		static void EnqueueOutput(
			std::stack<ChunkExpression*>* const sequenceStack,
			const int& sequenceSize,
			const int& expectedParamsCount,
			std::queue<ChunkExpression*>& output,
			const ChunkExpression* newChunk
		);

		static void WriteSequence(
			std::stack<ChunkExpression*>* const sequenceStack,
			const int& sequenceSize,
			const int& expectedParamsCount,
			std::queue<ChunkExpression*>& output,
			const ExpressionItem* oper
		);
	};

}//namespace MathEngine