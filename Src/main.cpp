#pragma once

#include <cstdlib>
#include <iostream>
#include "Algorithms/ShuntingYardAlgorithm.hpp"
#include "Records/ChunkExpression.hpp"
#include "MathEngine.hpp"
#include <string>

int main()
{
	std::cout << "Write 'Exit' for close application" << std::endl;
	MathEngine::MathEngine engine;

	/*for (int i = 0; i < 100000; i++)
	{
		auto result = engine.CalculateExpression("5 - 2 + 11");
	}*/

	std::string line;
	while (true)
	{
		std::getline(std::cin, line);
		if (line.empty() || line.find_first_not_of(' ') == std::string::npos)
		{
			continue;
		}

		if (line == "Exit")
		{
			break;
		}

		try
		{
			auto result = engine.CalculateExpression(line);
			std::cout << "Result:=" << result << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	return EXIT_SUCCESS;
}