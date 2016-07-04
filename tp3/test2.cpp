#include "Driver.h"
#include "mini_test.h"
#include "DiccHash.h"
#include <string>
#include <iostream>

using namespace aed2;


// ---------------------------------------------------------------------

/**
 * Ejemplo de caso de test, con llamadas a las rutinas de aserción 
 * definidas en mini_test.h
 */
 
string boolToString(bool booleano) {
	if(booleano) {
		return "true";
	} else {
		return "false";
	}
}
 
void test_agregar_obstaculos() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);


	
	Posicion p;
	p.x = 2; 
	p.y = 3;

	campus.agregarObstaculo(p);

	ASSERT(campus.ocupada(p) == true);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	ASSERT(campus.ocupada(p2) == false);
	
	
	
	
	
	
	/*Lista<int> listaPrivada;
	{
	Lista<int> lista;
	int as = 4;
	lista.AgregarAdelante(as);
	listaPrivada = lista;
	}
	cout << "Longitud: " << listaPrivada.Longitud() << endl;
	Lista<int>::Iterador it = listaPrivada.CrearIt();
	while(it.HaySiguiente()) {
		cout << "Elemento: " << it.Siguiente() << endl;
		it.Avanzar();
	}*/
	/*DiccHash<int> dicc = DiccHash<int>(10);
	dicc.definir(2, 5);
	dicc.definir(3, 7);*/
	

}

void test_hash() {
	cout << endl;
	DiccHash<int> dicc = DiccHash<int>();
	dicc = DiccHash<int>(10);
	
	cout << "Defino clave 3, significado 1" << endl;
	dicc.definir(3,1);
	
	int* puntero1 = dicc.significado(3);
	cout << "El significado de la clave 3 es " << *puntero1 << endl;
	
	cout << "Defino clave 1, significado 5" << endl;
	dicc.definir(1,5);
	
	int* puntero2 = dicc.significado(1);
	cout << "El significado de la clave 1 es " << *puntero2 << endl;
	
	int i = 0;
	bool definido;
	while(i < 10) {
		definido = dicc.definido(i);
		cout << "Esta definida la clave " << i << "? " << boolToString(definido) << endl;
		i++;
	}
	
	cout << "Cantidad de elementos en el diccionario: " << dicc.cardinal() << endl;
	cout << "Tamaño maximo del diccionario: " << dicc.obtenerTamano() << endl;
}

void test_trie() {
	cout << endl;
	diccTrie<int> dicc = diccTrie<int>();
	
	cout << "Defino la clave 'sebi' con significado 44" << endl;
	dicc.definir("sebi", 44);
	
	cout << "Defino la clave 'sebil' con significado 11" << endl;
	dicc.definir("sebil", 11);
	
	cout << "Defino la clave 'sebila' con significado 3" << endl;
	dicc.definir("sebila", 3);
	
	cout << "Defino la clave 'sebils' con significado 5" << endl;
	dicc.definir("sebils", 5);
	
	cout << "Defino la clave 'seb' con significado 123" << endl;
	dicc.definir("seb", 123);
	
	cout << "Defino la clave 'sebilas' con significado 6" << endl;
	dicc.definir("sebilas", 6);
	
	cout << "Defino la clave 'ezelargo' con significado 33" << endl;
	dicc.definir("ezelargo", 33);
	
	cout << "Defino la clave 'eze' con significado 33" << endl;
	dicc.definir("eze", 33);
	
	cout << "Defino la clave 'a' con significado 1" << endl;
	dicc.definir("a", 1);
	
	/*cout << "Defino la clave 's' con significado 10" << endl;
	dicc.definir("s", 10);*/
	
	/*cout << "Defino la clave 'e' con significado 255" << endl;
	dicc.definir("e", 255);*/
	
	cout << "Borro la clave 'sebil'" << endl;
	dicc.borrar("sebil");
	
	cout << "Borro la clave 'ezelargo'" << endl;
	dicc.borrar("ezelargo");
	
	int significadoSebila = dicc.obtener("sebila");
	cout << "La clave 'sebila' tiene significado: " << significadoSebila << endl;
	
	int significadoSebi = dicc.obtener("sebi");
	cout << "La clave 'sebi' tiene significado: " << significadoSebi << endl;
	
	bool definidoSebil = dicc.definido("sebil");
	cout << "Esta definida la clave 'sebil'? " << boolToString(definidoSebil) << endl;
	
	bool definidoSebi = dicc.definido("sebi");
	cout << "Esta definida la clave 'sebi'? " << boolToString(definidoSebi) << endl;
	
	diccTrie<int>::Iterador it = dicc.Claves();
	while(it.HaySiguiente()) {
		cout << "La clave '" << it.Siguiente().clave << "' tiene significado " << it.Siguiente().significado << endl;
		it.Avanzar();
	}
	cout << endl;
	dicc.MostrarClaves();
}

void test_ultra() {
	Driver campus;
	campus.crearCampus(10,10);
	Posicion o;
	o.x = 1; 
	o.y = 1;
	campus.agregarObstaculo(o);
	Posicion o2;
	o2.x = 2; 
	o2.y = 2;
	campus.agregarObstaculo(o2);
	Posicion o3;
	o3.x = 3; 
	o3.y = 1;
	campus.agregarObstaculo(o3);
	
	Dicc<Agente, Posicion> agentes;
	Agente ag1;
	Posicion p1;
	p1.x = 2;
	p1.y = 1;
	agentes.Definir(ag1, p1);
	
	Agente ag2;
	Posicion p2;
	p2.x = 3;
	p2.y = 3;
	agentes.Definir(ag2, p2);
	
	Agente ag3;
	Posicion p3;
	p3.x = 4;
	p3.y = 3;
	agentes.Definir(ag3, p3);
	campus.comenzarRastrillaje(agentes);
	Nombre s = "pepe";
	Posicion p10;
	p10.x = 5; 
	p10.y = 1;
	campus.ingresarEstudiante(s,p10);
	campus.moverEstudiante(s,abajo);
	campus.moverEstudiante(s,abajo);
	campus.moverEstudiante(s,abajo);
	campus.moverEstudiante(s,izq);
	campus.moverEstudiante(s,izq);
	campus.moverEstudiante(s,izq);
	campus.moverEstudiante(s,izq);
	campus.moverEstudiante(s,arriba);
	campus.moverEstudiante(s,arriba);
	Nombre nhip = "hipie";
	Posicion phip;
	phip.x = 4;
	phip.y = 1;
	campus.ingresarHippie(nhip, phip);
	campus.moverHippie(nhip);
	campus.moverHippie(nhip);
	campus.moverAgente(ag3);
	campus.moverAgente(ag1);
	cout << campus.posAgente(ag1).x << campus.posAgente(ag1).y << endl;
	cout << campus.posAgente(ag2).x << campus.posAgente(ag2).y << endl;
	cout << campus.posAgente(ag3).x << campus.posAgente(ag3).y << endl;
	cout << campus.posEstudianteYHippie("hipie").x << campus.posEstudianteYHippie("hipie").y << endl;
	/*cout << campus.cantHippiesAtrapados(ag3) << endl;
	cout << campus.cantHippiesAtrapados(ag2) << endl;*/
	
	ASSERT(campus.cantHippiesAtrapados(ag3) == 1);
	ASSERT(campus.cantHippiesAtrapados(ag2) == 1);
}

void test_ingresa_estudiante(){
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarEstudiante(s,p2);	


	Posicion p3 = campus.posEstudianteYHippie(s);
	ASSERT(p3.x == p2.x && p3.y == p3.x);
}

// DIFICIL
void test_ingresa_hippie_y_convierte() {
	// Testea que cuando ingresa un hippie y esta rodeado de estudiantes se convierte
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p1;
	p1.x = 1; 
	p1.y = 1;

	Posicion p2;
	p2.x = 2; 
	p2.y = 1;
	

	Posicion p3;
	p3.x = 3; 
	p3.y = 1;

	Nombre s1 = "pepe";
	Nombre s2 = "pepo";
	Nombre s3 = "pepa";
	
	// Ingreso 3 estudiantes uno al lado del otro
	campus.ingresarEstudiante(s1,p1);	
	
	campus.ingresarEstudiante(s2,p2);	
	
	campus.ingresarEstudiante(s3,p3);	
	
	/*ASSERT(campus.posEstudianteYHippie(s2).x == 2);
	ASSERT(campus.posEstudianteYHippie(s2).y == 1);*/
	
	// Avanzo el estudiante del medio
	campus.moverEstudiante(s2,abajo);
	
	/*ASSERT(campus.posEstudianteYHippie(s2).x == 2);
	ASSERT(campus.posEstudianteYHippie(s2).y == 2);*/

	// Ahora hago ingresar un hippie,se tiene que convertir a estudiante
	Nombre h1 = "wololoHippie";
	
	campus.ingresarHippie(h1,p2);
	
	ASSERT(campus.cantEstudiantes() == 4);
	ASSERT(campus.cantHippies() == 0);
}

// DIFICIL
void test_mueve_estudiante_y_convierte() {
	// Testea que cuando se mueve un estudiante y rodea a un hippie se convierte
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p1;
	p1.x = 1; 
	p1.y = 1;

	Posicion p2;
	p2.x = 2; 
	p2.y = 1;


	Posicion p3;
	p3.x = 3; 
	p3.y = 1;

	Nombre s1 = "pepe";
	Nombre s2 = "pepo";
	Nombre s3 = "pepa";
	
	// Ingreso 3 estudiantes uno al lado del otro
	campus.ingresarEstudiante(s1,p1);	
	campus.ingresarEstudiante(s2,p2);	
	campus.ingresarEstudiante(s3,p3);	

	// Avanzo el estudiante del medio
	campus.moverEstudiante(s2,abajo);
	campus.moverEstudiante(s2,abajo);

	// Ahora hago ingresar un hippie Y NO SE TIENE QUE CONVERTIR
	Nombre h1 = "wololoHippie";
	campus.ingresarHippie(h1,p2);
	
	ASSERT(campus.cantEstudiantes() == 3);
	ASSERT(campus.cantHippies() == 1);

	// Muevo el estudiante hacia arriba y tiene que convertir talannnn
	campus.moverEstudiante(s2,arriba);

	ASSERT(campus.cantEstudiantes() == 4);
	ASSERT(campus.cantHippies() == 0);

}

void test_mover_estudiante() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarEstudiante(s,p2);	
	campus.moverEstudiante(s, abajo);

	Posicion p3;
	p3.x = 1; 
	p3.y = 2;


	Posicion p = campus.posEstudianteYHippie(s);
	ASSERT(p3.x == p.x && p3.y == p.y);

}

void test_mover_estudiante_fuera() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarEstudiante(s,p2);	
	campus.moverEstudiante(s, arriba);

	
	ASSERT(campus.cantEstudiantes() == 0);	
}

void test_ingresa_hippie() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarHippie(s,p2);	
	

	Posicion p = campus.posEstudianteYHippie(s);
	ASSERT(p2.x == p.x && p2.y == p.y);

}

void test_ingresa_hippie_y_estudiante() {
	// Idea de este test es probar el funcionamiento del Trie
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarHippie(s,p2);	

	Posicion p3;
	p3.x = 1; 
	p3.y = 2;

	Nombre t = "pepa";
	campus.ingresarEstudiante(t,p3);

	Posicion p;
	p.x = 1; 
	p.y = 3;

	Nombre r = "pepen";
	campus.ingresarEstudiante(r,p);	


	ASSERT(campus.iesimoHippie(0) == s);

	// No importa el orden, pero tienen que estar los dos
	ASSERT(campus.iesimoEstudiante(0) == t || campus.iesimoEstudiante(1) == t);
	ASSERT(campus.iesimoEstudiante(0) == r || campus.iesimoEstudiante(1) == r);

}


void test_mover_hippie_a_estudiante() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);

	Posicion p;
	p.x = 1; 
	p.y = 1;

	Nombre t = "pepa";
	campus.ingresarEstudiante(t,p);

	campus.moverEstudiante(t, abajo);
	campus.moverEstudiante(t, abajo);
	campus.moverEstudiante(t, abajo);
	campus.moverEstudiante(t, abajo);
	campus.moverEstudiante(t, abajo);

	// Baja el estudiante
	Posicion p3 = campus.posEstudianteYHippie(t);
	ASSERT(p3.x == 1 && p3.y == 6);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarHippie(s,p2);	
	campus.moverHippie(s);	

	// El hippie se mueve hacia abajo
	Posicion p4 = campus.posEstudianteYHippie(s);
	ASSERT(p4.x == 1 && p4.y == 2);

	Posicion p5;
	p5.x = 3; 
	p5.y = 1;

	Nombre r = "pepo";
	campus.ingresarEstudiante(r,p5);

	// El hippie se mueve hacia el nuevo estudiante
	campus.moverHippie(s);	
	p4 = campus.posEstudianteYHippie(s);
	ASSERT((p4.x == 1 && p4.y == 1) || (p4.x == 2 && p4.y == 2) );

}


void test_mover_hippie_a_ingreso() {
	// Idea del test: el hippie se mueve hacia el estudiante
	// Luego el estudiante se borra
	// Luego el hippie se mueve al ingreso mas cercano

	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	campus.comenzarRastrillaje(agentes);


	Posicion p;
	p.x = 1; 
	p.y = 1;

	Nombre t = "pepa";
	campus.ingresarEstudiante(t,p);

	for (int i=0; i < 5; i++) {
		campus.moverEstudiante(t, abajo);
	}

	// Baja el estudiante
	Posicion p3 = campus.posEstudianteYHippie(t);
	ASSERT(p3.x == 1 && p3.y == 6);

	Posicion p2;
	p2.x = 1; 
	p2.y = 1;

	Nombre s = "pepe";
	campus.ingresarHippie(s,p2);	
	campus.moverHippie(s);	
	campus.moverHippie(s);	

	// El hippie se mueve hacia abajo
	Posicion p4 = campus.posEstudianteYHippie(s);
	ASSERT(p4.x == 1 && p4.y == 3);

	// Hago salir al estudiante, lo muevo a la derecha para no pisar el hippie
	campus.moverEstudiante(t, der);
	for (int i=0; i < 6; i++) {
		campus.moverEstudiante(t, arriba);
	}

	ASSERT(campus.cantEstudiantes() == 0);	

	// Muevo al hippie , tiene que ir al ingreso mas cercano
	campus.moverHippie(s);	
	
	p4 = campus.posEstudianteYHippie(s);

	ASSERT(p4.x == 1 && p4.y == 2);

}


void test_comenzar_rastrillaje_simple() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	Agente a = 1;

	Posicion p;
	p.x = 1;
	p.y = 1;

	agentes.Definir(a,p);

	campus.comenzarRastrillaje(agentes);
	ASSERT(campus.cantAgentes() == 1);
}


void test_rastrillaje_mover_hacia_hippie() {
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	Agente a = 1;

	Posicion p;
	p.x = 1;
	p.y = 1;

	agentes.Definir(a,p);

	campus.comenzarRastrillaje(agentes);

	Posicion ph;
	ph.x = 5;
	ph.y = 1;

	Nombre h = "hippie";
	campus.ingresarHippie(h,ph);

	campus.moverAgente(a);

	Posicion p4 = campus.posAgente(a);
	//cout << p4.x << p4.y;
	ASSERT(p4.x == 2 && p4.y == 1);

}


void test_captura_hippie_entre_agentes()
{
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	Agente a = 1;
	Agente a2 = 2;
	Agente a3 = 3;

	Posicion p;
	p.x = 1;
	p.y = 1;

	Posicion p2;
	p2.x = 2;
	p2.y = 2;

	Posicion p3;
	p3.x = 3;
	p3.y = 1;

	agentes.Definir(a,p);
	agentes.Definir(a2,p2);
	agentes.Definir(a3,p3);
	
	
	/*DiccHash<int> dic = DiccHash<int>(3);
	dic.definir(a,12);
	dic.definir(a2,22);
	dic.definir(a3,32);
	dic.mostrar();*/
	
	campus.comenzarRastrillaje(agentes);
	
	
	 //pedir la posicion en el mapa de los agente
	Posicion ph;
	ph.x = 2;
	ph.y = 1;

	Nombre h = "hippie";
	campus.ingresarHippie(h,ph);
	

	/*ASSERT(campus.cantHippiesAtrapados(a) == 1);
	ASSERT(campus.cantHippiesAtrapados(a2) == 1);
	ASSERT(campus.cantHippiesAtrapados(a3) == 1);

	ASSERT(campus.masVigilante() == a || campus.masVigilante() == a2 || campus.masVigilante() == a3);*/

}

void test_captura_estudiante()
{
	
	/*Lista<int> lista;
	Lista<int>::Iterador it1 = lista.AgregarAtras(1);*/
	//Lista<int>::Iterador it2 = lista.AgregarAtras(2);
	//Lista<int>::Iterador it3 = lista.AgregarAtras(3);
	//Lista<int>::Iterador it4 = lista.AgregarAtras(4);
	//Lista<int>::Iterador it = lista.CrearIt();
	//~ while(it.HaySiguiente()) {
		//~ cout << it.Siguiente() << endl;
		//~ it.Avanzar();
	//~ }
	/*cout << it.HaySiguiente() << endl;
	cout << it.Siguiente() << endl;
	it.Avanzar();
	cout << it.HaySiguiente() << endl;
	it2.EliminarSiguiente();
	while(it.HaySiguiente()) {
		cout << it.Siguiente() << endl;
		it.Avanzar();
	}
	cout << "holi" << endl;*/
	//it1.Avanzar();
	//it1.AgregarComoSiguiente(2);
	//it1.Retroceder();
	//cout << it1.Siguiente() << endl;
	
	Driver campus;
	campus.crearCampus(10,10);

	Dicc<Agente,Posicion> agentes;
	Agente a = 1;
	Agente a2 = 2;
	Agente a3 = 3;

	Posicion p;
	p.x = 1;
	p.y = 1;

	Posicion p2;
	p2.x = 2;
	p2.y = 2;

	Posicion p3;
	p3.x = 3;
	p3.y = 1;

	agentes.Definir(a,p);
	agentes.Definir(a2,p2);
	agentes.Definir(a3,p3);

	campus.comenzarRastrillaje(agentes);

	Posicion pe;
	pe.x = 2;
	pe.y = 1;

	Nombre e = "pepe";
	campus.ingresarEstudiante(e,pe);
	//cout << "salio0" << endl;
	//cout << campus.conMismasSanciones(a).Cardinal() << endl;
	ASSERT(campus.conMismasSanciones(a).Cardinal() == 3 );
	//cout << "salio1" << endl;
	ASSERT(campus.conMismasSanciones(a2).Cardinal() == 3 );
	//cout << "salio2" << endl;
	ASSERT(campus.conMismasSanciones(a3).Cardinal() == 3 );
	//cout << "salio3" << endl;
	Nat c = campus.conKSanciones(1).Cardinal();
	//cout << "salio4" << endl;
	//cout << c << endl;
	ASSERT(c == 3);

	Nat c2 = campus.conKSanciones(0).Cardinal();
	ASSERT(c2 == 0 );


}

void test_mas_vigilante()
{
// 3 primeras lineas antes de que ingresen los estudiantes
//     1   2   3   4   5
// 1 | A |   | A |   | O
// 2 |   | A |   | O | 
// 3 ...
// Los hippies ingresan en (2,1) y (4,1) los huecos. El Agente en (3,1) se transforma en el mas vigilante	
	Driver campus;
	campus.crearCampus(10,10);

	Posicion o;
	o.x = 4; 
	o.y = 2;

	campus.agregarObstaculo(o);

	Posicion o2;
	o2.x = 5; 
	o2.y = 1;

	campus.agregarObstaculo(o2);


	Dicc<Agente,Posicion> agentes;
	Agente a = 1;
	Agente a2 = 2;
	Agente a3 = 3;

	Posicion p;
	p.x = 1;
	p.y = 1;

	Posicion p2;
	p2.x = 2;
	p2.y = 2;

	Posicion p3;
	p3.x = 3;
	p3.y = 1;

	agentes.Definir(a,p);
	agentes.Definir(a2,p2);
	agentes.Definir(a3,p3);

	campus.comenzarRastrillaje(agentes);

	Posicion ph;
	ph.x = 2;
	ph.y = 1;
	//cout << "ANTES: " << campus.cantHippiesAtrapados(a3) << endl; 
	Nombre h = "hippie";
	campus.ingresarHippie(h,ph);
	//cout << "DESPUES 1 HIPPIE: " << campus.cantHippiesAtrapados(a3) << endl; 
	Posicion ph2;
	ph2.x = 4;
	ph2.y = 1;

	Nombre h2 = "hippie2";
	campus.ingresarHippie(h2,ph2);
	//cout << "DESPUES 2 HIPPIE: " << campus.cantHippiesAtrapados(a3) << endl; 
	//cout << campus.cantHippiesAtrapados(a3) << endl; // da 1
	
	ASSERT(campus.cantHippiesAtrapados(a) == 1);
	ASSERT(campus.cantHippiesAtrapados(a2) == 1);
	ASSERT(campus.cantHippiesAtrapados(a3) == 2);

	ASSERT(campus.masVigilante() == a3);

}


int main(int argc, char **argv)
{
    RUN_TEST(test_agregar_obstaculos);
	RUN_TEST(test_ingresa_estudiante);
	RUN_TEST(test_ingresa_hippie_y_convierte);
	RUN_TEST(test_mueve_estudiante_y_convierte);
	RUN_TEST(test_mover_estudiante);
	RUN_TEST(test_mover_estudiante_fuera);
	RUN_TEST(test_ingresa_hippie);
	RUN_TEST(test_ingresa_hippie_y_estudiante);
	RUN_TEST(test_mover_hippie_a_estudiante);
	RUN_TEST(test_mover_hippie_a_ingreso);
	RUN_TEST(test_comenzar_rastrillaje_simple);
	RUN_TEST(test_rastrillaje_mover_hacia_hippie);
	RUN_TEST(test_captura_hippie_entre_agentes);
	RUN_TEST(test_captura_estudiante);
	RUN_TEST(test_mas_vigilante);
	/*RUN_TEST(test_hash);
	RUN_TEST(test_trie);*/

	/*RUN_TEST(test_agregar_obstaculos);
	RUN_TEST(test_ingresa_estudiante);
	RUN_TEST(test_mover_estudiante);
	RUN_TEST(test_mover_estudiante_fuera);
	RUN_TEST(test_ingresa_hippie);
	RUN_TEST(test_ingresa_hippie_y_estudiante);
	RUN_TEST(test_mover_hippie_a_estudiante);
	RUN_TEST(test_mover_hippie_a_ingreso);
	RUN_TEST(test_ingresa_hippie_y_convierte);
	RUN_TEST(test_mueve_estudiante_y_convierte);
	RUN_TEST(test_comenzar_rastrillaje_simple);
	RUN_TEST(test_rastrillaje_mover_hacia_hippie);
	RUN_TEST(test_captura_hippie_entre_agentes);
	RUN_TEST(test_captura_estudiante);
	RUN_TEST(test_mas_vigilante);*/


	/********************************************************************
	 * TODO: escribir casos de test exhaustivos para todas              *
	 * las funcionalidades de cada módulo.                              *
     * La interacción con el TAD principal se debe hacer exclusivamente *
	 * a través de la interfaz del driver.                              *
	 ********************************************************************/

	return 0;
}
