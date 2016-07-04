#ifndef dicc_Trie
#define dicc_Trie
#include <string>
#include <iostream>
using namespace std;

template<class T>
class diccTrie {
	private:
	
	typedef struct tupla_t {
		tupla_t() {
			
		}
		string clave;
		T significado;
	} tupla;
	
	struct Nodo {
		//Nodo();
		//~Nodo();
		T* valor;
		typename Lista<tupla>::Iterador clave;
		Arreglo<Nodo*> hijos;
	} ;
	
	Nodo* raiz;
	Lista<tupla> claves;
	
	Nodo* crearNodo() {
		Nodo* res = new Nodo();
		Arreglo<Nodo*> d = Arreglo<Nodo*>(256);
		/*
		int i = 0;
		while(i < 256) {
			d.Definir(i, NULL);
			i++;
		}
		*/ 
		//cout << "Res: " << res->hijos << endl;
		
		res->hijos = d;
		res->valor = NULL;
		res->clave = claves.CrearItUlt();
		//cout << "Nodo: " << res << endl;
		 
		return res;
	}
	
	public:
	
	diccTrie() { //constructor esta mal, hay que usar memoria dinamica, sino el nodo este por ejemplo, se borra al finalizar el scope
		//cout << "cons123";
		claves = Lista<tupla>();
		Nodo* n = crearNodo();
		raiz = n;
	}
	
	~diccTrie() {
		
		Nodo* p = raiz;
		borrarTodoArray(p->hijos);
		delete p;
	}
	
	void borrarTodoArray(Arreglo<Nodo*>& arreglo) {
		for(int i = 0; i < 256; i++) {
			if(arreglo.Definido(i) && arreglo[i] != NULL) {
				borrarTodoArray(arreglo[i]->hijos);
				delete arreglo[i]->valor;
				delete arreglo[i];
			}
		}
	}
	
	class Iterador {
		private:
			typename Lista<tupla>::const_Iterador it;
		
		public:
			Iterador(const diccTrie<T>& d) : it(d.claves.CrearIt()) {
				
			}
			
			void Avanzar() {
				it.Avanzar();
			}
			
			const tupla& Siguiente() const {
				return it.Siguiente();
			}
			
			bool HaySiguiente() const {
				return it.HaySiguiente();
			}
	};
	
	void definir(const string c, const T& s) {
		
		int i = 0;
		Nodo* p = raiz;
		
		while(i < c.length()) {
			//cout << "llego" << endl;
			
			if(! p->hijos.Definido((int) c[i])) {
				Nodo* n = crearNodo();
				p->hijos.Definir((int) c[i], n);
				p->valor = NULL; //esto no va creo
			}
			
			p = p->hijos[(int) c[i]];
			i++;
			//cout << p->valor;

		}

		p->valor = new T;
		*(p->valor) = s;
		tupla* tup = new tupla;
		tup->clave = c;
		tup->significado = s;
		claves.AgregarAtras(*tup);
		p->clave = claves.CrearItUlt();
	}
	
	T& obtener(const string c) const {
		int i = 0;
		Nodo* p = raiz;
		while(i < c.length()) {
			p = p->hijos[(int) c[i]];
			i++;
		}
		return *(p->valor);
	}
	
	bool definido(const string c) const{
		int i = 0;

		Nodo* p = raiz;
		while(i < c.length()) {
			if(p->hijos.Definido((int) c[i])) {
				p = p->hijos[(int) c[i]];
				i++;
			} else {
				return false;
			}
		}
		return (p->valor != NULL);
	}
	
	Iterador Claves() {
		return Iterador(*(this));
	}
	
	void borrar(const string c) {
		int i = 0;
		Nodo* p = raiz;
		while(i < c.length()) {
			p = p->hijos[(int) c[i]];
			i++;
		}
		delete p->valor;
		p->valor = NULL; //esto puede no llegar a andar si es que justo se toco esa parte de la memoria entre esta instruccion y la anterior.
		p->clave.EliminarAnterior(); // o eliminar siguiente, pero creo que es eliminar anterior por como los creamos
	}
	
	
};

#endif
