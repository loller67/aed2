#include "DiccHash.h"
using namespace std; 
/*
template<class T>
DiccHash<T>::DiccHash(Nat n) {
	array = Arreglo<tupla>(n);
	
}*/

/*template<class T>
DiccHash<T>::DiccHash() {

}

template<class T>
DiccHash<T>::~DiccHash()
{
	
}*/
/*
template<class T>
void DiccHash<T>::definir(Nat c, T s) {
	Nat i = 0;
	Nat indice = c % tamano;
	while(array.Definido(i)) {
		i = i + 1;
		indice = (c+i) % tamano;
	}
	tupla tupla_dicc;
	tupla_dicc.clave = c;
	tupla_dicc.significado = s;
	array[indice] = tupla_dicc;
}

template<class T>
bool DiccHash<T>::definido(Nat c) {
	Nat i = 0;
	Nat indice = c % tamano;
	while(!(array[indice].clave == c) && (i < tamano)) {
		i = i + 1;
		indice = (c+i) % tamano;
	}
	return !(i == tamano) || (i == tamano && array[indice].clave == c);
}

template<class T>
T* DiccHash<T>::significado(Nat c) {
	Nat i = 0;
	Nat indice = c % tamano;
	while(!(array[indice].clave == c)) {
		i = i + 1;
		indice = (c+i) % tamano;
	}
	return &array[indice].significado;
}*/
