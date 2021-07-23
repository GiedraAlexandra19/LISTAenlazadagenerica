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
    Iterator<int> i(b.begin());
    for (; i != b.end(); ++i) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Lista ordenada" << endl;
    l.ordenar();
    l.print();

    cout << "\nElimina un elemento: " << endl;
    cin >> data;
    l.Eliminar(data);
    l.print();
    cout << endl;

    return 0;
}