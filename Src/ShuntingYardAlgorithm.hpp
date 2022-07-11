#pragma once

#include "Enums/Associativity.hpp"
#include "Enums/ChunkType.hpp"

#include <queue>
#include <string>
#include <stack>
#include <sstream>

namespace MathEngine
{
	class ExpressionItem
	{
	public:
		ChunkType ChunkType;
	};

	class Operand : ExpressionItem
	{
	};

	class PatternExpression : ExpressionItem
	{
	public:
		std::string Pattern;
	};

	class Operator : PatternExpression
	{
	public:
		int Order;
		Associativity Associativity;
	};

	class Function : PatternExpression
	{
	public:
		int Order;
		Associativity Associativity;
		int ParametrsCount;
	};

	class ChunkExpression
	{
	public:
		ChunkType ChunkType;
	};

	class ChunkNumber : ChunkExpression
	{
	public:
		float Number;
		Operand& Operand;
	};

	class SequenceNumberOperation : ChunkExpression
	{
	public:
		float* sequenceMemory;
		int Size;
		int ExpectedParamsCount;
	};

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
			const std::queue<ChunkExpression&>& output
		);

		static void PrintRVNAndDequeueAll(const std::queue<const ChunkExpression&> rvn, const std::stringstream& strStream);

	private:
		
		/// <summary>
		/// Enqueue to Output queue and apply optimization
		/// </summary>
		static void EnqueueOutput(
			const std::stack<ChunkExpression&>& sequenceStack,
			const int& sequenceSize,
			const int& expectedParamsCount,
			const std::queue<ChunkExpression&>& output,
			const ChunkExpression& newChunk
		);

		static void WriteSequence(
			const std::stack<ChunkExpression&> sequenceStack,
			const int& sequenceSize,
			const int& expectedParamsCount,
			const std::queue<ChunkExpression&>& output,
			const ExpressionItem& oper
		);
	};

}//namespace MathEngine