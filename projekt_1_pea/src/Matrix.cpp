#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Matrix::Matrix() 
	: size(0), matrix(nullptr) 
{
}

Matrix::Matrix(const int size_)
	: size(size_)
{
	matrix = new int* [size_];
	for (int i = 0; i < size_; i++)
	{
		matrix[i] = new int[size_];
	}

	// inicjalizacja macierzy warto�ci� pocz�tkow� -1
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = -1;
		}
	}
}

Matrix::~Matrix()
{
	clear();
}

void Matrix::loadFromFile(const string& fileName_)
{
	ifstream userDataFile; 

	userDataFile.open(fileName_);

	if (!userDataFile) {
		cout << "Nie mozna otworzyc pliku: " << fileName_ << endl;
		return;  
	}

	int newSize;
	userDataFile >> newSize; // wczytanie wielko�ci macierzy z 1 linii z pliku

	int** newMatrix = new int*[newSize];

	// inicjalizacja macierzy danymi z pliku
	for (int i = 0; i < newSize; i++)
	{
		newMatrix[i] = new int[newSize];
		for (int j = 0; j < newSize; j++)
		{
			userDataFile >> newMatrix[i][j];
		}
	}

	// Czyszczenie dotychczasowej macierzy
	clear();

	// Przypisanie nowej macierzy do sk�adowej pola klasy wskazuj�cej na macierz
	matrix = newMatrix;
	size = newSize;

	userDataFile.close();
}

void Matrix::generateRandomData(const int size_, const int minValue, const int maxValue)
{
	int** newMatrix = new int* [size_];

	for (int i = 0; i < size_; i++)
	{
		newMatrix[i] = new int[size_];
		for (int j = 0; j < size_; j++)
		{
			if (i == j)
			{
				newMatrix[i][j] = -1; // Ustawienie warto�ci elementu na -1 w przypdaku, gdy jest to element le��cy na przek�tnej macierzy
			}
			else
			{
				newMatrix[i][j] = rand() % (maxValue - minValue + 1) + minValue; //przypisanie losowej warto�ci do nowego elementu macierzy
			}
			 
		}
	}

	// czyszczenie dotychczasowej macierzy
	clear();

	// Pzrypisanie nowej macierzy do sk�adowej pola klasy wskazuj�cej na macierz
	matrix = newMatrix;
	size = size_;
}

void Matrix::clear()
{
	if (matrix == nullptr)
	{
		return;
	}

	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = nullptr;
	size = 0;
}

int* Matrix::operator[](int index)
{
	return matrix[index];
}

int Matrix::getSize()
{
	return size;
}

void Matrix::display()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}