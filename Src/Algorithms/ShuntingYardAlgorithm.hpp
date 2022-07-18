#pragma once

#include "..\Enums\Associativity.hpp"
#include "..\Enums\ChunkType.hpp"
#include "../Records/ChunkExpression.hpp"
#include "../Records/ExpressionItem.hpp"

#include <queue>
#include <string>
#include <stack>
#include <sstream>
#include "Helpers/ParserHelper.hpp"

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
		void ToRVNOpt(
			const char* chars,
			const int& charsLength,
			std::queue<ChunkExpression*>& output
		);

		void PrintRVNAndDequeueAll(
			std::queue<ChunkExpression*>& rvn,
			std::stringstream& strStream
		);

	private:
		
		/// <summary>
		/// Enqueue to Output queue and apply optimization
		/// </summary>
		void EnqueueOutput(
			std::stack<ChunkExpression*>& sequenceStack,
			int& sequenceSize,
			int& expectedParamsCount,
			std::queue<ChunkExpression*>& output,
			ChunkExpression* newChunk
		);

		void WriteSequence(
			std::stack<ChunkExpression*>& sequenceStack,
			int& sequenceSize,
			int& expectedParamsCount,
			std::queue<ChunkExpression*>& output,
			std::shared_ptr<ExpressionItem> oper
		);

		ParserHelper _parserHelper{};
	};

}//namespace MathEngine