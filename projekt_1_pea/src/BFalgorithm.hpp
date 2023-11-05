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

	// Metoda uruchamiaj¹ca algorytm przegl¹du zupe³nego (Brut Force)
	int run(const shared_ptr<Matrix>& matrix);

	// Metoda przeszukiwania grafu w g³¹b
	int DFS(int currentCity, int startCity, bool visited[],
		int currentPathLength, shared_ptr<List>& currentPath, const shared_ptr<Matrix>& matrix);

	// Metoda czyszcz¹ca pola klasy
	void clear();

	// Metoda zwracaj¹ca wagê nakrótszej drogi
	int getMinPathWeight();

	// Metoda zwracaj¹ca najkrótsz¹ drogê w postaci listy
	List getMinPath();

	// Metoda obs³uguj¹ca akcje wykonan¹ przez u¿ytkownika
	void showMenu();

	// Metoda wyœwietlaj¹ca menu kontekstowe algorytmu
	void showOptions();
};