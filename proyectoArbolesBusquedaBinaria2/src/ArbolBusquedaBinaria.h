/*
 * ArbolBusquedaBinaria.h
 *
 *  Created on: 20/04/2018
 *      Author: juanferna.perez
 */

#ifndef ARBOLBUSQUEDABINARIA_H_
#define ARBOLBUSQUEDABINARIA_H_

template <typename TipoDato>
class ArbolBusquedaBinaria {
public:
	/*
	* Tipo: Nodo de �rbol de B�squeda Binaria
	* ----------
	* Estructura para almacenar cada nodo del �rbol.
	*/

	struct NodoAVL {
		TipoDato dato;
		NodoAVL *izq;
		NodoAVL *der;
		int h ;
	};

	//Constructores
	ArbolBusquedaBinaria();

	ArbolBusquedaBinaria(TipoDato datoIni);

	//~ArbolBusquedaBinaria();

	//M�todos p�blicos
	bool buscar(TipoDato dato);

	NodoAVL* buscarNodo(NodoAVL* nodo, TipoDato dato);


	TipoDato minimo();

	NodoAVL* minimoNodo(NodoAVL * nodo);

	TipoDato maximo();

	NodoAVL* maximoNodo(NodoAVL * nodo);

	TipoDato predecesor(TipoDato dato);

	NodoAVL* predecesorNodo(NodoAVL* nodo, TipoDato dato);

	TipoDato sucesor(TipoDato dato);

	NodoAVL* sucesorNodo(NodoAVL* nodo);

	NodoAVL* getNodoPadre(TipoDato dato);

	NodoAVL* getNodoPadre(TipoDato dato, NodoAVL * nodo);

	void insertar(TipoDato dato);

	void insertarNodo(NodoAVL * & nodo, TipoDato dato);

	void eliminar(TipoDato dato);

	void eliminarNodo(NodoAVL * & nodo, TipoDato dato);

	void imprimir();

	void imprimirArbol(NodoAVL * nodo);

	int altura(NodoAVL *nodo);

	void balanciar(NodoAVL * & nodo);

	void rotarIzq(NodoAVL * & nodo);

	void rotarDer(NodoAVL * & nodo);
	/*

	void imprimirPreOrden();

	void imprimirPostOrden();

	*/

private:
	/* Atributos */
	NodoAVL *raiz; 	/* Apuntador al nodo ra�z del �rbol */
};



#endif /* ARBOLBUSQUEDABINARIA_H_ */

#include "ArbolBusquedaBinaria.cpp"
