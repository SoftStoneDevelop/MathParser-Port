#include <cstdlib>
#include <iostream>
#include "Algorithms/ShuntingYardAlgorithm.hpp"
#include "Records/ChunkExpression.hpp"

int main()
{
	std::cout << "Hello bich\n";
	auto chars = new char[]{'s', ' '};
	std::queue<MathEngine::ChunkExpression*>* queue = new std::queue<MathEngine::ChunkExpression*>();
	MathEngine::ShuntingYardAlgorithm::ToRVNOpt(&chars[0], 2, *queue);

	delete[] chars;
	delete queue;

	return EXIT_SUCCESS;
}