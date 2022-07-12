#pragma once

#include <string>

namespace MathEngine
{
	class MathEngine 
	{
	public:
		float CalculateExpression(const std::string& expression);

		float CalculateExpression(const char* expression, const int& expressionSize);

		float Multiplication(float* data, const int& size);

		float Addition(float* data, const int& size);
	};
}