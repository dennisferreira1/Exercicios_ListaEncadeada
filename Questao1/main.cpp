#include <iostream>

#include "Sequence.h"

using namespace std;



template <typename T>
T aux_max(Node<T>* maior, Node<T>* comparado)
{

	if(comparado->getNext() == nullptr){
		return maior->getValue();
	}
	else if(comparado->getValue() > maior->getValue()){
		return aux_max(comparado, comparado->getNext());
	}
	else{
		return aux_max(maior, comparado->getNext());
	}

}

template <typename T>
T max(Sequence<T>* lista)
{
	return aux_max(lista->getFirst(), lista->getFirst()->getNext());
}


int main()
{
	Sequence<float>* lista= new Sequence<float>();

	float valores[]= {2.5,3.6,14.5,5.4,6.3,7.1,14.6,1.0};

	for(int i=0; i<8; i++){
		lista->insertBegin(valores[i]);
	}

	lista->insertBegin(15.9);
	
	cout<<"Elemento 1: "<<lista->get(1)<<endl;
	cout<<"Elemento 9: "<<lista->get(9)<<endl;

	cout<<"Maior valor da lista: "<< max(lista)<<endl<<endl;

	lista->removeBegin();

	cout<<"Elemento 1: "<<lista->get(1)<<endl;
	cout<<"Elemento 8: "<<lista->get(8)<<endl;
	

	cout<<"Maior valor da lista: "<< max(lista);

	return 0;

}