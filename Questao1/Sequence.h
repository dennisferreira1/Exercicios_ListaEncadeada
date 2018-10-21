//
//  Sequence.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __Sequence__Sequence__
#define __Sequence__Sequence__

#include "Node.h"

template <typename T>
class Sequence
{
private:
    Node<T> *first;
    int quantity;
    
public:
    Sequence();
    
    ~Sequence();

    Node<T>* getFirst();
    
    /**
     Returns the i-th element in this sequence.
     */
   T get(int i);
    
    /**
     Inserts the element in this sequence. After inserting, the element must be in the i-th position.
     */
    void insert(int i, T element);
    
    /**
     Inserts the element in the begin of this sequence.
     */
    void insertBegin(T element);
    
    /**
     Inserts the element in the end position of this sequence.
     */
    void insertEnd(T element);
    
    /**
     Removes the element in the i-th position of this sequence.
     Returns the removed element.
     */
    T remove(int i);
    
    /**
     Removes the element in begin of this sequence.
     Returns the removed element.
     */
    T removeBegin();
    
    /**
     Removes the element in begin of this sequence.
     Returns the removed element.
     */
    T removeEnd();
    
    /**
     Checks whether the sequence is empty or not.
     */
    bool isEmpty();
    
    /**
     Returns the quantity of elements in the sequence.
     */
    int getQuantity();
};

template <typename T>
Sequence<T>::Sequence()
{
    first = NULL;
    this->quantity = 0;
}

template <typename T>
Sequence<T>::~Sequence()
{
    // TO - DO
}
template <typename T>
Node<T>* Sequence<T>::getFirst(){
    return this->first;
}

/**
 Returns the i-th element in this sequence.
 */
template <typename T>
T Sequence<T>::get(int i)
{
    Node<T>* curr = first;
    int counter = 1;
    
    while( curr!= NULL && counter < i )
    {
        curr = curr->getNext();
        counter++;
    }
    
    return curr->getValue();
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
template <typename T>
void Sequence<T>::insert(int i, T element)
{
  
    if(i == 1){
        insertBegin(element);
    }
    else if(i == this->quantity){
        insertEnd(element);
    }
    else{
        Node<T>* aux= first;
        for(int cont=0; cont<i-2; cont++)
        {
            aux= aux->getNext();
        }
        Node<T>* novo= new Node<T>(element);
        novo->setNext(aux->getNext());
        aux->setNext(novo);

        quantity++;
    }
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
template <typename T>
void Sequence<T>::insertBegin(T element)
{
    
    Node<T>* novo= new Node<T>(element);
    novo->setNext(this->first);
    this->first= novo;
    ++this->quantity;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
template <typename T>
void Sequence<T>::insertEnd(T element)
{
    // TO - DO
    if(quantity == 0){

        insertBegin(element);

    }
    else{

        Node<T>* aux= this->first;
        while(aux->getNext()!= nullptr)
        {
            aux= aux->getNext();

        } 
        Node<T>* novo= new Node<T>(element);
        novo->setNext(nullptr);
        aux->setNext(novo);
        ++this->quantity;
    }

}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
template <typename T>
T Sequence<T>::remove(int i)
{
    if(i == 1){
        return removeBegin();
    }
    else if(i == this->quantity){
        return removeEnd();
    }
    else{

        Node<T>* auxToRemove= this->first;
        Node<T>* aux= nullptr;
        for(int cont= 0; cont<i-1; cont++){
            aux= auxToRemove;
            auxToRemove= auxToRemove->getNext();
        }
            aux->setNext(auxToRemove->getNext());
            T result= auxToRemove->getValue();

            --this->quantity;
            delete auxToRemove;

        return result;
    }
   
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
template <typename T>
T Sequence<T>::removeBegin()
{
    T result=0;
    if(isEmpty()){
        return result;
    }
    else{
        Node<T>* auxToRemove= this->first;
        result= auxToRemove->getValue();
        
        this->first= first->getNext();

        delete auxToRemove;
        --this->quantity;

    }   
 return result;
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
template <typename T>
T Sequence<T>::removeEnd()
{
  
    if(isEmpty()){
       return 0; 
    }
    else if(this->quantity == 1){
    
       return removeBegin();

    }
    else{
        Node<T>* ultimo= this->first;
        Node<T>* penultimo= nullptr;

        while(ultimo->getNext() != nullptr){
            penultimo= ultimo;  
            ultimo= ultimo->getNext(); 
        }
        //ultimo->getNext == nullptr
        T result= ultimo->getValue();
        delete ultimo;
        --this->quantity;
         penultimo->setNext(nullptr);

         return result;

   }
 
}
template <typename T>
bool Sequence<T>::isEmpty()
{
    return this->getQuantity()==0;
}
template <typename T>
int Sequence<T>::getQuantity()
{
    return this->quantity;
}


#endif /* defined(__Sequence__Sequence__) */
