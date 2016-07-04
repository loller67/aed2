#ifndef AED2_TIPOS_H_
#define AED2_TIPOS_H_

#include "aed2/TiposBasicos.h"

namespace aed2{

	typedef struct Posicion_t {
		Posicion_t(int X, int Y) : x(X), y(Y){}
		Posicion_t() {}
		Nat x,y;
		bool operator==(const Posicion_t& p) const {
			return (x == p.x && y == p.y);
		}
		bool operator!=(const Posicion_t& p) const {
			return !(x == p.x && y == p.y);
		}
	} Posicion;
	typedef enum Direccion_t {
		izq,der,arriba,abajo
	} Direccion;
	typedef Nat Agente;
	typedef String Nombre;

} // namespace aed2

#endif // AED2_TIPOS_H_
