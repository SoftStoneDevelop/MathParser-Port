#pragma once

#include "MathEngine.hpp"
#include "Algorithms/ShuntingYardAlgorithm.hpp"
#include "Records/Function.hpp"
#include "Records/ChunkNumber.hpp"
#include "Records/SequenceNumberOperation.hpp"
#include "Records/Operator.hpp"
#include <cmath>

namespace MathEngine
{
	float MathEngine::CalculateExpression(const std::string& expression)
	{
		return CalculateExpression(expression.c_str(), expression.size());
	}

	float MathEngine::CalculateExpression(
		const char* expression,
		const int& expressionSize
	)
	{
		std::queue<ChunkExpression*>* const queue = new std::queue<ChunkExpression*>();
		ShuntingYardAlgorithm::ToRVNOpt(expression, expressionSize, queue);
		std::stack<float>* const  stackOperands = new std::stack<float>();

		while (!queue->empty())
		{
			auto chunk = queue->front();
			queue->pop();

			if (chunk->GetExpression()->GetChunkType() == ChunkType::Number)
			{
				stackOperands->emplace(reinterpret_cast<ChunkNumber*>(chunk)->GetNumber());
				delete chunk->GetExpression();
				delete chunk;

				continue;
			}

			SequenceNumberOperation* sequenceNumberOperation = dynamic_cast<SequenceNumberOperation*>(chunk);
			if (sequenceNumberOperation != nullptr)
			{
				int startIndex = sequenceNumberOperation->GetExpectedParamsCount() - sequenceNumberOperation->GetSize();
				for (int i = 0; i < startIndex; i++)
				{
					if (stackOperands->empty())
					{
						throw std::runtime_error("Not enough operands for calculate operator");
					}

					sequenceNumberOperation->GetSequenceMemory()[i] = stackOperands->top();
					stackOperands->pop();
				}

				switch (sequenceNumberOperation->GetExpression()->GetChunkType())
				{
				case ChunkType::Multiplication:
				{
					//TODO
					break;
				}

				case ChunkType::Addition:
				{
					//TODO
					break;
				}

				default:
				{
					throw std::runtime_error("Unknown SequenceNumberOperation");
				}
				}

				delete sequenceNumberOperation->GetExpression();
				delete[] sequenceNumberOperation->GetSequenceMemory();
				delete sequenceNumberOperation;
			}

			Function* function = dynamic_cast<Function*>(chunk->GetExpression());
			if (function != nullptr)
			{
				if (stackOperands->size() < function->GetParametrsCount())
				{
					throw std::runtime_error("Not enough operands for calculate operator Sin");
				}

				switch (function->GetChunkType())
				{
				case ChunkType::Sin:
				{
					auto a = stackOperands->top();
					stackOperands->pop();

					stackOperands->push(sin(a));
					break;
				}
				}

				delete function;
				delete chunk;
				continue;
			}

			Operator* oper = dynamic_cast<Operator*>(chunk->GetExpression());
			if (oper != nullptr)
			{
				if (stackOperands->size() < 2)
				{
					throw std::runtime_error("Not enough operands for calculate operator");
				}

				auto a = stackOperands->top();
				stackOperands->pop();

				auto b = stackOperands->top();
				stackOperands->pop();

				switch (oper->GetChunkType())
				{
				
				case ChunkType::Multiplication:
				{
					stackOperands->emplace(a*b);
					break;
				}

				case ChunkType::Addition:
				{
					stackOperands->emplace(a + b);
					break;
				}

				case ChunkType::Division:
				{
					stackOperands->emplace(a / b);
					break;
				}

				case ChunkType::Subtraction:
				{
					stackOperands->emplace(a - b);
					break;
				}

				}

				delete oper;
				delete chunk;
				continue;
			}


			delete chunk->GetExpression();
			delete chunk;
		}

		auto result = stackOperands->top();

		delete stackOperands;
		delete queue;

		return result;
	}
}