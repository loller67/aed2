#ifndef _CAMPUS_SEGURO_H_
#define _CAMPUS_SEGURO_H_

#include "aed2.h"
#include "campus.h"
#include "DiccHash.h"
#include "Diccstr.h" //si usamos dicc_trie no necesitamos este
#include "diccTrie.h"

using namespace aed2;

	class CampusSeguro
	{
		public:
			//constructor
			CampusSeguro(const Campus&, const Dicc<Agente, Posicion>&);  
			CampusSeguro();
			//destructor
			~CampusSeguro();
			
			//funciones
			Campus obtenerCampus(); //si le ponemos de nombre "campus" tira error, porque ya hay una variable llamada "campus"
			diccTrie<Posicion>::Iterador estudiantes();
			diccTrie<Posicion>::Iterador hippies();
			Conj<Agente>::Iterador agentes();
			Posicion posEstYHip(Nombre n);
			Posicion posAgente(Agente a);
			Nat cantSanciones(Agente a);
			Nat cantHippiesAtrapados(Agente a);
			//void ComenzarRastrillaje(Campus& c, Dicc<Agente, Posicion> d);
			void ingresarEstudiante(Nombre n, Posicion p);
			void ingresarHippie(Nombre n, Posicion p);
			void moverEstudiante(Nombre n, Direccion d);
			void moverHippie(const Nombre& n);
			void moverAgente(Agente a);
			Nat cantHippies();
			Nat cantEstudiantes();
			Agente masVigilante();
			Conj<Agente> conMismasSanciones(Agente a);
			Conj<Agente> conKSanciones(Nat k);
			
			
			
			void mostraMapa(int x, int y) {
				tupMapa tupla = Mapa[x][y];
				cout << x << " " << y;
				cout << " " << tupla.agente.p->agente << endl;
			}
			
			
			//operaciones
			//bool operator<(const Campus& c1) const;
			//bool operator!=(const Campus& c1) const;
			//bool operator==(const Campus& c1) const;

		private:
		
			typedef struct tupConjNat_t {
				//struct nodo_t 	*primero; NO BORRAR ESTE COMENTARIO
				Conj<Agente> conj;
				Nat sanc;
			} tupConjNat;
			
			typedef struct tupHash_t {
				void operator=(const tupHash_t& tup) {
					agente = tup.agente;
					pos = tup.pos;
					capturados = tup.capturados;
					sanciones = tup.sanciones;
					mSanc = tup.mSanc;
					lista = tup.lista;
				}
				Agente agente;
				Posicion pos;
				Nat capturados;
				Nat sanciones;
				Conj<Agente>::Iterador mSanc;
				Lista<tupConjNat>::Iterador lista;
			} tupHash;
			
			typedef struct tupMasVigilante_t {
				Agente ag;
				Nat cant;
			} tupMasVigilante;
			
			typedef struct tupItConjNat_t {
				Conj<Agente>::Iterador ag;
				Nat sanc;
			} tupItConjNat;
			
			typedef struct tupCantSanciones_t {
				tupCantSanciones_t() {
					lista = Lista<tupConjNat>();
					actualizar = false;
				}
				Lista<tupConjNat> lista;
				bool actualizar;
			} tupCantSanciones;
			
			typedef struct tupPersona_t {
				bool oc;
				Nombre n;
			} tupPersona;
			
			typedef struct tupAgente_t {
				bool oc;
				tupHash* p;
			} tupAgente;
			
			typedef struct tupMapa_t {
				tupPersona est;
				tupPersona hip;
				tupAgente agente;
				bool obstaculo;
			} tupMapa;
			

			Campus _campus;
			diccTrie<Posicion> Estudiantes;
			diccTrie<Posicion> Hippies;
			DiccHash<tupHash> AgentesD;
			Conj<Agente> AgentesC;
			tupMasVigilante MasVigilante;
			Vector<tupConjNat> sanciones;
			tupCantSanciones CantSanciones;
			Vector< Vector< tupMapa > > Mapa;
			
			//<Lista< Conj<Agente > conj, Nat sanc    > > CantSanciones;
			//Vector<Vector< < <bool oc, Nombre n > est, <bool oc, Nombre n > hip, < > agente 

			void ingresarEstudianteMagicamente(Nombre n, Posicion p);
			void ingresarHippieMagicamente(Nombre n, Posicion p);
			bool alMenos1Agente(Conj<Posicion> cp);
			bool alMenos2Hippies(Conj<Posicion> cp);
			bool todasLasVecinasOcupadas(Conj<Posicion> cp);
			bool todosEstudiantes(Conj<Posicion> cp);
			void muerteDelHippie(Nombre n);
			void seHaceHippie(Nombre n, Posicion p);
			void otorgarSanciones(Posicion p);
			void otorgarCapturas(Posicion p);
			Conj<Posicion> posicionesDeObjetivosDeHippies();
			Conj<Posicion> posicionesDeObjetivosDeAgentes();
			bool todasOcupadas(Conj<Posicion> cp);
			Nat busquedaBinaria(Vector<tupConjNat> v, Nat e);
			Nat busquedaDC(Vector<tupConjNat> v, Nat e,Nat bajo,Nat alto);
			void inicializarMapa(Nat _filas, Nat _columnas);
			void actualizarMapa(Nat x, Nat y, bool ocE, Nombre nE, bool ocH, Nombre nH, bool ocA, tupHash* puntHash, bool obs);
			void deletearMapa();
			
	};
#endif
