//
//  Sort.h
//  Aula-Ordenacao
//
//  Created by Eiji Adachi Medeiros Barbosa on 09/03/17.
//  Copyright © 2017 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include "LinkedList.h"

//template <typename T>
//LinkedList<T>* mergeSortList(LinkedList<T>* lista1, LinkedList<T>* lista2);

template <typename T>
LinkedList<T>* merge(LinkedList<T>* lista1, LinkedList<T>* lista2)
{
	return mergeSortList(lista1, lista2);
}

template <typename T>
LinkedList<T>* mergeSortList(LinkedList<T>* lista1, LinkedList<T>* lista2)
{
	// Nova lista para armazenar os nós das duas listas em ordem crescente
	LinkedList<T>* newList= new LinkedList<T>();
	// Ponteiro aux1 apontando para o primeiro nó após a cabeça da lista1
	Node<T>* aux1= lista1->getHead()->getNext();
	// Ponteiro aux2 apontando para o primeiro nó após a cabeça da lista2
	Node<T>* aux2= lista2->getHead()->getNext();

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


#endif /* Sort_hpp */

