#ifndef DICCHASH_H
#define DICCHASH_H

#include "aed2.h"
#include "Tipos.h"
#include <iostream>
//#include "CampusSeguro.h"

using namespace aed2;
	template<class T>
	class DiccHash
	{
		public:
			//constructor
			DiccHash(Nat);  
			DiccHash();
			//destructor
			~DiccHash();
			
			//funciones
			void definir(Nat, const T&);			
			bool definido(Nat);
			T* significado(Nat);
			Nat cardinal();
			Nat obtenerTamano();
			void mostrar();
			//operaciones
			//bool operator<(const Campus& c1) const;
			//bool operator!=(const Campus& c1) const;
			//bool operator==(const Campus& c1) const;

		private:
			typedef struct tupla_t {
				Nat clave;
				T significado;
			} tupla;
			
			Nat tamano; //tamaño del arreglo
			Arreglo<tupla> array;
			Nat cant; //cantidad de claves creadas
	};


template<class T>
DiccHash<T>::DiccHash(Nat n) {
	array = Arreglo<tupla>(n);
	tamano = n;
	cant = 0;
}

template<class T>
DiccHash<T>::DiccHash() {
	tamano = 0;
	cant = 0;
	array = Arreglo<tupla>(0); //Sí, no pasa nada si creas un arreglo de cero, mientras que no trates de agregar nada y no trates de acceder a alguna posición...
}

template<class T>
DiccHash<T>::~DiccHash()
{
	
}

template<class T>
Nat DiccHash<T>::cardinal() {
	return cant;
}

template<class T>
void DiccHash<T>::definir(Nat c, const T& s) {
	//Nat i = 0;
	Nat clave_aux = c;
	if(cant == tamano) return;
	if(tamano > 0) {
		Nat indice = c % tamano;
		while(array.Definido(indice)) {
			//cout <<"no entra" << i;
			//i = i + 1;
			c++;
			indice = c % tamano;
		}
		tupla tupla_dicc;
		tupla_dicc.clave = clave_aux;
		tupla_dicc.significado = s;
		array.Definir(indice, tupla_dicc);
		cant++;
	}
}

template<class T>
bool DiccHash<T>::definido(Nat c) {
	if(tamano > 0) {
		Nat i = 0;
		Nat indice = c % tamano;
		if(!array.Definido(indice)) return false;
		while(!(array[indice].clave == c) && (i < tamano)) {
			i = i + 1;
			indice = (c+i) % tamano;
		}
		return !(i == tamano) || (i == tamano && array[indice].clave == c);
	} else {
		return false;
	}
}
template<class T>
Nat DiccHash<T>::obtenerTamano() {
	return tamano;
}

template<class T>
T* DiccHash<T>::significado(Nat c) {
	//Nat i = 0;
	Nat clave_aux = c;
	Nat indice = c % tamano;
	while(!(array[indice].clave == clave_aux)) {
		//i = i + 1;
		c++;
		indice = c % tamano;
	}
	return &array[indice].significado;
}

template<class T>
void DiccHash<T>::mostrar() {
	Nat i = 0;
	while(i < tamano) {
		Nat asdd = array[i].clave;
		cout << asdd;
		i = i + 1;
	}
}

#endif

