#pragma once
#include "Matrix.hpp"
#include "List.hpp"
#include <memory>

using namespace std;

class BFalgorithm
{
private:
	// waga minimalnego cyklu
	int minCycleWeight;

	// Liczba miast
	int numberOfCities;

	// cykl o minimalnej wadze
	shared_ptr<List> minCycle;

public:
	// Konstruktor 
	BFalgorithm();

	// Destruktor
	~BFalgorithm();

	// Metoda uruchamiaj�ca algorytm przegl�du zupe�nego (Brut Force)
	int run(const shared_ptr<Matrix>& matrix);

	// Metoda przeszukiwania grafu w g��b
	int DFS(int currentCity, int startCity, bool visited[],
		int currentPathLength, shared_ptr<List>& currentPath, const shared_ptr<Matrix>& matrix);

	// Metoda czyszcz�ca pola klasy
	void clear();

	// Metoda zwracaj�ca wag� nakr�tszej drogi
	int getMinPathWeight();

	// Metoda zwracaj�ca najkr�tsz� drog� w postaci listy
	List getMinPath();

	// Metoda obs�uguj�ca akcje wykonan� przez u�ytkownika
	void showMenu();

	// Metoda wy�wietlaj�ca menu kontekstowe algorytmu
	void showOptions();
};