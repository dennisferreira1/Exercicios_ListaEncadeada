//
//  LinkedList.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include "Node.h"


typedef enum {
    OK ,
    HeadNull,
    TailNull,
    HeadPrevious,
    HeadNextNull,
    TailNext,
    TailPreviousNull,
    HeadTail,
    IncorrectLink
} ListStatus ;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int quantity;
    
public:
    LinkedList(void);
    ~LinkedList(void);

    Node<T>* getHead(void);
    Node<T>* getTail(void);
    
    T get(int);
    int search(T);
    
    bool insertEnd(T);
    bool insertBegin(T);
    bool insert(int, T);

    T removeEnd(void);
    T removeBegin(void);
    T remove(int);
    
    ListStatus checkConsistency(void);
    
    void print(void);
    
    bool isEmpty(void);
    int getQuantity(void);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = new Node<T>();
    this->tail = new Node<T>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // TO-DO
}

template <typename T>
Node<T>* LinkedList<T>::getHead(void)
{
    return this->head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail(void)
{
    return this->tail;
}

template <typename T>
int LinkedList<T>::getQuantity(void)
{
    return this->quantity;
}

template <typename T>
bool LinkedList<T>::isEmpty(void)
{
    return this->quantity == 0;
}

template <typename T>
T LinkedList<T>::get(int i)
{
    if( i < 1 || i > this->getQuantity())
    {
        std::cout << "Valor do índice de busca deve estar entre [1, quantity].\n";
        return "";
    }
    if( this->isEmpty() )
    {
        std::cout << "Não há elementos a serem retornados, pois lista está vazia.\n";
        return "";
    }
        
    int counter = 1;
    
    T result;
    for(Node<T>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        if( i == counter )
        {
            result = n->getValue();
            break;
        }
        counter++;
    }
    
    return result;
}

template <typename T>
int LinkedList<T>::search(T s)
{
    int index= 1;
    for(Node<T>* iter= this->head->getNext(); iter != this->tail; iter= iter->getNext()){
        if(iter->getValue() == s){
            return index;
        }

        index++;
    }

    //iter == tail --> percorreu todos os elementos
    return -1;
}

template <typename T>
bool LinkedList<T>::insertBegin(T s)
{
    Node<T>* novo= new Node<T>(s);

    novo->setPrevious(this->head);
    novo->setNext(this->head->getNext());

    novo->getNext()->setPrevious(novo);
    novo->getPrevious()->setNext(novo);

    this->quantity++;

    return true;
}

template <typename T>
bool LinkedList<T>::insertEnd(T s)
{

    Node<T>* novo= new Node<T>(s);

    novo->setNext(this->tail);
    novo->setPrevious(this->tail->getPrevious());

    novo->getPrevious()->setNext(novo);  //this->tail->getPrevious()->setNext(novo); ->também funciona
    novo->getNext()->setPrevious(novo);  //this->tail->setPrevious(novo); ->também funciona

    this->quantity++;

    return true;
}

template <typename T>
bool LinkedList<T>::insert(int i, T s)
{
    if(i == 1){
        return insertBegin(s);
    }
    else if(i > this->quantity){
        return insertEnd(s);
    }
    else{
        Node<T>* aux= this->head;
        int cont= 1;
        while(cont < i){
            aux= aux->getNext();
            cont++;
        }
        //cont == i
        Node<T>* novo= new Node<T>(s);
        novo->setNext(aux->getNext());
        novo->setPrevious(aux);

        novo->getNext()->setPrevious(novo);
        novo->getPrevious()->setNext(novo);
        this->quantity++;

        return true;
    }
}

template <typename T>
T LinkedList<T>::removeEnd(void)
{

    Node<T>* remover= this->tail->getPrevious();

    remover->getPrevious()->setNext(this->tail);
    remover->getNext()->setPrevious(remover->getPrevious());   //this->tail->setPrevious(remover->getPrevious()); ->também funciona
   
    T result= remover->getValue();

    delete remover;
    this->quantity--;

    return result;
}

template <typename T>
T LinkedList<T>::removeBegin(void)
{
   Node<T>* remover= this->head->getNext();

   remover->getNext()->setPrevious(this->head);
   remover->getPrevious()->setNext(remover->getNext()); //this->head->setNext(remover->getNext()) ->também funciona
   
   T result= remover->getValue();
   delete remover;
   this->quantity--; 

   return result;
}

template <typename T>
T LinkedList<T>::remove(int indice)
{
    if(indice == 1){
        return removeBegin();
    }
    else if(indice > this->quantity){
        return "Posicao inexistente";
    }
    else{
        Node<T>* remover= this->head;
        int cont= 1;
        while(cont < indice){
            remover= remover->getNext();
        }

        //cont == i 
        remover->getPrevious()->setNext(remover->getNext());
        remover->getNext()->setPrevious(remover->getPrevious());

        T result= remover->getValue();
        delete remover;
        this->quantity--;

        return result;
    }
}

template <typename T>
void LinkedList<T>::print(void)
{
    for(Node<T>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        std::cout << n->getValue() << " ";
    }
    std::cout << std::endl;
}

template <typename T>
ListStatus LinkedList<T>::checkConsistency()
{
    if( head == NULL )
    {
        return HeadNull;
    }
    else if( head->getNext() == NULL )
    {
        return HeadNextNull;
    }
    else if( head->getNext()->getPrevious() != head )
    {
        return IncorrectLink;
    }
    else if( head->getPrevious() != NULL )
    {
        return HeadPrevious;
    }
    
    if( tail == NULL )
    {
        return TailNull;
    }
    else if( tail->getPrevious() == NULL )
    {
        return TailPreviousNull;
    }
    else if( tail->getPrevious()->getNext() != tail )
    {
        return IncorrectLink;
    }
    else if( tail->getNext() != NULL )
    {
        return TailNext;
    }
    
    if(isEmpty())
    {
        if( head->getNext() != tail )
        {
            return HeadTail;
        }
        
        if( head != tail->getPrevious() )
        {
            return HeadTail;
        }
    }
    else
    {
        // Verifica encadeamento dos elementos
        for(Node<T>* i = head->getNext(); i != tail; i=i->getNext())
        {
            if( i->getNext()->getPrevious() != i )
            {
                return IncorrectLink;
            }
            if( i->getPrevious()->getNext() != i )
            {
                return IncorrectLink;
            }
        }
    }
    
    return OK;
}



#endif /* defined(__LinkedList__LinkedList__) */
