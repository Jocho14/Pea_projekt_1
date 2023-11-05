// Main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <memory>
#include "Matrix.hpp"
#include "List.hpp"
#include "BFalgorithm.hpp"

using namespace std;

int main()
{
	auto bfAlgorithm = make_shared<BFalgorithm>();

	bfAlgorithm->showMenu();

	return 0;
}
