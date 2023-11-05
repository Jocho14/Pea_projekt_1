#include "BFalgorithm.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>

BFalgorithm::BFalgorithm()
{
	minCycleWeight = INT_MAX;	// pocz�tkowa waga minimalnego cyklu r�wna niesko�czono��
	minCycle = nullptr;
	numberOfCities = 0;
}

BFalgorithm::~BFalgorithm()
{
	clear();
}

int BFalgorithm::run(const shared_ptr<Matrix>& matrix)
{	
	
	if (matrix->getSize() < 1) {					// Przypadek, gdy macierz nie istnieje
		minCycle->clear();
		return -1;
	} 

	minCycleWeight = INT_MAX;					// Ustawienie minimalnego cyklu na niesko�czono��
	numberOfCities = matrix->getSize();
						
	const int startCity = 0;						// Ustawienie pocz�tkowego miasta na 0

	bool* visited      = new bool[numberOfCities]();		// Stworzenie tablicy odwiedzonych miast zainicjalizowane warto�ciami false
	visited[startCity] = true;						// Ustawienie pocz�tkowego miasta na odwiedzone

	auto currentPath = make_shared<List>();		// Stworzenie aktualnej �cie�ki
	currentPath->addValue(0, startCity);	    // Ustawienie pocz�tkowego miasta jako 1 element w li�cie

	int pathWeightResult = DFS(startCity, startCity, visited, 0, currentPath, matrix);// Uruchomienie algorytm DFS

	delete[] visited;
	return pathWeightResult;
}

int BFalgorithm::DFS(int startCity, int currentCity, bool visited[], int currentPathWeight, shared_ptr<List>& currentPath, const shared_ptr<Matrix>& matrix)
{
	//if (currentPathLength > minPathWeight) { // Je�li na dowolnym etapie aktualna �cie�ka jest d�u�sza ni� najkr�tsza �cie�ka -
	//	return INT_MAX;	  // - nie kontynuujemy dalszego przeszukiwania �cie�ki
	//}
	bool allVisited = true;				// Za�o�enie, �e wszystkie miasta zosta�y odwiedzone

	for (int city = 0; city < numberOfCities; city++)
	{
		if (!visited[city])
		{
			allVisited	  = false;			// zmiana statusu wszystkich odwiedzonych na false
			visited[city] = true;		// ustawiamy miasto na odwiedzone
		
			currentPath->addValue(currentPath->count, city); // dodanie miasta nowego do aktualnej �cie�ki
			
			int newPathLength = DFS(startCity, city, visited, currentPathWeight + (*matrix)[currentCity][city], currentPath, matrix);

			currentPath->deleteFromListByIndex(currentPath->count - 1); // Usu� miasto z bie��cej �cie�ki
			visited[city] = false;							// Ustaw miasto na nieodwiedzone, tak aby algorytm bada� inne �cie�ki przechodz�ce przez dane miasto
		}
	}
	if (allVisited) {
		int newCycleWeight = currentPathWeight + (*matrix)[currentCity][startCity];	// obliczenie wagi ca�ego cyklu 
		currentPath->addValue(currentPath->count, startCity);						// Dodanie pocz�tkowego miasta do cyklu

		if (newCycleWeight < minCycleWeight) {						// Sprawdzenie czy waga nowego cyklu jest mniejsza ni� waga najmniejszego cyklu
			minCycle       = make_shared<List>(*currentPath);
			minCycleWeight = newCycleWeight;
		}

		currentPath->deleteFromListByIndex(currentPath->count - 1);				// Usuni�cie pocz�tkowego miasta z aktualnej �cie�ki
		return newCycleWeight;													// Zwr�cenie wagi nowego cyklu
	}
	return minCycleWeight;
}

void BFalgorithm::clear()
{
	return;
}

void BFalgorithm::showOptions()
{
	cout << "\n--- ALGROTYM PRZEGLADU ZUPELNEGO (BRUTE FORCE) ---\n";
	cout << "--------------------------------------------\n";
	cout << "1. Wczytaj dane z pliku\n";
	cout << "2. Wygeneruj dane losowo\n";
	cout << "3. Wyswietl ostatnio wczytane lub wygenerowane dane\n";
	cout << "4. Uruchom algorytm\n";
	cout << "5. Wyjdz\n\n";
	//cout << "6. Testuj";

	cout << "Wprowadz nr opcji: ";
}

void BFalgorithm::showMenu()
{
	auto matrix = std::make_shared<Matrix>();
	int matrixSize;

	chrono::high_resolution_clock::time_point TimeStart;
	chrono::high_resolution_clock::time_point TimeEnd;
	int time = 0;
	int path = 0;

	int opt;
	string fileName;
	do
	{
		showOptions();
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("CLS");
			cout << "Podaj nazwe pliku: ";
			cin >> fileName;
			matrix->clear();

			matrix->loadFromFile(fileName);
			matrix->display();

			cout << endl;
			break;

		case 2:
			system("CLS");
			cout << "Podaj rozmiar macierzy: ";
			cin >> matrixSize;

			matrix->generateRandomData(matrixSize, 1, 20);
			matrix->display();

			cout << endl;
			break;

		case 3:
			system("CLS");
			matrix->display();
			
			cout << endl;
			break;

		case 4:
			system("CLS");
			matrix->display();

			cout << endl;

			TimeStart = std::chrono::high_resolution_clock::now();
			path = run(matrix);
			TimeEnd = std::chrono::high_resolution_clock::now();

			time = chrono::duration_cast<chrono::milliseconds>(TimeEnd - TimeStart).count();

			std::cout << "Waga najkrotszego cyklu: " << path << endl;
			std::cout << "Cykl: ";  minCycle->display(); std::cout << endl;
			std::cout << "Czas wykonania: " << time <<"ms\n\n";
			break;

		case 5:
			return;

		default:
			system("CLS");
			cout << "Niepoprawny nr opcji";
			break;
		}
	} while (opt != 5);
}

int BFalgorithm::getMinPathWeight()
{
	return minCycleWeight;
}

List BFalgorithm::getMinPath()
{
	return *minCycle;
}