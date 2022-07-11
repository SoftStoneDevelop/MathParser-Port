#pragma once

#include <string>

namespace MathEngine
{
	class MathEngine 
	{
	public:
		float CalculateExpression(const std::string& expression);

		float CalculateExpression(const char* expression, const int& expressionSize);
	};
}