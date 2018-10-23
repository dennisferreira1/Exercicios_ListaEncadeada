#include <iostream>

#include "Sequence.h"
#include "Node.h"

using namespace std;


template <typename T>
void aux_invert(Node<T>* ultimo, Node<T>* penultimo){
	if(ultimo == nullptr){
		return;	
	}
	else{
		aux_invert(ultimo->getNext(), ultimo);

		ultimo->setNext(penultimo);
	}
}

template <typename T>
void invert(Sequence<T>* lista){
	aux_invert(lista->getFirst(), nullptr);
}



int main(){

	Sequence<int>* lista= new Sequence<int>();

	int valores[]= {1,2,3,4,5};
	int tamanho= sizeof(valores)/sizeof(int);

	for(int i= 0; i < tamanho; i++){
		lista->insertEnd(valores[i]);
	}

	for(Node<int>* i= lista->getFirst(); i!=nullptr; i= i->getNext()){
		cout<<i->getValue()<<"-->";
	}

	invert(lista);
	cout<<endl;

	for(Node<int>* i= lista->getFirst(); i!=nullptr; i= i->getNext()){
		cout<<i->getValue()<<"-->";
	}

	return 0;

}