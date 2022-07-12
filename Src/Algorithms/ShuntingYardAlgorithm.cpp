#pragma once

#include "ShuntingYardAlgorithm.hpp"
#include <stack>
#include "../Records/Operator.hpp"
#include "../Helpers/ParserHelper.hpp"
#include "../Records/ChunkNumber.hpp"

namespace MathEngine
{
	void ShuntingYardAlgorithm::ToRVNOpt(
		const char* chars,
		const int& charsLength,
		std::queue<ChunkExpression*>& output
	)
	{
		std::stack<Operator*>* stackOperators = new std::stack<Operator*>();
		int numberLength = 0;
		std::stack<ChunkExpression*>* sequenceStack = new std::stack<ChunkExpression*>();

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
				stackOperators->push(ParserHelper::CreateLeftBracket());
				continue;
			}

			if (chars[i] == ')')
			{
				if (stackOperators->empty())
				{
					throw std::runtime_error("The operator stack is empty");
				}

				while (!stackOperators->empty())
				{
					Operator* top = stackOperators->top();
					if ((*top).GetChunkType() == ChunkType::LeftBracket)
					{
						break;
					}

					stackOperators->pop();
					EnqueueOutput(
						sequenceStack,
						sequenceSize,
						expectedParamsSequence,
						output,
						new ChunkExpression(reinterpret_cast<ExpressionItem*>(top))
					);
				}

				if (stackOperators->empty())
				{
					throw std::runtime_error("There are mismatched parentheses 'Left Bracket'");
				}

				stackOperators->pop();
			}

			//check is number
			numberLength = ParserHelper::IsNumber(chars, charsLength, i);
			if (numberLength != -1)
			{
				//TODO cast
				float number;

				EnqueueOutput(
					sequenceStack,
					sequenceSize,
					expectedParamsSequence,
					output,
					new ChunkNumber(number, ParserHelper::CreateNumber())
				);

				i += numberLength - 1;

				continue;
			}

			//check is function
			if (ParserHelper::IsSin(chars, charsLength, i))
			{
				stackOperators->push(reinterpret_cast<Operator*>(ParserHelper::CreateSin()));
				continue;
			}

			//check is operator

			if (ParserHelper::IsMultiplication(chars, charsLength, i))
			{
				stackOperators->push(ParserHelper::CreateMultiplication());
				continue;
			}
			
			if (ParserHelper::IsDivision(chars, charsLength, i))
			{
				stackOperators->push(ParserHelper::CreateDivision());
				continue;
			}
			
			if (ParserHelper::IsAddition(chars, charsLength, i))
			{
				stackOperators->push(ParserHelper::CreateAddition());
				continue;
			}
			
			if (ParserHelper::IsSubtraction(chars, charsLength, i))
			{
				stackOperators->push(ParserHelper::CreateSubtraction());
				continue;
			}
		}

		while (!stackOperators->empty())
		{
			auto top = stackOperators->top();
			stackOperators->pop();
			if (top->GetChunkType() == ChunkType::LeftBracket)
			{
				throw std::runtime_error("There are mismatched parentheses 'Left Bracket in end'");
			}

			EnqueueOutput(
				sequenceStack,
				sequenceSize,
				expectedParamsSequence,
				output,
				new ChunkExpression(top)
			);
		}

		if (!sequenceStack->empty())
		{
			auto top = sequenceStack->top();
			sequenceStack->pop();

			if (top->GetExpression()->GetChunkType() == ChunkType::Number)
			{
				throw std::runtime_error("Sequence must ended on number");
			}

			if (sequenceStack->empty())
			{
				output.push(top);
			}
			else
			{
				WriteSequence(
					sequenceStack,
					sequenceSize,
					expectedParamsSequence,
					output,
					top->GetExpression()
				);

				delete top;
			}
		}

		delete stackOperators;
		delete sequenceStack;
	}

	void ShuntingYardAlgorithm::PrintRVNAndDequeueAll(
		std::queue<ChunkExpression*>& rvn,
		std::stringstream& strStream
	) 
	{

	}

	/// <summary>
	/// Enqueue to Output queue and apply optimization
	/// </summary>
	void ShuntingYardAlgorithm::EnqueueOutput(
		std::stack<ChunkExpression*>* const sequenceStack,
		const int& sequenceSize,
		const int& expectedParamsCount,
		std::queue<ChunkExpression*>& output,
		const ChunkExpression* newChunk
	) 
	{

	}

	void ShuntingYardAlgorithm::WriteSequence(
		std::stack<ChunkExpression*>* const sequenceStack,
		const int& sequenceSize,
		const int& expectedParamsCount,
		std::queue<ChunkExpression*>& output,
		const ExpressionItem* oper
	) 
	{

	}

}//namespace MathEngine