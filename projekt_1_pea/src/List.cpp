#include "List.hpp"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

List::List() {
    List::head = nullptr;
    List::tail = nullptr;
    List::count = 0;
}

List::List(const List& other) {
    head = nullptr;
    tail = nullptr;
    count = 0;

    Node* tempOther = other.head;
    while (tempOther) {
        this->addValue(count, tempOther->nodeVal);
        tempOther = tempOther->next;
    }
}

List::~List() {
    Node* temp = head;
    while (temp) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void List::clear()
{
    if (count < 1)
    {
        head = nullptr;
        tail = nullptr;
    }

    if (head == nullptr) return;
   
    Node* temp = head;
    while (temp) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void List::addValue(int index, int number) {
    //Sprawdzenie czy indeks mieœci siê w przedziale [0, size]
    if (index > count || index < 0) {
        cout << "index out of range";
    }
    //Przypadek kiedy lista jest pusta
    else if (head == nullptr) {
        Node* newNode = new Node;
        newNode->nodeVal = number;
        head = newNode;
        tail = newNode;

        count++;
    }
    else {
        //Dodanie elementu na pocz¹tek listy
        if (index == 0) {
            //Stworzenie nowego elementu, do którego zostanie przypisana podana na wejœciu wartoœæ 
            Node* newNode = new Node;
            newNode->nodeVal = number;

            newNode->next = head; //przypisanie nastêpnika nowego elementu na aktualnie pierwszy element
            head->prev = newNode; //ustawienie poprzednika aktualnego pierwszego elementu jako nowy element
            head = newNode; //ustawienie pierwszego elementu jako nowy element

            count++;

        }
        //Dodanie elementu na koniec listy
        else if (index == count) {
            Node* newNode = new Node;
            newNode->nodeVal = number;

            newNode->prev = tail; //ustawienie poprzednika nowego elementu na aktualnie ostatni element
            tail->next = newNode; //ustawienie nastêpnika aktualnie ostatniego elementu na nowy element
            tail = newNode; //ustawienie ostatniego elementu jako nowy element

            count++;
        }

        else {
            if (count > 0) {
                Node* newNode = new Node;
                newNode->nodeVal = number;

                Node* leftNodeNeigh = head;

                int i = 0;
                while (leftNodeNeigh) {
                    if (i + 1 == index) {
                        break;
                    }
                    leftNodeNeigh = leftNodeNeigh->next;
                    i++;
                }

                Node* rightNodeNeigh = leftNodeNeigh->next;

                newNode->prev = leftNodeNeigh;
                newNode->next = rightNodeNeigh;

                leftNodeNeigh->next = newNode;
                rightNodeNeigh->prev = newNode;

                count++;
            }
        }
    }
}

void List::deleteFromList(int number) {
    if (head != nullptr) {
        Node* tempNode = head;

        while (tempNode) {
            if (tempNode->nodeVal == number) {
                break;
            }
            tempNode = tempNode->next;
        }

        if (tempNode != nullptr) {
            if (tempNode == head) {
                head = tempNode->next;
            }
            if (tempNode == tail) {
                tail = tempNode->prev;
            }
            if (tempNode->prev != nullptr) {
                //zmiana wskaŸnika nastêpuj¹cego po poprzednim elemencie na nastêpnik elementu usuwanego
                tempNode->prev->next = tempNode->next;
            }
            if (tempNode->next != nullptr) {
                //zmiana wskaŸnika poprzedzaj¹cego nastêpny element na poprzednik elementu usuwanego
                tempNode->next->prev = tempNode->prev;
            }

            delete tempNode;
            count--;
        }
    }
}

bool List::IsValueInList(int val) {
    Node* tempNode = head;
    while (tempNode) {
        if (tempNode->nodeVal == val) {
            return true;
        }
        tempNode = tempNode->next;
    }
    return false;
}

void List::display() {

    cout << endl;
    if (head == nullptr) return;
    Node* temp = head;

    while (temp) {
        cout << temp->nodeVal;
        temp != tail ? cout << " -> " : cout << "";
        temp = temp->next;
    }
}

int List::getSize()
{
    Node* temp = head;
    int size = 0;

    while (temp) {
        temp = temp->next;
        size++;
    }
    
    return size;
}

void List::deleteFromListByIndex(int index) {
    if (head != nullptr) {
        Node* tempNode = head;

        if (index == count - 1) {
            tempNode = tail;
        }

        else if (index == 0) {
            tempNode = head;
        }

        else {
            for (int i = 0; i < index; i++) {
                tempNode = tempNode->next;
            }
        }

        if (tempNode != nullptr) {
            if (tempNode == head) {
                head = tempNode->next;
            }
            if (tempNode == tail) {
                tail = tempNode->prev;
            }
            if (tempNode->prev != nullptr) {
                //zmiana wskaŸnika nastêpuj¹cego po poprzednim elemencie na nastêpnik elementu usuwanego
                tempNode->prev->next = tempNode->next;
            }
            if (tempNode->next != nullptr) {
                //zmiana wskaŸnika poprzedzaj¹cego nastêpny element na poprzednik elementu usuwanego
                tempNode->next->prev = tempNode->prev;
            }

            delete tempNode;
            count--;
        }
    }
}
