#include <iostream>

#include "Sequence.h"

using namespace std;



template <typename T>
T aux_sum(Node<T>* node, T soma)
{

	if(node == nullptr){
		return soma;
	}
	else{
		return aux_sum(node->getNext(), soma + node->getValue());
	}

}

template <typename T>
T sum(Sequence<T>* lista)
{
	return aux_sum(lista->getFirst(), 0.0f);
}


int main()
{
	Sequence<float>* lista= new Sequence<float>();

	float valores[]= {2.5,3.6,5.4,6.3,7.1,14.6,1.5};
	int tamanho= sizeof(valores)/sizeof(float);

	for(int i=0; i < tamanho; i++){
		lista->insertBegin(valores[i]);
	}

	cout<<"Soma dos valores da lista: "<< sum(lista);

	return 0;

}