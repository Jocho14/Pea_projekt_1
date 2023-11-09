#include "DPAlgorithm.hpp"
#include <limits>
#include <chrono>
#include <iostream>
#include <map>

using namespace std;

DPalgorithm::DPalgorithm()
{
    minCycle = nullptr;
}

DPalgorithm::~DPalgorithm()
{
}

void DPalgorithm::initialize(shared_ptr<Matrix>& matrix)
{
	this->dp.clear();
	this->next.clear();

    this->dp.resize(1 << matrix->getSize(), std::vector<int>(matrix->getSize(), -1));
    this->next.resize(1 << matrix->getSize(), std::vector<int>(matrix->getSize(), -1));
    this->minCycle = make_shared<List>();
}

void DPalgorithm::displayMinCycle()
{
    minCycle->display();
}

int DPalgorithm::findMinCost(int mask, int currentCity, shared_ptr<Matrix>& matrix) {
    // Base case
    if (mask == (1 << matrix->getSize()) - 1) {
        return (*matrix)[currentCity][0];
    }
    // Check memoization table
    if (dp[mask][currentCity] != -1) {
        return dp[mask][currentCity];
    }
    // Recursive case
    int ans = INT_MAX;
    for (int city = 0; city < matrix->getSize(); city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = (*matrix)[currentCity][city] + findMinCost(mask | (1 << city), city, matrix);
            if (newAns < ans) {
                ans = newAns;
                next[mask][currentCity] = city;
            }
        }
    }
    dp[mask][currentCity] = ans;
    return ans;
}

int DPalgorithm::run(std::shared_ptr<Matrix>& matrix) {
    initialize(matrix);
    int minCost = findMinCost(1, 0, matrix);
    // Reconstruct the path
    int mask = 1;
    int pos = 0;
    while (mask != (1 << matrix->getSize()) - 1) {
        minCycle->addValue(minCycle->getSize(), pos);
        pos = next[mask][pos];
        mask |= (1 << pos);
    }
    minCycle->addValue(minCycle->getSize(), pos); // dodanie koñcowego wierzcho³ka
    minCycle->addValue(minCycle->getSize(), 0); // dodanie poczatkowego wierzcho³ka
    return minCost;
}

void DPalgorithm::showOptions()
{
	cout << "\n--- PROGRAMOWANIE DYNAMICZNE (DP) ---\n";
	cout << "--------------------------------------------\n";
	cout << "1. Wczytaj dane z pliku\n";
	cout << "2. Wygeneruj dane losowo\n";
	cout << "3. Wyswietl ostatnio wczytane lub wygenerowane dane\n";
	cout << "4. Uruchom algorytm\n";
	cout << "5. Wyjdz\n\n";
	//cout << "6. Testuj";

	cout << "Wprowadz nr opcji: ";
}

void DPalgorithm::showMenu()
{
	auto matrix = std::make_shared<Matrix>();

	chrono::high_resolution_clock::time_point TimeStart;
	chrono::high_resolution_clock::time_point TimeEnd;
	int time = 0;
	int result = 0;
	int matrixSize;
	

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
			initialize(matrix);

			cout << endl;

			TimeStart = std::chrono::high_resolution_clock::now();
			result = run(matrix);
			TimeEnd = std::chrono::high_resolution_clock::now();

			time = chrono::duration_cast<chrono::milliseconds>(TimeEnd - TimeStart).count();

			cout << "Waga najkrotszego cyklu: " << result << endl;
			cout << "Cykl: ";  minCycle->display(); cout << endl;
			cout << "Czas wykonania: " << time << "ms\n\n";

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