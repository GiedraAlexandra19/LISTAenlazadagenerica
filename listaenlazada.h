#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "Iterador.h"

using namespace std;
template<typename J>
class Listaenlazada {
private:
    Nodo<J>* head;
    int dim;
public:
    Listaenlazada();
    Listaenlazada(J data);
    int Size();
    void Anadir(J data);
    void fill_random(int dim);
    void Eliminar(J data);
    
    void pushBack(J);
    void pushFront(J);
    void popBack();
    void popFront();

    void print();

    Nodo<J>* begin();
    Nodo<J>* end();
    
    ~Listaenlazada();
};

//Constructores
template<typename J>
Listaenlazada<J>::Listaenlazada() {
    head = nullptr;
    dim = 0;
}
template<typename J>
Listaenlazada<J>::Listaenlazada(J data) {
    head = new Nodo<J>(data);
    dim = 1;
}

//Métodos
template<typename J>
int Listaenlazada<J>::Size() {
    return dim;
}
template<typename J>
void Listaenlazada<J>::Anadir(J data) {
    if (head == nullptr) {
        head = new Nodo<J>(data);
    }
    else {
        Nodo<J>* tmp;
        tmp = head;
        while (tmp->Devolver() != nullptr) {
            tmp = tmp->Devolver();
        }
        tmp->Siguiente(data);
    }
    dim++;
}

//Anadir aleatoriamente
template<typename J>
void Listaenlazada<J>::fill_random(int dim){
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        Anadir(rand() % 100);
    }
}

//eliminar elemento
template<typename J>
void Listaenlazada<J>::Eliminar(J data) {
    if (dim > 0) {
        if (head->Devolver1() == data) {
            if (dim > 1) {
                Nodo<J>* tmp;
                tmp = new Nodo<J>(*(head->Devolver()));
                delete head;
                head = tmp;
            }
            else {
                delete head;
                head = nullptr;
            }
        }
        else {
            Nodo<J>* tmp;
            tmp = head;
            while (tmp->Devolver()->Devolver1() != data) {
                tmp = tmp->Devolver();
            }
            if (tmp->Devolver()->Devolver() != nullptr) {
                Nodo<J>* tmp2;
                tmp2 = new Nodo<J>(*(tmp->Devolver()->Devolver()));
                delete tmp->Devolver();
                *(tmp->Devolver()) = *tmp2;
            }
            else {
                delete tmp->Devolver();
            }
        }
        dim--;
    }
}

//anade al final
template<typename J>
void Listaenlazada<J>::pushBack(J data) {
    Nodo<J>* newNodo = new Nodo<J>(data);
    if (!head) {
        head = newNodo;
    }
    else {
        Nodo<J>* actual = head;
        while (actual->Devolver()) {
            actual = actual->Devolver();
        }actual->Siguiente(newNodo);
    }dim++;
}
//anade al inicio
template <typename J>
void Listaenlazada<J>::pushFront(J elem) {
    head = new Nodo<J>(elem, head);
}

//elimina el final
template<typename J>
void Listaenlazada<J>::popBack() {
    int tam = dim - 1;
    Nodo<J>* aux, * actual = head;
    if (tam != 0) {
        int i = 0;
        while (i < tam) {
            aux = actual; 
            actual = actual->Devolver();
            i++;
        }
        aux->Siguiente(actual->Devolver());
        delete actual;
    }
    else {
        head = head->Devolver();
        delete actual;
    }
    dim--;
}
//eliminar inicio
template<typename J>
void Listaenlazada<J>::popFront() {
    Nodo<J>* actual = head;
    head = head->Devolver();
    delete actual;
    dim--;
}

// Imprimir la Lista
template<typename J>
void Listaenlazada<J>::print(){
    Nodo<J>* temp = head;
    if (!head) {
        cout << "La Lista está vacía " << endl;
    }
    else {
        while (temp) {
            temp->print();
            if (!temp->Devolver()) cout << "NULL";
            temp = temp->Devolver();
        }
    }
    cout << endl << endl;
}

//Métodos relacionados con Iterator
template<typename J>
Nodo<J>* Listaenlazada<J>::begin() {
    return head;
}
template<typename J>
Nodo<J>* Listaenlazada<J>::end() {
    Nodo<J>* tmp;
    tmp = head;
    for (int i = 0; i < dim - 1; i++) {
        tmp = tmp->Devolver();
    }
    return tmp;
}

//Destructor
template<typename J>
Listaenlazada<J>::~Listaenlazada() {
    delete head;
}

#endif