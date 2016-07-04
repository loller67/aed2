#ifndef _CAMPUS_H_
#define _CAMPUS_H_

#include "aed2.h"
#include "Tipos.h"

using namespace aed2;

	class Campus
	{
		public:
			//constructor
			Campus(Nat filas, Nat columnas);  
			Campus();
			//destructor
			~Campus();
			
			//funciones
			void agregarObstaculo(Posicion p);			
			Nat obtenerFilas() const;
			Nat obtenerColumnas() const;
			bool ocupada(Posicion p) const;
			bool posValida(Posicion p);
			bool esIngreso(Posicion p);
			bool ingresoSuperior(Posicion p);
			bool ingresoInferior(Posicion p);
			Conj<Posicion> vecinos(Posicion p);
			Conj<Posicion> vecinosValidos(Conj<Posicion> cp);
			Nat distancia(Posicion p1, Posicion p2);
			Posicion proxPosicion(Posicion p, Direccion d);
			Conj<Posicion> ingresosMasCercanos(Posicion p);
			Posicion posicionMinimaDistancia(Posicion p, Conj<Posicion> cp);
			Conj<Direccion> enQueDireccionesVoy(Posicion p1, Posicion p2);
			Direccion enQueDireccionVoy(Posicion p1, Posicion p2);
			Conj<Posicion> objetivosDeMinimaDistancia(Posicion p, Conj<Posicion> cp, Nat dist);

			//operaciones
			//bool operator<(const Campus& c1) const;
			bool operator!=(const Campus& c1) const;
			//bool operator==(const Campus& c1) const;
		private:
			 Nat filas;
			 Nat columnas;
			 Conj<Posicion> ocupadas;
	};
#endif
