#include "Driver.h"

namespace aed2 {

Driver::Driver() : _campus(NULL), _campusSeguro(NULL)
{
    // TODO
	//assert(false);
	/*_campus = NULL;
	_campusSeguro = NULL;*/
}

/*Driver::Driver(Campus* as, CampusSeguro* aa) {
	_campusSeguro = aa;
	_campus = as;

}*/

Driver::~Driver()
{
    // TODO
	//assert(false);
	delete(_campus);
	delete(_campusSeguro);
}


/// Generadores del Campus

void Driver::crearCampus(Nat ancho, Nat alto)
{
    // TODO
	//assert(false);
	//delete(_campus);
	_campus = new Campus(alto, ancho);
}

void Driver::agregarObstaculo(Posicion p)
{
    // TODO
	//assert(false);
	_campus->agregarObstaculo(p);
}


// Observadores del Campus

Nat Driver::filas() const
{
    // TODO
	//assert(false);
	return _campus->obtenerFilas();
}

Nat Driver::columnas() const
{
    // TODO
	//assert(false);
	return _campus->obtenerColumnas();
}

bool Driver::ocupada(Posicion p) const
{
    // TODO
	//assert(false);
	return _campus->ocupada(p);
}


/// Generadores de CampusSeguro
void  Driver::comenzarRastrillaje(const Dicc<Agente,Posicion>& d) {
    // TODO
	//assert(false);
	_campusSeguro = new CampusSeguro(*_campus, d);
}

void Driver::ingresarEstudiante(Nombre n, Posicion p)
{
    // TODO
	//assert(false);
	_campusSeguro->ingresarEstudiante(n, p);
}

void Driver::ingresarHippie(Nombre n, Posicion p)
{
    // TODO
	//assert(false);
	_campusSeguro->ingresarHippie(n, p);
}

void Driver::moverEstudiante(Nombre n, Direccion d)
{
    // TODO
	//assert(false);
	_campusSeguro->moverEstudiante(n, d);
}

void Driver::moverHippie(Nombre n)
{
    // TODO
	//assert(false);
	_campusSeguro->moverHippie(n);
}

void Driver::moverAgente(Agente pl)
{
    // TODO
	//assert(false);
	_campusSeguro->moverAgente(pl);
}


/// Observadores de CampusSeguro

Nombre Driver::iesimoEstudiante(Nat i) const
{
    // TODO
	//assert(false);
	Nat j = 0;
	diccTrie<Posicion>::Iterador it = _campusSeguro->estudiantes();
	while(j < i) {
		it.Avanzar();
		j++;
	}
	return it.Siguiente().clave;
}

Nombre Driver::iesimoHippie(Nat i) const
{
    // TODO
	//assert(false);
	Nat j = 0;
	diccTrie<Posicion>::Iterador it = _campusSeguro->hippies();
	while(j < i) {
		it.Avanzar();
		j++;
	}
	return it.Siguiente().clave;
}

Nat Driver::iesimoAgente(Nat i) const
{
    // TODO
	//assert(false);
	Nat j = 0;
	Conj<Agente>::Iterador it = _campusSeguro->agentes();
	while(j < i) {
		it.Avanzar();
		j++;
	}
	return it.Siguiente();
}

Nat Driver::cantEstudiantes() const {
    // TODO
	//assert(false);
	return _campusSeguro->cantEstudiantes();
}

Nat Driver::cantHippies() const
{    // TODO
	//assert(false);
	return _campusSeguro->cantHippies();
}

Nat Driver::cantAgentes() const
{
    // TODO
	//assert(false);
	Conj<Agente>::Iterador _agentes = _campusSeguro->agentes();
	int i = 0;
	while(_agentes.HaySiguiente()) {
		i++;
		_agentes.Avanzar();
	}
	return i;
}

Posicion Driver::posEstudianteYHippie(Nombre n) const
{
    // TODO
	//assert(false);
	return _campusSeguro->posEstYHip(n);
}

Posicion Driver::posAgente(Agente pl) const
{
    // TODO
	//assert(false);
	return _campusSeguro->posAgente(pl);
}

Nat Driver::cantSanciones(Agente pl) const
{
    // TODO
	//assert(false);
	return _campusSeguro->cantSanciones(pl);
}

Nat Driver::cantHippiesAtrapados(Agente pl) const
{
    // TODO
	//assert(false);
	return _campusSeguro->cantHippiesAtrapados(pl);
}


/// Otras operaciones de CampusSeguro

Agente Driver::masVigilante() const //la a de mas vigilante llevaba tilde, pero tiraba error stray \303
{
    // TODO
	//assert(false);
	return _campusSeguro->masVigilante();
}

const Conj<Agente> Driver::conMismasSanciones(Agente a) const
{
    // TODO
	//assert(false);
	return _campusSeguro->conMismasSanciones(a);
}

const Conj<Agente> Driver::conKSanciones(Nat k)
{
    // TODO
	//assert(false);
	/*Conj<Agente> conjunto;
	Conj<Agente>::Iterador it = _campusSeguro->conKSanciones(k);
	while(it.HaySiguiente()) {
		conjunto.AgregarRapido(it.Siguiente());
	}
	return conjunto;*/
	return _campusSeguro->conKSanciones(k);
}


} // namespace aed2

