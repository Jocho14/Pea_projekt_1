#pragma once
#include "Node.hpp"

class List {
public:
	//Konstruktor listy
	List();

	//Konstruktor kopiuj�cy
	List(const List& other);

	//Destruktor listy
	~List();

	//Wska�nik na pierwszy element listy
	Node* head;

	//Wska�nik na ostatni element listy
	Node* tail;

	//Zmienna przechowuj�ca rozmiar listy
	int count;

	//Dodawanie elementu do listy na wyznaczon� pozycj�
	void addValue(int index, int number);

	//Usuwanie elementu (je�li istnieje) o podanej warto�ci na wej�cu z listy
	void deleteFromList(int number);
	
	//Wy�wietlanie zawarto�ci listy
	void display();

	//Sprawdzenie czy dana warto�� znajduje si� w li�cie
	bool IsValueInList(int val);

	//Usuwanie z listy po indexie
	void deleteFromListByIndex(int index);

	// Zwracanie ilo�ci element�w listy
	int getSize();

	// Czyszczenie listy
	void clear();
};

