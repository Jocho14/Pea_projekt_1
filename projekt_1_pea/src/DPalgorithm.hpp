#pragma once
#include "List.hpp"
#include "Matrix.hpp"
#include <memory>
#include <vector>

using namespace std;

class DPalgorithm {
private:
    // List zawieraj�ca minimalny cykl
    shared_ptr<List> minCycle;

    // Wektor zapami�tuj�cy �cie�ki
    vector<vector<int>> dp;

    // Wektor rekonstruktuj�cy minimalny cykl
    vector<vector<int>> next;

    // Metoda znajduj�ca minimalny koszt
    int findMinCost(int mask, int pos, shared_ptr<Matrix>& matrix);

public:
    // Konstruktor
    DPalgorithm();

    // Destruktor
    ~DPalgorithm();

    // Metoda inicjalizuj�ca sk�adowe klasy w zale�no�ci od podanego grafu
    void initialize(shared_ptr<Matrix>& matrix);

    // Metoda uruchamiaj�ca algorytm
    int run(shared_ptr<Matrix>& matrix);

    // Metoda wy�wietlaj�ca minimalny cykl
    void displayMinCycle();

    void showMenu();

    void showOptions();
};
