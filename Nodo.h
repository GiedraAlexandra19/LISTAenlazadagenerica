#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
template<typename J>

class Nodo {
private:
    J head;
    Nodo<J>* next;
public:
    Nodo(J data);
    Nodo(Nodo<J>& data);
    void Siguiente(J data);
    Nodo<J>* Devolver();
    J Devolver1();

};
//Constructores
template<typename J>
Nodo<J>::Nodo(J data) {
    next = nullptr;
    head = data;
}
template<typename J>
Nodo<J>::Nodo(Nodo<J>& data) {
    this->head = data.head;
    if (data.next== nullptr) {
        this->next = nullptr;
    }
    else {
        this->next = new Nodo<J>(data.next->head);
        Nodo<J>* tmp;
        tmp = data.sig;
        Nodo<J>* tmp2;
        tmp2 = this->sig;
        while (tmp->next!= nullptr) {
            tmp2->next = new Nodo<J>(tmp->next->head);
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        tmp->next = nullptr;
    }
}
//Métodos
template<typename J>
void Nodo<J>::Siguiente(J data) {
    next = new Nodo<J>(data);
}
template<typename J>
Nodo<J>* Nodo<J>::Devolver() {
    return next;
}
template<typename J>
J Nodo<J>::Devolver1() {
    return head;
}
#endif
