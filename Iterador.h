#ifndef ITERADOR_H
#define ITERADOR_H
#include "Nodo.h"

template <typename J>
class Iterator;
template <typename J>
ostream& operator << (ostream& o, const Iterator<J>& data);
template<typename J>
class Iterator {
private:
    Nodo<J>* g;
public:
    Iterator(Nodo<J>* b);
    friend ostream& operator << <>(ostream& o, const Iterator<J>& data);
    Iterator<J>& operator ++();
    bool operator!=(Nodo<J>* p);
    ~Iterator();
};
//Constructores
template<typename J>
Iterator<J>::Iterator(Nodo<J>* b) {
    g = b;
}
template<typename J>

//Operadores
ostream& operator << (ostream& o, const Iterator<J>& data) {
    o << data.g->Devol2();
    return o;
}
template<typename J>
Iterator<J>& Iterator<J>::operator ++() {
    if (this->g->Devolver() == nullptr) {
        this->g = nullptr;
    }
    else {
        this->g = this->g->Devolver();
    }
    return *this;
}
template<typename J>
bool Iterator<J>::operator!=(Nodo<J>* p) {
    return this->g != p->Devolver();
}
//Destructor
template<typename J>
Iterator<J>::~Iterator() {
    delete g;
}
#endif
