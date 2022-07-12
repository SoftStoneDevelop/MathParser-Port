#pragma once

#include "ShuntingYardAlgorithm.hpp"
#include <stack>
#include "../Records/Operator.hpp"
#include "../Helpers/ParserHelper.hpp"

namespace MathEngine
{
	void ShuntingYardAlgorithm::ToRVNOpt(
		const char* chars,
		const int& charsLength,
		const std::queue<ChunkExpression*>& output
	)
	{
		std::stack<const Operator*>* stackOperators = new std::stack<const Operator*>();
		int numberLength = 0;
		std::stack<ChunkExpression>* sequenceStack = new std::stack<ChunkExpression>();

		int sequenceSize = 0;
		int expectedParamsSequence = 0;

		for (int i = 0; i < charsLength; i++)
		{
			if (chars[i] == ' ')
			{
				continue;
			}

			if (chars[i] == '(')
			{
				stackOperators->push(&ParserHelper::LeftBracket);
				continue;
			}
		}

		delete stackOperators;
		delete sequenceStack;
	}

	void ShuntingYardAlgorithm::PrintRVNAndDequeueAll(
		const std::queue<ChunkExpression*> rvn,
		const std::stringstream& strStream
	) 
	{

	}

	/// <summary>
	/// Enqueue to Output queue and apply optimization
	/// </summary>
	void ShuntingYardAlgorithm::EnqueueOutput(
		const std::stack<ChunkExpression*>& sequenceStack,
		const int& sequenceSize,
		const int& expectedParamsCount,
		const std::queue<ChunkExpression*>& output,
		const ChunkExpression& newChunk
	) 
	{

	}

	void ShuntingYardAlgorithm::WriteSequence(
		const std::stack<ChunkExpression*> sequenceStack,
		const int& sequenceSize,
		const int& expectedParamsCount,
		const std::queue<ChunkExpression*>& output,
		const ExpressionItem& oper
	) 
	{

	}

}//namespace MathEngine