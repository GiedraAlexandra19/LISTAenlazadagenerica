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
    void ordenar();
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

// Ordenar
template<typename J>
void Listaenlazada<J>::ordenar() {
    int temp_data;
    Nodo* aux_node = head;
    Nodo* temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->next) {
            temp = temp->next;

            if (aux_node->data > temp->data) {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }

        aux_node = aux_node->next;
    }
}

//Mostrar lista
template<typename J>
void Listaenlazada<J>::print() {
    Nodo<J>* temp = head;
    if (!head) {
        cout << "La Lista está vacía " << endl;
    }
    else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
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