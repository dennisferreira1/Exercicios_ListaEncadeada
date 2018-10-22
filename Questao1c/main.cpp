#include <iostream>

#include "Sequence.h"

using namespace std;



template <typename T>
int aux_countMin(Node<T>* node, T x, int cont)
{

	if(node == nullptr){
		return cont;
	}
	else if(node->getValue() < x){
		return aux_countMin(node->getNext(), x, ++cont);
	}
	else{
		return aux_countMin(node->getNext(), x, cont);
	}

}

template <typename T>
int countMin(Sequence<T>* lista, T x)
{
	return aux_countMin(lista->getFirst(), x, 0);
}


int main()
{
	Sequence<float>* lista= new Sequence<float>();

	float valores[]= {2.5,3.6,5.4,6.3,7.1,14.6,1.5};
	int tamanho= sizeof(valores)/sizeof(float);

	for(int i=0; i < tamanho; i++){
		lista->insertBegin(valores[i]);
	}

	float x= 5.5;

	cout<<"Quantidade de elementos menores que "<<x<<": "<< countMin(lista, x);

	return 0;

}