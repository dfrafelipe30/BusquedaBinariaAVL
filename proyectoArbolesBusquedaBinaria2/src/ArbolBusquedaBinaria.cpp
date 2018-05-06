/*
 * ArbolBusquedaBinaria.cpp
 *
 */

#ifdef ARBOLBUSQUEDABINARIA_H_

#include<iostream>
#include<cmath>
template <typename TipoDato>
ArbolBusquedaBinaria<TipoDato>::ArbolBusquedaBinaria(){
	raiz = NULL;
}

template <typename TipoDato>
TipoDato ArbolBusquedaBinaria<TipoDato>::minimo(){
	return minimoNodo(raiz)->dato;
}

template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoAVL * ArbolBusquedaBinaria<TipoDato>::minimoNodo(ArbolBusquedaBinaria<TipoDato>::NodoAVL*nodo) {
	if (nodo == NULL) return NULL;
	if (nodo->izq == NULL) return nodo;
	return minimoNodo(nodo->izq);
}

//maximo
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria<TipoDato>::maximo(){
	return maximoNodo(raiz)->dato;
}

template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoAVL * ArbolBusquedaBinaria<TipoDato>::maximoNodo(ArbolBusquedaBinaria<TipoDato>::NodoAVL*nodo) {
	if (nodo == NULL) return NULL;
	if (nodo->der == NULL) return nodo;
	return minimoNodo(nodo->der);
}

// sucesor
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria<TipoDato>::sucesor(TipoDato dato){
	NodoAVL * nodo = buscarNodo(raiz, dato);
	if (nodo != NULL){
		NodoAVL * sucesor = sucesorNodo(nodo);
		if (sucesor != NULL)
			return sucesor -> dato;
	}
	std::cout << "El elemento " << dato << " no tiene sucesor en el árbol" << std::endl;
	return NULL;
}

template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoAVL * ArbolBusquedaBinaria<TipoDato>::sucesorNodo(ArbolBusquedaBinaria<TipoDato>::NodoAVL* nodo) {
	if (nodo->der != NULL) return minimoNodo(nodo->der);

	NodoAVL *padre = getNodoPadre(nodo->dato);
	while (padre!=NULL && nodo == padre->der){
		nodo = padre;
		padre = getNodoPadre(padre->dato);
	}
	return padre;
}


//nodo padre
template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoAVL * ArbolBusquedaBinaria<TipoDato>::getNodoPadre(TipoDato dato){
	if (raiz -> dato == dato)
		return NULL;
	return getNodoPadre(dato, raiz);
}

template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoAVL * ArbolBusquedaBinaria<TipoDato>::getNodoPadre(TipoDato dato, ArbolBusquedaBinaria<TipoDato>::NodoAVL * nodo){
	if (nodo == NULL)
		return NULL;
	if( (nodo->izq != NULL && nodo->izq->dato == dato) || (nodo->der != NULL && nodo->der->dato == dato) ){
		return nodo;
	}
	if(dato < nodo->dato)
		return getNodoPadre(dato, nodo->izq);
	else
		return getNodoPadre(dato, nodo->der);
}



// buscar

template <typename TipoDato>
bool ArbolBusquedaBinaria<TipoDato>::buscar(TipoDato dato){
	return buscarNodo(raiz, dato) != NULL;
}


template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoAVL * ArbolBusquedaBinaria<TipoDato>::buscarNodo(ArbolBusquedaBinaria<TipoDato>::NodoAVL*nodo, TipoDato dato) {
	if (nodo == NULL) return NULL;
	if (dato == nodo->dato) return nodo;
	if (dato < nodo->dato) {
		return buscarNodo(nodo->izq, dato);
	} else {
		return buscarNodo(nodo->der, dato);
	}
}


template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::insertar(TipoDato dato){
	insertarNodo(raiz, dato);
}

template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::insertarNodo(ArbolBusquedaBinaria<TipoDato>::NodoAVL * & nodo, TipoDato dato){
	if (nodo == NULL) {
		nodo = new NodoAVL;
		nodo->dato = dato;
		nodo->izq = nodo->der = NULL;
	} else {
		if (dato != nodo->dato) {
			if (dato < nodo->dato) {
				insertarNodo(nodo->izq, dato);
			} else {
				insertarNodo(nodo->der, dato);
			}
		}
	}

	balanciar(nodo);
}


template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::eliminar(TipoDato dato){
	eliminarNodo(raiz, dato);
}

template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::eliminarNodo(ArbolBusquedaBinaria<TipoDato>::NodoAVL * & nodo, TipoDato dato){
	if (nodo == NULL)
		return;
	if(dato < nodo->dato ){
		eliminarNodo(nodo->izq, dato);
	}else if(dato > nodo->dato){
		eliminarNodo(nodo->der, dato);
	}else if(nodo->izq != NULL && nodo->der != NULL){ // caso 2 hijos
		nodo -> dato = minimoNodo(nodo->der)->dato;	  // reemplaza dato del nodo a eliminar por el dato del minimo nodo en el subarbol derecho
		eliminarNodo(nodo->der, dato);		  // elimina dato que quedó duplicado en el subárbol derecho
	}else{											  // caso 1 hijo
		NodoAVL *nodoViejo;
		nodo = (nodo->izq != NULL) ? nodo->izq : nodo->der;
		delete nodoViejo;
	}
	balanciar(nodo);
}



template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimir(){
	std::cout << "- - -" << std::endl;
	imprimirArbol(raiz);
	std::cout << "- - -" << std::endl;
}

template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimirArbol(ArbolBusquedaBinaria<TipoDato>::NodoAVL *nodo){
	if (nodo != NULL) {
		imprimirArbol(nodo->izq);
		std::cout << nodo->dato << std::endl;
		imprimirArbol(nodo->der);
	}
}
template <typename TipoDato>
int ArbolBusquedaBinaria<TipoDato>::altura(ArbolBusquedaBinaria<TipoDato>::NodoAVL * nodo)
{
	return nodo == nullptr ? 0 : nodo->h;
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::balanciar(ArbolBusquedaBinaria<TipoDato>::NodoAVL *  & nodo)
{
	if(nodo == nullptr)
	{
		return;
	}
	if(altura(nodo -> izq) - altura(nodo -> der) > 1)
	{
		if(altura(nodo -> izq -> izq) >= altura(nodo -> izq ->der))
		{
			rotarIzq(nodo);
		}
		else rotarDer(nodo);
	}
	else{
		if(altura(nodo -> der) - altura(nodo->izq) > 1)
		{
			if(altura(nodo->der->der) >= altura(nodo->der->izq))
			{
				rotarDer(nodo);
			}
			else rotarIzq(nodo);
		}
		nodo -> h= max(altura(nodo -> izq), altura(nodo-> der)) + 1;
	}
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::rotarIzq(ArbolBusquedaBinaria<TipoDato>::NodoAVL *  & nodo)
{
	NodoAVL * temp = nodo -> izq;
	nodo -> izq = temp -> der;
	temp -> der = nodo;
	nodo -> h= max(altura(nodo -> izq),altura(nodo->der));
	temp -> h = max(altura(temp -> izq), nodo -> h) + 1;
	nodo = temp;
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::rotarIzq(ArbolBusquedaBinaria<TipoDato>::NodoAVL *  & nodo)
{
	NodoAVL * temp = nodo -> izq;
	nodo -> izq = temp -> der;
	temp -> der = nodo;
	nodo -> h= max(altura(nodo -> izq),altura(nodo->der));
	temp -> h = max(altura(temp -> izq), nodo -> h) + 1;
	nodo = temp;
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::rotarDer(ArbolBusquedaBinaria<TipoDato>::NodoAVL *  & nodo)
{
	NodoAVL * temp = nodo -> der;
	nodo -> der = temp -> izq;
	temp -> izq = nodo;
	nodo -> h= max(altura(nodo -> der),altura(nodo->izq));
	temp -> h = max(altura(temp -> der), nodo -> h) + 1;
	nodo = temp;
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::doubleRotarIzq(ArbolBusquedaBinaria<TipoDato>::NodoAVL *  & nodo)
{
	rotarDer(nodo -> der);
	rotarIzq(nodo);
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::doubleRotarDer(ArbolBusquedaBinaria<TipoDato>::NodoAVL *  & nodo)
{
	rotarDer(nodo -> izq);
	rotarIzq(nodo);
}
#endif
