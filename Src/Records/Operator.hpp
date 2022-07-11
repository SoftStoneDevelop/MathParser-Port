#pragma once

#include "PatternExpression.hpp"
#include "Enums/Associativity.hpp"
#include "Enums/ChunkType.hpp"
#include <string>

namespace MathEngine
{
	class Operator : PatternExpression
	{
	public:
		Operator(
			ChunkType chunkType,
			std::string pattern,
			int order,
			Associativity associativity
		);

		Operator(const Operator& other) = delete;
		Operator(Operator&& other) = delete;

		Operator& operator=(Operator&& other) = delete;
		Operator& operator=(const Operator& other) = delete;

		const Associativity& GetAssociativity()
		{
			return _associativity;
		}

		const int& GetOrder()
		{
			return _order;
		}

	private:
		int _order;
		Associativity _associativity;
	};

}//namespace MathEngine