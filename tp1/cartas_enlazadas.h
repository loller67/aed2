#ifndef CARTAS_ENLAZADAS_H_
#define CARTAS_ENLAZADAS_H_

#include <iostream>
#include <cassert>
using namespace std;

/* 
 * Se puede asumir que el tipo T tiene constructor por copia y operator==
 * No se puede asumir que el tipo T tenga operator=
 */
template<typename T>
class CartasEnlazadas {

  public:

	/**
	 * Crea un nuevo juego.
	 */	
	CartasEnlazadas();

	/**
	 * Una vez copiada, ambos juegos deben ser independientes, 
	 * es decir, cuando se borre una no debe borrar la otra.
	 */	
	CartasEnlazadas(const CartasEnlazadas<T>&);
	
	/**
	 * Acordarse de liberar toda la memoria!
	 */	 
	~CartasEnlazadas();  
	
	/**
	* Agrega un jugador a la mesa. El mismo debe sentarse en la posición 
	* siguiente a la posición del jugador con el mazo azul. Por ejemplo si en la
	* mesa hay 3 jugadores sentados de la siguiente forma: [j1 j2 j3], y el 
	* mazo rojo lo tiene el jugador j3, la mesa debe quedar: [j1 j2 j3 j4].
	* PRE: el jugador a agregar no existe.
	*/
	void agregarJugador(const T&);
	
	/**
	* Adelanta el mazo rojo n posiciones. Por ejemplo: si en la mesa hay 3 
	* jugadores sentados de la siguiente forma: [j1 j2 j3] y el jugador j2
	* tiene el mazo rojo, si se adelanta 1 posicion el mazo rojo pasa al jugador j3. En
	* cambio si el mazo rojo se adelanta 2 posiciones el mazo rojo pasa al jugador j1.
	* En caso de que n sea negativo debe retroceder el mazo rojo -n posiciones.
	* PRE: existe al menos un jugador
	*/
	void adelantarMazoRojo(int n);
	
	/**
	* Adelanta el mazo azul n posiciones. Por ejemplo: si en la mesa hay 3 
	* jugadores sentados de la siguiente forma: [j1 j2 j3] y el jugador j2
	* tiene el mazo azul, si se adelanta 1 posicion el mazo azul pasa al jugador j3. En
	* cambio si el mazo azul se adelanta 2 posiciones el mazo azul pasa al jugador j1.
	* En caso de que n sea negativo debe retroceder el mazo azul -n posiciones.
	* PRE: existe al menos un jugador
	*/
	void adelantarMazoAzul(int n);
	
	/**
	* Devuelve el jugador que tiene el mazo Rojo actualmente.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugadorConMazoRojo() const;
	
	/**
	* Devuelve el jugador que tiene el mazo Azul actualmente.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugadorConMazoAzul() const;
	
	/**
	* Devuelve el jugador que se encuentra n posiciones adelante a la posicion 
	* del jugador con el mazo rojo. En caso de que n sea negativo deberia devolver 
	* el jugador que se encuentra -n posiciones atrás.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugador(int n) const;
	
	/**
	* Devuelve el jugador que se encuentra enfreantado al jugador que tiene el 
	* mazo rojo. Por ejemplo si en la mesa hay cuatros jugadores sentados de la
	* siguiente forma: [J1 J2 J3 J4] y el el jugador J2 tiene el mazo rojo, el
	* resultado debe ser J4.
	* PRE: cantidad de jugadores par, al menos un jugador
	*/
	const T& dameJugadorEnfrentado() const;
	
	/**
	* Elimina el jugador pasado como parámetro.
	* En el caso de que el jugador no exista, el método no debe hacer nada.
	* En el caso de que el jugador tenga algún mazo, se le pasa el mazo al 
	* siguiente jugador en la ronda.
	*/
	void eliminarJugador(const T&);
	
	/**
	* Elimina al jugador que tiene el mazo azul.
	* Por ejemplo si los jugadores estan sentadods de la siguiente forma: 
	* [J1 J2 J3 J4 J5] y el mazo lo tiene el jugador J3. Cuando se eliminan al 
	* jugador con  del mazo, la mesa * debería quedar de la siguiente forma 
	* [J1 J2 J4 J5].
	* En el caso de que algún jugador tenga algún mazo, se le pasa el mazo al 
	* siguiente jugador en la ronda.
	* PRE: al menos un jugador
	*/
	void eliminarJugadorConMazoAzul();
	
	/**
	* Dice si el jugador existe.
	*/
	bool existeJugador(const T&) const;

	/**
	* Le suma los puntos al jugador.
	* PRE: el jugador existe
	*/
	void sumarPuntosAlJugador(const T&, int);
	
	/**
	* Devuelve la cantidad de puntos que tiene el jugador pasado como 
	* parámetro.
	* PRE: el jugador existe
	*/
	int puntosDelJugador(const T&) const;
	
	/**
	* Devuelve al jugador que más puntos tiene.
	* PRE: hay un único jugador que tiene más puntos que todos los demás.
	*/
	const T& ganador() const;
	
	/*
	 * Dice si hay jugadores en la mesa.
	 */
	bool esVacia() const;

	/*
	 * Devuelve la cantidad de jugadores.
	 */
	int tamanio() const;	

	/*
	 * Devuelve true si los juegos son iguales.
	 */
	bool operator==(const CartasEnlazadas<T>&) const;	
	
	/*
	 * Debe mostrar la ronda por el ostream (y retornar el mismo).
	 * CartasEnlazadas vacio: []
	 * CartasEnlazadas con 1 elementos (e1 tiene el mazo azul y el rojo, p es el puntaje): [(e1,p)*]
	 * CartasEnlazadas con 2 elementos (e2 tiene el mazo azul y e1 el mazo rojo, p es el puntaje): [(e2,p), (e1,p)*]
	 * CartasEnlazadas con 3 elementos (e1 tiene el mazo, e3 fue agregado después que e2,
	 * e1 fue agregado antes que e2): [(e1, 0)*, (e3, 0), (e2, 0)]
	 */
	ostream& mostrarCartasEnlazadas(ostream&) const;
  private:
  
	/*
	 * No se puede modificar esta funcion.
	 */
	CartasEnlazadas<T>& operator=(const CartasEnlazadas<T>& otra) {
		assert(false);
		return *this;
	}

	/*
	 * Aca va la implementación del nodo.
	 */
    struct Nodo {
 		Nodo(T elem) : jugador(elem) {}
		T jugador;
		Nodo* anterior;
		Nodo* siguiente;
		int puntos;
	
    };


	Nodo* azul;
	Nodo* rojo;
	int longitud;
	
};


template<class T>
ostream& operator<<(ostream& out, const CartasEnlazadas<T>& a) {
	return a.mostrarCartasEnlazadas(out);
}

template<typename T>
CartasEnlazadas<T>::CartasEnlazadas()
	:rojo(NULL), azul(NULL), longitud(0){}

template<typename T>
CartasEnlazadas<T>::CartasEnlazadas(const CartasEnlazadas<T>& a){

	int i=0;
	this->azul=NULL;
	this->rojo= NULL;
	this->longitud=0;
	Nodo* nuevo=a.rojo;
	
	for(i=0;i<a.tamanio();i++){
		agregarJugador(nuevo->jugador);
		nuevo=nuevo->anterior;
		

	}
	this->longitud= a.tamanio();
	this->rojo->jugador = a.dameJugadorConMazoRojo();
	this->azul->jugador=a.dameJugadorConMazoAzul();
	
	Nodo* temp = this->rojo;
	Nodo* temp2 = a.rojo;

	
	for(i=0;i<a.tamanio();i++){
		temp->puntos = temp2->puntos;
		temp=temp->siguiente;
		temp2=temp2->siguiente;		


	}

	
	

}
template<typename T>
CartasEnlazadas<T>::~CartasEnlazadas(){


	if(!(this->longitud ==0)){


		int i=0;
		Nodo* nuevo = this->rojo;
		Nodo* eliminador = this->rojo;
		
		for(i=0;i<this->longitud;i++){
			nuevo= nuevo->siguiente;		
			delete eliminador;
			eliminador=nuevo;
			

		}

	}
	this->longitud=0;
}  
template<typename T>
void CartasEnlazadas<T>::agregarJugador(const T& a){
			
	if (this->longitud ==0){
	
		Nodo* nuevo = new Nodo(a);
		nuevo->puntos=0;
		nuevo->anterior = nuevo;
		nuevo->siguiente= nuevo;
		this->azul= nuevo;
		this->rojo = nuevo;	
		this->longitud = this->longitud+1;
		
		
		

	}else{
		Nodo* nuevo = new Nodo(a);
		nuevo->puntos=0;
		nuevo->siguiente=this->azul->siguiente;
		this->azul->siguiente->anterior= nuevo;
		nuevo->anterior= this->azul;
		this->azul->siguiente= nuevo; 
		this->longitud = this->longitud+1;
		
		
}

}
template<typename T>
void CartasEnlazadas<T>::adelantarMazoRojo(int n){


	if(n>0){

	int i=0;
	Nodo* nuevo = this->rojo;
	for(i=0;i<n;i++){

		nuevo=nuevo->siguiente;



	}

	this->rojo=nuevo;
	}else{

	int i=0;
	Nodo* nuevo = this->rojo;	
	for(i=0;i>n;i--){

		nuevo=nuevo->anterior;



	}

	this->rojo= nuevo;
}
	

}
template<typename T>
void CartasEnlazadas<T>::adelantarMazoAzul(int n){

	


	if(n>0){

	int i=0;
	Nodo* nuevo = this->azul;
	for(i=0;i<n;i++){

		nuevo=nuevo->siguiente;



	}

	this->azul=nuevo;
	}else{

	int i=0;
	Nodo* nuevo = this->azul;	
	for(i=0;i>n;i--){

		nuevo=nuevo->anterior;



	}

	this->azul= nuevo;
}

	
}
template<typename T>
const T& CartasEnlazadas<T>::dameJugadorConMazoRojo() const{

	return this->rojo->jugador;

}
template<typename T>
const T& CartasEnlazadas<T>::dameJugadorConMazoAzul() const{

	return this->azul->jugador;

}
template<typename T>
const T& CartasEnlazadas<T>::dameJugador(int n) const{


	if (n>=0){

		int i=0;
		Nodo* nuevo = this->rojo;
		for(i=0;i<n;i++){

			nuevo=nuevo->siguiente;
		
		}
		return nuevo->jugador;

				
	}else{


		int i=0;
		Nodo* nuevo = this->rojo;
		for(i=0;i>n;i--){

			nuevo=nuevo->anterior;


		}
		return nuevo->jugador;

	}

	


}
template<typename T>
const T& CartasEnlazadas<T>::dameJugadorEnfrentado() const{

	int i= this->longitud /2;
	Nodo* nuevo = this->rojo;
	for(i=this->longitud /2;i>0;i--){

		nuevo=nuevo->siguiente;


	}

	return nuevo->jugador;

}
template<typename T>
void CartasEnlazadas<T>::eliminarJugador(const T& a){

	Nodo* nuevo = this->rojo;
	int i=0;
	bool encontre = false;
	for(i=0;i<this->longitud && !encontre;i++){

		

		if(nuevo->jugador==a){

			this->longitud= this->longitud-1;
					
			if(this->azul->jugador== nuevo->jugador){

				this->azul=nuevo->siguiente;
			}

			if(this->rojo->jugador==nuevo->jugador){

				this->rojo=nuevo->siguiente;

			}

			Nodo* aux = nuevo;

			(aux->anterior)->siguiente= nuevo->siguiente;
			(aux->siguiente)->anterior = aux->anterior;
			delete nuevo;
			encontre=true;
		}
			if(!encontre){
			nuevo= nuevo->siguiente;
			}
			
	}
					
		
}



template<typename T>
void CartasEnlazadas<T>:: eliminarJugadorConMazoAzul(){

	int i=0;
	Nodo* nuevo = this->azul;

	if(this->rojo->jugador==nuevo->jugador){

		this->rojo=nuevo->siguiente;
	}

	this->azul=nuevo->siguiente;
	eliminarJugador(nuevo->jugador);




}
template<typename T>
bool CartasEnlazadas<T>::existeJugador(const T& a) const{

	
	bool res= false;
	int i=0;
	Nodo* nuevo = this->rojo;
	for(i=0;i<this->longitud;i++){
		

		if(nuevo->jugador==a){

			res= true;

		}

		nuevo=nuevo->siguiente;

	}
	
	return res;

}
template<typename T>
void CartasEnlazadas<T>::sumarPuntosAlJugador(const T& a, int n){

	
	int i=0;
	Nodo* nuevo = this->rojo;
	for(i=0;i<this->longitud; i++){

		if (nuevo->jugador== a){

		nuevo->puntos = nuevo->puntos + n;
		}

		nuevo=nuevo->siguiente;


	}


}

template<typename T>
int CartasEnlazadas<T>::puntosDelJugador(const T& a) const{


	int i=0;
	Nodo* nuevo = this->rojo;
	for(i=0;i<this->longitud; i++){

		if (nuevo->jugador== a){

		return nuevo->puntos;
		}

		nuevo=nuevo->siguiente;


	}

	

}
template<typename T>
const T& CartasEnlazadas<T>::ganador() const{

	int i =0;
	Nodo* nuevo = this->rojo;
	Nodo* campeon= this->rojo;
	int puntos= nuevo->puntos;

	for(i=0;i<this->longitud;i++){

		if(puntos < nuevo->siguiente->puntos){

			campeon= nuevo->siguiente;


		}
		nuevo= nuevo->siguiente;

	}
	return campeon->jugador;


}
template<typename T>
bool CartasEnlazadas<T>::esVacia() const{
	
	return (this->longitud == 0);

}
template<typename T>
int CartasEnlazadas<T>::tamanio() const{

	return this->longitud;

}
template<typename T>
bool CartasEnlazadas<T>::operator==(const CartasEnlazadas<T>& a) const{

	


	if (this->longitud==a.tamanio()){
		

		if(this->longitud==0){
			return true;
		}else{
		
		if(this->rojo->jugador==a.dameJugadorConMazoRojo() && this->azul->jugador==a.dameJugadorConMazoAzul()){

			int i =0;
			Nodo* nuevo = this->rojo;
			Nodo* nueva = a.rojo;

			for(i=0;i<this->longitud;i++){
				//cout <<this->longitud<<endl;
				//cout <<nuevo->jugador<<endl;
				//cout<<nueva->jugador<<endl;
				if(nuevo->jugador==nueva->jugador && nueva->puntos==nuevo->puntos ){

					
					nuevo=nuevo->siguiente;
					nueva=nueva->siguiente;
					

				}else{
				
					
					return false;
				}			




			}
			return true;

		
		}
		}

		}else{


		return false;

}

}
template<typename T>
ostream&  CartasEnlazadas<T>::mostrarCartasEnlazadas(ostream& os) const{
	os << "{";
	Nodo *nodo = this->rojo; 
	int i=0;
	for(i=0;i<this->longitud;i++) { 
		os << "(" << nodo->jugador << nodo->puntos << ")";
		 nodo = nodo->siguiente; 

		if(nodo->jugador== this->rojo->jugador){
		os << "mazo rojo" "(" << nodo->jugador << nodo->puntos << ")";

		}
		if(nodo->jugador== this->azul->jugador){

		os << "mazo azul" "(" << nodo->jugador << nodo->puntos << ")";
		}
		

	} 


	return os;
}
// Implementación a hacer por los alumnos.


#endif //CARTAS_ENLAZADAS_H_
