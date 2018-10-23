#include "sort.hpp"
#include "LinkedList.h"

#include <iostream>

using namespace std;

int main(){
	LinkedList<int>* lista1= new LinkedList<int>();
	LinkedList<int>* lista2= new LinkedList<int>();
	
	lista1->insertBegin(3);
	lista1->insertBegin(5);
	lista1->insertBegin(8);

	lista2->insertBegin(2);
	lista2->insertBegin(6);
	lista2->insertBegin(9);

	LinkedList<int>* lista3= sortList(lista1, lista2);

	cout<<"Lista 1: ";
	lista1->print();
	cout<<"Lista 2: ";
	lista2->print();
	cout<<"Lista 3: ";
	lista3->print();


	return 0;

}