#pragma once

#include "PatternExpression.hpp"
#include "..\Enums\Associativity.hpp"
#include "..\Enums\ChunkType.hpp"
#include <string>

namespace MathEngine
{
	class Function : PatternExpression
	{
	public:
		Function(
			ChunkType chunkType,
			std::string pattern,
			int order,
			Associativity associativity,
			int parametrsCount
		);

		Function(const Function& other) = delete;
		Function(Function&& other) = delete;

		Function& operator=(Function&& other) = delete;
		Function& operator=(const Function& other) = delete;

		const Associativity& GetAssociativity()
		{
			return _associativity;
		}

		const int& GetOrder()
		{
			return _order;
		}

		const int& GetParametrsCount()
		{
			return _parametrsCount;
		}

	private:
		int _order;
		Associativity _associativity;
		int _parametrsCount;
	};

}//namespace MathEngine