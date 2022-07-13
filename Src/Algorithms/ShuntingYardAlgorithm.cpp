#pragma once

#include "ShuntingYardAlgorithm.hpp"
#include <stack>
#include "../Records/Operator.hpp"
#include "../Helpers/ParserHelper.hpp"
#include "../Records/ChunkNumber.hpp"
#include "../Records/SequenceNumberOperation.hpp"
#include "fast_float.h"

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
					if (top->GetType() == ExpressionType::LeftBracket)
					{
						break;
					}

					stackOperators->pop();
					EnqueueOutput(
						sequenceStack,
						sequenceSize,
						expectedParamsSequence,
						output,
						new ChunkExpression(ChunkType::BaseExpression, reinterpret_cast<ExpressionItem*>(top))
					);
				}

				if (stackOperators->empty())
				{
					throw std::runtime_error("There are mismatched parentheses 'Left Bracket'");
				}

				Operator* top = stackOperators->top();
				delete top;
				stackOperators->pop();
			}

			//check is number
			numberLength = ParserHelper::IsNumber(chars, charsLength, i);
			if (numberLength != -1)
			{
				float number;
				auto answer2 = fast_float::from_chars(chars + i, chars + i + numberLength, number);

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
			Operator* oper = nullptr;
			if (ParserHelper::IsMultiplication(chars, charsLength, i))
			{
				oper = ParserHelper::CreateMultiplication();
			}
			else
			if (ParserHelper::IsDivision(chars, charsLength, i))
			{
				oper = ParserHelper::CreateDivision();
			}
			else
			if (ParserHelper::IsAddition(chars, charsLength, i))
			{
				oper = ParserHelper::CreateAddition();
			}
			else
			if (ParserHelper::IsSubtraction(chars, charsLength, i))
			{
				oper = ParserHelper::CreateSubtraction();
			}

			if (oper != nullptr)
			{
				while (!stackOperators->empty())
				{
					auto top = stackOperators->top();
					if (top->GetType() == ExpressionType::LeftBracket)
					{
						break;
					}

					if (!((top->GetOrder() > oper->GetOrder()) || (top->GetOrder() == oper->GetOrder() && oper->GetAssociativity() == Associativity::Left)))
					{
						break;
					}

					stackOperators->pop();
					EnqueueOutput(
						sequenceStack,
						sequenceSize,
						expectedParamsSequence,
						output,
						new ChunkExpression(ChunkType::BaseExpression, top)
					);
				}

				stackOperators->push(oper);
			}
		}

		while (!stackOperators->empty())
		{
			auto top = stackOperators->top();
			stackOperators->pop();
			if (top->GetType() == ExpressionType::LeftBracket)
			{
				throw std::runtime_error("There are mismatched parentheses 'Left Bracket in end'");
			}

			EnqueueOutput(
				sequenceStack,
				sequenceSize,
				expectedParamsSequence,
				output,
				new ChunkExpression(ChunkType::BaseExpression, top)
			);
		}

		if (!sequenceStack->empty())
		{
			auto top = sequenceStack->top();
			sequenceStack->pop();

			if (top->GetExpression()->GetType() == ExpressionType::Number)
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

	/// <summary>
	/// Enqueue to Output queue and apply optimization
	/// </summary>
	void ShuntingYardAlgorithm::EnqueueOutput(
		std::stack<ChunkExpression*>* const sequenceStack,
		int& sequenceSize,
		int& expectedParamsCount,
		std::queue<ChunkExpression*>& output,
		ChunkExpression* newChunk
	) 
	{
		switch (newChunk->GetExpression()->GetType())
		{
		case ExpressionType::Number:
		{
			if (sequenceStack->empty())
			{
				sequenceStack->push(newChunk);
				sequenceSize++;
				expectedParamsCount++;
				return;
			}

			auto chunk0 = sequenceStack->top();
			if (chunk0->GetExpression()->GetType() == ExpressionType::Number)
			{
				sequenceStack->pop();
				sequenceSize--;
				expectedParamsCount--;

				if (!sequenceStack->empty())
				{
					auto chunk1 = sequenceStack->top();
					if (chunk1->GetExpression()->GetType() == ExpressionType::Number)
					{
						throw std::runtime_error("Incorrect sequence");
					}
					sequenceStack->pop();

					WriteSequence(sequenceStack, sequenceSize, expectedParamsCount, output, chunk1->GetExpression());
					delete chunk1;
				}

				output.push(chunk0);
				sequenceStack->push(newChunk);
				sequenceSize++;
				expectedParamsCount++;

				return;
			}
			else
			{
				sequenceStack->push(newChunk);
				sequenceSize++;
				expectedParamsCount++;
				return;
			}

			break;
		}

		case ExpressionType::Multiplication:
		case ExpressionType::Addition:
		{
			if (sequenceStack->empty())
			{
				sequenceStack->push(newChunk);
				return;
			}
			else
			{
				auto chunk0 = sequenceStack->top();
				if (chunk0->GetExpression()->GetType() == ExpressionType::Number)
				{
					if (sequenceStack->size() == 1)
					{
						sequenceStack->push(newChunk);
						return;
					}
					else
					{
						sequenceStack->pop();
						auto chunk1 = sequenceStack->top();
						if (chunk1->GetExpression()->GetType() == ExpressionType::Number)
						{
							throw std::runtime_error("Incorrect sequence");
						}

						sequenceStack->pop();

						if (chunk1->GetExpression()->GetType() == newChunk->GetExpression()->GetType())
						{
							sequenceStack->push(chunk0);
							sequenceStack->push(newChunk);
							delete chunk1->GetExpression();
							delete chunk1;
						}
						else
						{
							sequenceSize--;
							expectedParamsCount--;

							WriteSequence(sequenceStack, sequenceSize, expectedParamsCount, output, chunk1->GetExpression());
							delete chunk1;

							sequenceStack->push(chunk0);
							sequenceSize = 1;
							expectedParamsCount = 1;
							sequenceStack->push(newChunk);
						}

						return;
					}
				}
				else
				{
					if (chunk0->GetExpression()->GetType() == newChunk->GetExpression()->GetType())
					{
						expectedParamsCount++;
					}
					else
					{
						sequenceStack->pop();
						WriteSequence(sequenceStack, sequenceSize, expectedParamsCount, output, chunk0->GetExpression());
						delete chunk0;

						output.push(newChunk);
					}

					return;
				}
			}
		}

		default:
		{
			if (sequenceStack->empty())
			{
				output.push(newChunk);
				return;
			}
			else
			{
				auto chunk0 = sequenceStack->top();
				sequenceStack->pop();
				if (chunk0->GetExpression()->GetType() == ExpressionType::Number)
				{
					sequenceSize--;
					expectedParamsCount--;

					if (!sequenceStack->empty())
					{
						auto chunk1 = sequenceStack->top();
						if (chunk1->GetExpression()->GetType() == ExpressionType::Number)
						{
							throw std::runtime_error("Incorrect sequence");
						}
						sequenceStack->pop();

						WriteSequence(sequenceStack, sequenceSize, expectedParamsCount, output, chunk1->GetExpression());
						delete chunk1;
					}

					output.push(chunk0);
				}
				else
				{
					WriteSequence(sequenceStack, sequenceSize, expectedParamsCount, output, chunk0->GetExpression());
					delete chunk0;
				}

				output.push(newChunk);
			}

			return;
		}

		}
	}

	void ShuntingYardAlgorithm::WriteSequence(
		std::stack<ChunkExpression*>* const sequenceStack,
		int& sequenceSize,
		int& expectedParamsCount,
		std::queue<ChunkExpression*>& output,
		ExpressionItem* oper
	) 
	{
		//TODO get from pool
		auto memory = new float[expectedParamsCount + 1];
		try
		{
			int indexMemory = expectedParamsCount + 1 - sequenceSize;
			while (!sequenceStack->empty())
			{
				auto item = sequenceStack->top();
				sequenceStack->pop();

				if (item->GetExpression()->GetType() == ExpressionType::Number)
				{
					memory[indexMemory] = (reinterpret_cast<ChunkNumber*>(item))->GetNumber();
					indexMemory++;
				}

				delete item->GetExpression();
				delete item;
			}

			output.push(new SequenceNumberOperation(reinterpret_cast<PatternExpression*>(oper), memory, sequenceSize, expectedParamsCount + 1));
		}
		catch (const std::exception&)
		{
			delete[] memory;
			throw;
		}

		sequenceSize = 0;
		expectedParamsCount = 0;
	}

	void ShuntingYardAlgorithm::PrintRVNAndDequeueAll(
		std::queue<ChunkExpression*>& rvn,
		std::stringstream& strStream
	)
	{
		//TODO
	}

}//namespace MathEngine