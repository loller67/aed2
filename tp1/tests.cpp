// g++ -g tests.cpp -o tests
// valgrind --leak-check=full -v ./tests

#include "mini_test.h"
#include "cartas_enlazadas.h"


template<typename T>
string to_s(const T& m) {
 	ostringstream os;
	os << m;
	return os.str();
 }

/*
 * Crea una mesa de int vacia y no agrega elementos
 */


void check_crear_mesa_vacia() {
	CartasEnlazadas<int> mesa;
	ASSERT_EQ(mesa.esVacia(), true);
	ASSERT_EQ(mesa.tamanio(), 0);
}
void listas_vacias_son_iguales(){
	CartasEnlazadas<int> j1;
	CartasEnlazadas<int> j2;
	ASSERT(j1==j2);
}
void listas_no_vacias_son_iguales(){
	CartasEnlazadas<int> juego1;
	CartasEnlazadas<int> juego2;
	
	juego1.agregarJugador(0);
	juego1.agregarJugador(1);
	juego1.agregarJugador(2);
	juego2.agregarJugador(0);
	juego2.agregarJugador(1);
	juego2.agregarJugador(2);
	ASSERT(juego1 == juego2);
}
void agregar_primer_jugador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	ASSERT_EQ(mesa.esVacia(), false);
	ASSERT_EQ(mesa.tamanio(), 1);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 1);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 1);
	
}
void agregar_mas_de_un_jugador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	ASSERT_EQ(mesa.esVacia(), false);
	ASSERT_EQ(mesa.tamanio(), 4);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 1);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 1);
	
}
void existe_jugador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(5);
	ASSERT_EQ(mesa.existeJugador(1), true);
	ASSERT_EQ(mesa.existeJugador(2), true);
	ASSERT_EQ(mesa.existeJugador(6), false);
	ASSERT_EQ(mesa.existeJugador(5), true);
	ASSERT_EQ(mesa.existeJugador(4), false);
}
 void constructor_por_copia_crea_bien(){
	CartasEnlazadas<int> mesa1;
	
	mesa1.agregarJugador(1);
	mesa1.agregarJugador(2);
	mesa1.agregarJugador(3);
	mesa1.agregarJugador(4);
	CartasEnlazadas<int> mesa2 = CartasEnlazadas<int>(mesa1);
	ASSERT_EQ(mesa2.tamanio(), 4);
	ASSERT_EQ(mesa2.dameJugadorConMazoRojo(), mesa1.dameJugadorConMazoRojo());
	ASSERT_EQ(mesa2.dameJugadorConMazoAzul(), mesa1.dameJugadorConMazoAzul());
	ASSERT(mesa1 == mesa2);
}
void adelantar_mazo_rojo(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);	
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.agregarJugador(5);
	mesa.agregarJugador(6);
	//con n positivo
	mesa.adelantarMazoRojo(1);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 6);
	mesa.adelantarMazoRojo(3);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 3);
	mesa.adelantarMazoRojo(2);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 1);
	mesa.adelantarMazoRojo(6);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 1);
	//con n negativo
	mesa.adelantarMazoRojo((-4));
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 5);
	mesa.adelantarMazoRojo((-1));
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 6);
	mesa.adelantarMazoRojo((-4));
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 4);
	mesa.adelantarMazoRojo((-1));
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 5);
	mesa.adelantarMazoRojo((-6));
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 5);
}
void adelantar_mazo_azul(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);	
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.agregarJugador(5);
	mesa.agregarJugador(6);
	//con n positivo
	mesa.adelantarMazoAzul(1);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 6);
	mesa.adelantarMazoAzul(3);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 3);
	mesa.adelantarMazoAzul(2);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 1);
	mesa.adelantarMazoAzul(6);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 1);
	//con n negativo
	mesa.adelantarMazoAzul((-4));
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 5);
	mesa.adelantarMazoAzul((-1));
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 6);
	mesa.adelantarMazoAzul((-4));
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 4);
	mesa.adelantarMazoAzul((-1));
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 5);
	mesa.adelantarMazoAzul((-6));
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 5);
}
void dame_jugador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);	
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.agregarJugador(5);
	mesa.agregarJugador(6);
	mesa.agregarJugador(7);
	//con el mazo en la primer posicion
	ASSERT_EQ(mesa.dameJugador(6), 2);
	ASSERT_EQ(mesa.dameJugador(3), 5);
	ASSERT_EQ(mesa.dameJugador(7), 1);
	ASSERT_EQ(mesa.dameJugador((-2)), 3);
	ASSERT_EQ(mesa.dameJugador((-5)), 6);
	ASSERT_EQ(mesa.dameJugador((-6)), 7);
	ASSERT_EQ(mesa.dameJugador((-7)), 1);
	//cambio de posicion al mazo
	mesa.adelantarMazoRojo(4);
	ASSERT_EQ(mesa.dameJugador(6), 5);
	ASSERT_EQ(mesa.dameJugador(3), 1);
	ASSERT_EQ(mesa.dameJugador(7), 4);
	ASSERT_EQ(mesa.dameJugador((-2)), 6);
	ASSERT_EQ(mesa.dameJugador((-5)), 2);
	ASSERT_EQ(mesa.dameJugador((-6)), 3);
	ASSERT_EQ(mesa.dameJugador((-7)), 4);
}
void dame_jugador_enfrentado(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.mostrarCartasEnlazadas(cout);
	ASSERT_EQ(mesa.dameJugadorEnfrentado(), 3);
	mesa.adelantarMazoRojo(1);
	mesa.mostrarCartasEnlazadas(cout);
	ASSERT_EQ(mesa.dameJugadorEnfrentado(), 2);
	mesa.agregarJugador(5);
	mesa.mostrarCartasEnlazadas(cout);
	mesa.agregarJugador(6);
	mesa.mostrarCartasEnlazadas(cout);
	ASSERT_EQ(mesa.dameJugadorEnfrentado(), 1);
	mesa.adelantarMazoRojo(1);
	mesa.mostrarCartasEnlazadas(cout);
	ASSERT_EQ(mesa.dameJugadorEnfrentado(), 6);
}
void sumar_puntos_al_jugador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	
	
	ASSERT_EQ(mesa.puntosDelJugador(1), 0);
	ASSERT_EQ(mesa.puntosDelJugador(2), 0);
	ASSERT_EQ(mesa.puntosDelJugador(3), 0);
	ASSERT_EQ(mesa.puntosDelJugador(4), 0);
	
	mesa.sumarPuntosAlJugador(1, 10);
	mesa.sumarPuntosAlJugador(2, 3);
	mesa.sumarPuntosAlJugador(3, 9);
	mesa.sumarPuntosAlJugador(4, 22);
	ASSERT_EQ(mesa.puntosDelJugador(1), 10);
	ASSERT_EQ(mesa.puntosDelJugador(2), 3);
	ASSERT_EQ(mesa.puntosDelJugador(3), 9);
	ASSERT_EQ(mesa.puntosDelJugador(4), 22);
}
void devolver_ganador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.sumarPuntosAlJugador(1, 10);
	mesa.sumarPuntosAlJugador(2, 3);
	mesa.sumarPuntosAlJugador(3, 9);
	mesa.sumarPuntosAlJugador(4, 22);
	ASSERT_EQ(mesa.ganador(), 4);
}
void imprimir_juego(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.adelantarMazoRojo(2);
	mesa.adelantarMazoAzul(2);
	mesa.agregarJugador(5);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 3);
	mesa.sumarPuntosAlJugador(1, 10);
	mesa.sumarPuntosAlJugador(2, 7);
	mesa.sumarPuntosAlJugador(3, 9);
	mesa.sumarPuntosAlJugador(4 ,12);
	mesa.sumarPuntosAlJugador(5, 99);
	
	/*
	std::ofstream os ("testmio");
	std::ofstream osMesa ("testjuego");
	if(os.is_open()){
		os << "[(1,10), (4,12), (3,9)*, (5,99), (2,7)]";
		os.close();
	}
	if(osMesa.is_open()){
		mesa.mostrarCartasEnlazadas(osMesa);
		osMesa.close();
	}
	//ASSERT(osMesa == os);*/
}
void eliminar_jugador(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	mesa.eliminarJugador(1);
	ASSERT_EQ(mesa.tamanio(), 3);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 4);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 4);
	mesa.eliminarJugador(3);
	ASSERT_EQ(mesa.tamanio(), 2);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 4);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 4);
	mesa.eliminarJugador(4);
	ASSERT_EQ(mesa.tamanio(), 1);
	ASSERT_EQ(mesa.dameJugadorConMazoRojo(), 2);
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 2);
	mesa.eliminarJugador(2);
}
void eliminar_juego(){
	CartasEnlazadas<int>* mesa = new CartasEnlazadas<int>();
	mesa->agregarJugador(1);
	mesa->agregarJugador(2);
	mesa->agregarJugador(3);
	mesa->agregarJugador(4);
	delete mesa;
}
void eliminar_jugador_mazo_azul(){
	CartasEnlazadas<int> mesa;
	mesa.agregarJugador(1);
	mesa.agregarJugador(2);
	mesa.agregarJugador(3);
	mesa.agregarJugador(4);
	
	ASSERT_EQ(mesa.tamanio(), 4);
	mesa.eliminarJugadorConMazoAzul();
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 4);
	ASSERT_EQ(mesa.tamanio(), 3);
	mesa.adelantarMazoAzul(1);
	mesa.eliminarJugadorConMazoAzul();
	ASSERT_EQ(mesa.dameJugadorConMazoAzul(), 2);
	ASSERT_EQ(mesa.tamanio(), 2);
	mesa.mostrarCartasEnlazadas(cout);
	ASSERT_EQ(mesa.tamanio(), 2);
}
int main() {
	RUN_TEST(check_crear_mesa_vacia);//funca 
	RUN_TEST(listas_vacias_son_iguales);//  funca
	RUN_TEST(listas_no_vacias_son_iguales);//  funca pm
	RUN_TEST(agregar_primer_jugador);//funca
	RUN_TEST(agregar_mas_de_un_jugador);//funca pm
	RUN_TEST(existe_jugador);//funca pm*/
	RUN_TEST(constructor_por_copia_crea_bien);
	RUN_TEST(adelantar_mazo_rojo);//funca
	RUN_TEST(adelantar_mazo_azul);//funca
	RUN_TEST(dame_jugador);//funca
	RUN_TEST(dame_jugador_enfrentado);//funca
	RUN_TEST(sumar_puntos_al_jugador);// funca
	RUN_TEST(devolver_ganador);// funca
	RUN_TEST(eliminar_jugador);//funca
	RUN_TEST(eliminar_juego);//funca 
	RUN_TEST(eliminar_jugador_mazo_azul);// funca 
	return 0;
}
