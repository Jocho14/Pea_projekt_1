#pragma once
#include "Node.hpp"

class List {
public:
	//Konstruktor listy
	List();

	//Konstruktor kopiuj¹cy
	List(const List& other);

	//Destruktor listy
	~List();

	//WskaŸnik na pierwszy element listy
	Node* head;

	//WskaŸnik na ostatni element listy
	Node* tail;

	//Zmienna przechowuj¹ca rozmiar listy
	int count;

	//Dodawanie elementu do listy na wyznaczon¹ pozycjê
	void addValue(int index, int number);

	//Usuwanie elementu (jeœli istnieje) o podanej wartoœci na wejœcu z listy
	void deleteFromList(int number);
	
	//Wyœwietlanie zawartoœci listy
	void display();

	//Sprawdzenie czy dana wartoœæ znajduje siê w liœcie
	bool IsValueInList(int val);

	//Usuwanie z listy po indexie
	void deleteFromListByIndex(int index);

	// Zwracanie iloœci elementów listy
	int getSize();

	// Czyszczenie listy
	void clear();
};

