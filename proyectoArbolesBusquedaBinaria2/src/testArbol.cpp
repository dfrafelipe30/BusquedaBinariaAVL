/*
 * testArbol.cpp
 */

#include"ArbolBusquedaBinaria.h"
#include<iostream>
using namespace std;

int main(){
	ArbolBusquedaBinaria<int> arbol;
	arbol.insertar(7);
	arbol.insertar(3);
	arbol.insertar(1);
	arbol.insertar(5);
	arbol.insertar(9);

	arbol.imprimir();
	cout << "min: " << arbol.minimo() << endl;
	cout << "max: " << arbol.maximo() << endl;
	cout << "suc(3): " << arbol.sucesor(3) << endl;
	cout << "suc(1): " << arbol.sucesor(1) << endl;
	cout << "suc(7): " << arbol.sucesor(7) << endl;
	cout << "suc(9): " << arbol.sucesor(9) << endl;

	arbol.eliminar(5);
	arbol.imprimir();

	arbol.eliminar(1);
	arbol.imprimir();



	return 0;
}


