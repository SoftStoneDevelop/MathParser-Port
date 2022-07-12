#pragma once

#include <cstdlib>
#include <iostream>
#include "Algorithms/ShuntingYardAlgorithm.hpp"
#include "Records/ChunkExpression.hpp"
#include "MathEngine.hpp"
#include <string>

int main()
{
	MathEngine::MathEngine engine;
	auto result = engine.CalculateExpression("5 - 2 + 11");

	return EXIT_SUCCESS;
}