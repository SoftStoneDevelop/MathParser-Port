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
		ShuntingYardAlgorithm::ToRVNOpt(expression, expressionSize, *queue);
		std::stack<float>* const  stackOperands = new std::stack<float>();

		while (!queue->empty())
		{
			auto chunk = queue->front();
			queue->pop();

			if (chunk->GetType() == ChunkType::Number)
			{
				stackOperands->emplace(static_cast<ChunkNumber*>(chunk)->GetNumber());
				delete chunk->GetExpression();
				delete chunk;

				continue;
			}

			if (chunk->GetType() == ChunkType::SequenceNumberOperation)
			{
				SequenceNumberOperation* sequenceNumberOperation = static_cast<SequenceNumberOperation*>(chunk);
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

				switch (sequenceNumberOperation->GetExpression()->GetType())
				{
				case ExpressionType::Multiplication:
				{
					//TODO
					break;
				}

				case ExpressionType::Addition:
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

				continue;
			}
			
			if (chunk->GetExpression()->GetType() == ExpressionType::Sin)
			{
				Function* function = static_cast<Function*>(chunk->GetExpression());
				if (stackOperands->size() < function->GetParametrsCount())
				{
					throw std::runtime_error("Not enough operands for calculate operator Sin");
				}

				auto a = stackOperands->top();
				stackOperands->pop();

				stackOperands->push(sin(a));

				delete function;
				delete chunk;
				continue;
			}

			switch (chunk->GetExpression()->GetType())
			{

			case ExpressionType::Multiplication:
			{
				if (stackOperands->size() < 2)
				{
					throw std::runtime_error("Not enough operands for calculate operator Multiplication");
				}

				auto b = stackOperands->top();
				stackOperands->pop();

				auto a = stackOperands->top();
				stackOperands->pop();

				stackOperands->emplace(a * b);

				break;
			}

			case ExpressionType::Addition:
			{
				if (stackOperands->size() < 2)
				{
					throw std::runtime_error("Not enough operands for calculate operator Addition");
				}

				auto b = stackOperands->top();
				stackOperands->pop();

				auto a = stackOperands->top();
				stackOperands->pop();

				stackOperands->emplace(a + b);
				break;
			}

			case ExpressionType::Division:
			{
				if (stackOperands->size() < 2)
				{
					throw std::runtime_error("Not enough operands for calculate operator Division");
				}

				auto b = stackOperands->top();
				stackOperands->pop();

				auto a = stackOperands->top();
				stackOperands->pop();

				stackOperands->emplace(a / b);
				break;
			}

			case ExpressionType::Subtraction:
			{
				if (stackOperands->size() < 2)
				{
					throw std::runtime_error("Not enough operands for calculate operator Subtraction");
				}

				auto b = stackOperands->top();
				stackOperands->pop();

				auto a = stackOperands->top();
				stackOperands->pop();

				stackOperands->emplace(a - b);
				break;
			}

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