#pragma once
#include "List.hpp"
#include "Matrix.hpp"
#include <memory>
#include <vector>

using namespace std;

class DPalgorithm {
private:
    // List zawierająca minimalny cykl
    shared_ptr<List> minCycle;

    // Wektor zapamiętujący ścieżki
    vector<vector<int>> dp;

    // Wektor rekonstruktujący minimalny cykl
    vector<vector<int>> next;

    // Metoda znajdująca minimalny koszt
    int findMinCost(int mask, int pos, shared_ptr<Matrix>& matrix);

public:
    // Konstruktor
    DPalgorithm();

    // Destruktor
    ~DPalgorithm();

    // Metoda inicjalizująca składowe klasy w zależności od podanego grafu
    void initialize(shared_ptr<Matrix>& matrix);

    // Metoda uruchamiająca algorytm
    int run(shared_ptr<Matrix>& matrix);

    // Metoda wyświetlająca minimalny cykl
    void displayMinCycle();

    void showMenu();

    void showOptions();
};
