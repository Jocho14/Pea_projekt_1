#pragma once
#include "List.hpp"
#include "Matrix.hpp"
#include <memory>
#include <vector>

using namespace std;

class DPalgorithm {
private:
    // List zawieraj¹ca minimalny cykl
    shared_ptr<List> minCycle;

    // Wektor zapamiêtuj¹cy œcie¿ki
    vector<vector<int>> dp;

    // Wektor rekonstruktuj¹cy minimalny cykl
    vector<vector<int>> next;

    // Metoda znajduj¹ca minimalny koszt
    int findMinCost(int mask, int pos, shared_ptr<Matrix>& matrix);

public:
    // Konstruktor
    DPalgorithm();

    // Destruktor
    ~DPalgorithm();

    // Metoda inicjalizuj¹ca sk³adowe klasy w zale¿noœci od podanego grafu
    void initialize(shared_ptr<Matrix>& matrix);

    // Metoda uruchamiaj¹ca algorytm
    int run(shared_ptr<Matrix>& matrix);

    // Metoda wyœwietlaj¹ca minimalny cykl
    void displayMinCycle();

    void showMenu();

    void showOptions();
};
