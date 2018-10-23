#include "Sort.hpp"

using namespace std;

template <typename T>
LinkedList<T>* intercalar(LinkedList<T>* lista1, LinkedList<T>* lista2);

template <typename T>
LinkedList<T>* sortList(LinkedList<T>* lista1, LinkedList<T>* lista2)
{
	return intercalar(lista1, lista2);
}

template <typename T>
LinkedList<T>* intercalar(LinkedList<T>* lista1, LinkedList<T>* lista2)
{
	// Nova lista para armazenar os nós das duas listas em ordem crescente
	LinkedList<T>* newList= new LinkedList<T>();
	// Ponteiro aux1 apontando para o primeiro nó após a cabeça da lista1
	Node<string>* aux1= lista1->getHead()->getNext();
	// Ponteiro aux2 apontando para o primeiro nó após a cabeça da lista2
	Node<string>* aux2= lista1->getHead()->getNext();

	while(aux1 != lista1->getTail() && aux2 != lista2->getTail())
	{
		if(aux1->getValue() <= aux2->getValue()){
			newList->insertEnd(aux1->getValue());
			aux1= aux1->getNext();
		}
		else{
			newList->insertEnd(aux2->getValue());
			aux2= aux2->getNext();
		}
	}

	while(aux1 != lista1->getTail())
	{
		newList->insertEnd(aux1->getValue());
		aux1= aux1->getNext();
	}

	while(aux2 != lista2->getTail())
	{
		newList->insertEnd(aux2->getValue());
		aux2= aux2->getNext();
	}

	return newList;
}