#include <iostream>
#include "listaenlazada.h"
#include <iterator>
#include "Iterador.h"

using namespace std;

int main() {
    int dim;
    int data;

    Listaenlazada<int> l;
    cout << "Ingresa la dimension de la lista: " << endl;
    cin >> dim;

    l.fill_random(dim);
    
    cout << "\nLista: " << endl;
    Iterator<int> i(l.begin());
    for (; i != l.end(); ++i) {
        cout << i << " ";
    }
    cout << endl;


    l.pushBack(10);
    l.pushFront(20);
    cout << "\nNueva Lista: " << endl;
    l.print();

    l.popBack();
    l.popFront();
    cout << "\nNueva Lista: " << endl;
    l.print();
    
    return 0;
}