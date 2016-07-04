#include "campus.h"
using namespace std; 

Campus::Campus(Nat Filas, Nat Columnas) {
	filas = Filas;
	columnas = Columnas;
	// (Eze) no se si a ocupadas hay q ponerle algo, quiza ya al declararlo viene vacío

	// tiene que retornar algo esto pero ni idea
	// (Eze) No, no tiene que retornar nada, solo tine que inicializar las variables.
}

Campus::Campus()
{
	filas = 0;
	columnas = 0;
	Conj<Posicion> nuevoConj;
	ocupadas = nuevoConj;
}

Campus::~Campus()
{
	
}

void Campus::agregarObstaculo(Posicion p) { //requiere que no este ocupada, asi que podemos agregar rapido
	ocupadas.AgregarRapido(p);
}	

	
Nat Campus::obtenerFilas() const {
	return filas;
}
		

Nat Campus::obtenerColumnas() const {
	return columnas; 
}	


bool Campus::ocupada(Posicion p) const {
	return ocupadas.Pertenece(p);
}

bool Campus:: posValida(Posicion p) {
	return ((0 < p.x) && (p.x <= columnas) && (0 < p.y) & (p.y <= filas));
}


bool Campus::esIngreso(Posicion p) {
	return (ingresoSuperior(p) || ingresoInferior(p));
}

bool Campus::ingresoSuperior(Posicion p) {
	return (p.y == 1);
}

bool Campus::ingresoInferior(Posicion p) {
	return (p.y == filas);
}

Conj<Posicion> Campus::vecinos(Posicion p) {
	Conj<Posicion> conjunto;
	Posicion posicion1;
	Posicion posicion2;
	Posicion posicion3;
	Posicion posicion4;
	posicion1.x = p.x + 1;
	posicion1.y = p.y;
	conjunto.AgregarRapido(posicion1);
	posicion2.x = p.x - 1;
	posicion2.y = p.y;
	conjunto.AgregarRapido(posicion2);
	posicion3.x = p.x;
	posicion3.y = p.y + 1;
	conjunto.AgregarRapido(posicion3);
	posicion4.x = p.x;
	posicion4.y = p.y - 1;
	conjunto.AgregarRapido(posicion4);
	return vecinosValidos(conjunto);
}

Conj<Posicion> Campus::vecinosValidos(Conj<Posicion> cp) {
	Conj<Posicion> nuevoConj;
	Conj<Posicion>::const_Iterador it = cp.CrearIt();
	while(it.HaySiguiente()) {
		if(posValida(it.Siguiente())) {
			nuevoConj.AgregarRapido(it.Siguiente());
		}
		it.Avanzar();
	}
	return nuevoConj;
}


Nat Campus::distancia(Posicion p1, Posicion p2) { //no se si existe alguna funcion para aplicar a los unsigned int (aka Nat) para obtener el valor absoluto..
	Nat absolutoX;
	Nat absolutoY;
	if(p1.x > p2.x) {
		absolutoX = p1.x - p2.x;
	} else {
		absolutoX = p2.x - p1.x;
	}
	if(p1.y > p2.y) {
		absolutoY = p1.y - p2.y;
	} else {
		absolutoY = p2.y - p1.y;
	}
	return absolutoX + absolutoY;
}

Posicion Campus::proxPosicion(Posicion p, Direccion d){
	Posicion pos;
	if(d == izq) {
		pos.x = p.x - 1;
		pos.y = p.y;
	} else if(d == der) {
		pos.x = p.x + 1;
		pos.y = p.y;
	} else if(d == arriba) {
		pos.x = p.x;
		pos.y = p.y - 1;
	} else if(d == abajo) {
		pos.x = p.x;
		pos.y = p.y + 1;
	}
	return pos;
}

Conj<Posicion> Campus::ingresosMasCercanos(Posicion p) {
	Conj<Posicion> conjunto;
	Posicion posAux1;
	Posicion posAux2;
	posAux1.x = p.x;
	posAux1.y = 1;
	posAux2.x = p.x;
	posAux2.y = filas;
	if(distancia(p, posAux1) < distancia(p, posAux2)) {
		conjunto.AgregarRapido(posAux1);
	} else if(distancia(p, posAux1) > distancia(p, posAux2)) {
		conjunto.AgregarRapido(posAux2);
	} else {
		conjunto.AgregarRapido(posAux1);
		conjunto.AgregarRapido(posAux2);
	}
	return conjunto;
}

Posicion Campus::posicionMinimaDistancia(Posicion p, Conj<Posicion> cp) {
	Conj<Posicion>::Iterador it = cp.CrearIt();
	Posicion minima = it.Siguiente();
	it.Avanzar();
	while(it.HaySiguiente()) {
		if(distancia(p, it.Siguiente()) < distancia(p, minima)) {
			minima = it.Siguiente();
		}
		it.Avanzar();
	}
	return minima;
}

Conj<Direccion> Campus::enQueDireccionesVoy(Posicion p1, Posicion p2) {
	Conj<Direccion> conj;
	//Conj<Direccion>::Iterador itConj = conj.CrearIt();
	Direccion d1;
	Direccion d2;
	Direccion d3;
	Direccion d4; 
	if(p1.x < p2.x) {
		d1 = der;
		conj.AgregarRapido(d1);
	} else if(p1.x > p2.x) {
		d2 = izq;
		conj.AgregarRapido(d2);
	} else if(p1.y < p2.y) {
		d3 = abajo;
		conj.AgregarRapido(d3);
	} else if(p1.y > p2.y) {
		d4 = arriba;
		conj.AgregarRapido(d4);
	}
	return conj;
}

Direccion Campus::enQueDireccionVoy(Posicion p1, Posicion p2) {
	Direccion d;
	Conj<Direccion> conj = enQueDireccionesVoy(p1, p2);
	Conj<Direccion>::Iterador it = conj.CrearIt();
	d = it.Siguiente();
	return d;
}

Conj<Posicion> Campus::objetivosDeMinimaDistancia(Posicion p, Conj<Posicion> cp, Nat dist) {
	Conj<Posicion> res;
	Conj<Posicion>::Iterador it = cp.CrearIt();
	while(it.HaySiguiente()) {
		if(distancia(p, it.Siguiente()) == dist) {
			res.AgregarRapido(it.Siguiente());
		}
		it.Avanzar();
	}
	return res;
}
