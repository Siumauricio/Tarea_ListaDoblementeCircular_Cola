#pragma once
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template<class T>
struct QueueNode {
	T dato;
	QueueNode *anterior;
	QueueNode *siguiente;
	QueueNode (T dato,QueueNode *siguiente,QueueNode *anterior) {
		this->dato = dato;
		this->siguiente = siguiente;
		this->anterior = anterior;
	}
};

template<class T>
class Queue {
private:
	int CantidadElementos;
	QueueNode<T> *primero;
	QueueNode<T> *ultimo;
public:
	Queue (void);
	void Enqueue (T);
	void Dequeue (void);
	bool isEmpty ();
	bool isFull (void);
	const T &Peek (void);
};
template<class T>
Queue<T>::Queue ():CantidadElementos (0),primero (nullptr),ultimo (nullptr) {}

template<class T>
bool Queue<T>::isEmpty (void) {
	return primero == nullptr;
}

template<class T>
void Queue<T>::Enqueue (T dato) {
	QueueNode<T> *nuevo = new QueueNode<T> (dato,nullptr,nullptr);
	if(isFull ()) {
		if(isEmpty ()) {
			primero = nuevo;
			ultimo = nuevo;
			primero->siguiente = ultimo;
			CantidadElementos++;
		} else {
			ultimo->siguiente = nuevo;
			nuevo->anterior = ultimo;
			nuevo->siguiente = primero;
			primero->anterior = nuevo;
			primero = nuevo;
			CantidadElementos++;
		}
	}
}
template<class T>
bool Queue<T>::isFull (void) {
	return CantidadElementos < 5;
}

template <class T>
const T &Queue<T>::Peek (void) {
	QueueNode<T> *actual = primero;
	return actual->dato;
}
template <class T>
void Queue<T>::Dequeue (void) {
	if(!isEmpty ()) {
		QueueNode<T> *actual = primero;
		primero = primero->siguiente;
		primero->anterior = ultimo;
		ultimo->siguiente = primero;
		delete actual;
	}
}

#endif 