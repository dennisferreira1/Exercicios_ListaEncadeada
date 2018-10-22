#include <iostream>

#include "Sequence.h"

using namespace std;


template <typename T>
void aux_invert(Sequence<T>* lista, int quantidade){
	if(quantidade != 0){
		lista->insertEnd(lista->remove(quantidade));
		aux_invert(lista, --quantidade);
	}
}

template <typename T>
void invert(Sequence<T>* lista){
	aux_invert(lista, lista->getQuantity());
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