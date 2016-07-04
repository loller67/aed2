#ifndef  __DICCSTR__H__
#define  __DICCSTR__H__



#ifndef NULL
	#define NULL 0
#endif

#include "aed2/Arreglo.h"
#include "aed2/Lista.h"
#include <string>


using namespace aed2;
template<class S>
class Diccstr
{
	public:

		Diccstr();

		Diccstr(const Diccstr& jesus);

		~Diccstr();

		Diccstr<S>& operator=(const Diccstr<S>& jesus);

		const bool Definido(const std::string) const;

		S& Obtener(const std::string) const;

		const Lista<std::string> Claves() const;


		class Iterador{

			public:

				Iterador();

				Iterador(const typename Diccstr<S>::Iterador& otro);

				bool HaySiguiente() const;

				bool HayAnterior() const;

				const std::string& Siguiente() const;

				const std::string& Anterior() const;

				void Avanzar();

				void Retroceder();

			private:

				Lista<std::string>::Iterador it;

				Iterador(Diccstr<S>*);

				friend typename Diccstr<S>::Iterador Diccstr<S>::CrearIt();
		};

		Iterador Definir(const std::string& ,const S&);

		Iterador CrearIt();

	private:

		struct Nodo{

			typename Lista<S>::Iterador significado;

			Arreglo<Nodo>* avanzar;

			Nodo(): avanzar(NULL), significado() {};

		};

		Arreglo<Nodo>* comienzo;

		Lista<std::string> claves;

		Lista<S> significados;
		
		void AuxDestru(Arreglo<Nodo>*);


};


template<class S>
Diccstr<S>::Diccstr(): comienzo(NULL), claves(), significados()
{
}


template<class S>
Diccstr<S>::Diccstr(const Diccstr& jesus)
{
	comienzo = NULL;
	Lista<std::string>::const_Iterador it = jesus.claves.CrearIt();
	while( it.HaySiguiente()) {
		Definir(it.Siguiente(), jesus.Obtener(it.Siguiente()));
		it.Avanzar();
	}
}

template<class S>
Diccstr<S>& Diccstr<S>::operator=(const Diccstr<S>& jesus)
{
	comienzo = NULL;
	Lista<std::string>::const_Iterador it = jesus.claves.CrearIt();
	while( it.HaySiguiente()) {
		Definir(it.Siguiente(), jesus.Obtener(it.Siguiente()));
		it.Avanzar();
	}
	return *this;
		
}

template<class S>
Diccstr<S>::~Diccstr()
{
	if(comienzo != NULL){	
		AuxDestru(comienzo);
	}

}


template<class S>
void Diccstr<S>::AuxDestru(Arreglo<Nodo>* a)
{
	int i = 0;
	while( i < 256) {
                
		if((*a)[i].avanzar != NULL){
			Arreglo<Nodo>* aux = (*a)[i].avanzar;
			(*a)[i].avanzar = NULL;
			AuxDestru(aux);
			
		}
		i++;
	}
	delete a;
}


template<class S>
typename Diccstr<S>::Iterador Diccstr<S>::Definir(const std::string& k,const S& s)
{
	if(comienzo == NULL){
		Arreglo<Nodo>* a = new Arreglo<Nodo>(256);
		for(int f = 0; f < 256 ; f++){
			Nodo n;
			(*a).Definir(f, n);
		}	
		comienzo = a;	
	}
	Arreglo<Nodo>* aux = comienzo;
	int i = 0 ;
	while(i < k.length() - 1){
		if((*aux)[k[i]].avanzar == NULL){
			Arreglo<Nodo>* b = new Arreglo<Nodo>(256);
			for(int j = 0; j < 256 ; j++){
				Nodo n;
				(*b).Definir(j, n);
			}
			(*aux)[(int)k[i]].avanzar = b;
		}
		aux = (*aux)[(int)k[i]].avanzar;
		i++;
	}
	typename Lista<S>::Iterador it;
	it = significados.AgregarAdelante(s);
	(*aux)[(int)k[i]].significado = it;
	claves.AgregarAdelante(k);
	
	
	
	return CrearIt();
}


template<class S>
const bool Diccstr<S>::Definido(const std::string s) const
{
	int i =0;
	Arreglo<Nodo>* aux = comienzo;
	while(i< s.length() -1 && aux != NULL){
		aux = (*aux)[(int)s[i]].avanzar;
		i++;
	}
	if(aux != NULL){
		return (*aux)[(int)s[i]].significado.HaySiguiente();
	} else {
		return false;
	}
}


template<class S>
S& Diccstr<S>::Obtener(const std::string s) const
{
	Arreglo<Nodo>* aux = comienzo;
	int i = 0;
	while(i< s.length() - 1){
		aux = (*aux)[(int)s[i]].avanzar;
		i++;
	}
	return (*aux)[(int)s[i]].significado.Siguiente();
}


template<class S>
const Lista<std::string> Diccstr<S>::Claves() const
{
	return claves;
}


template<class S>
typename Diccstr<S>::Iterador Diccstr<S>::CrearIt()
{
	
	return Iterador(this);
}


//operaciones del iterador

template<class S>
Diccstr<S>::Iterador::Iterador() : it()
{
}


template<class S>
Diccstr<S>::Iterador::Iterador(const typename Diccstr<S>::Iterador& otro)
{
	it = otro.it; 
}


template<class S>
Diccstr<S>::Iterador::Iterador(Diccstr<S>* jesus)
{
	it = jesus->claves.CrearIt();
}


template<class S>
bool Diccstr<S>::Iterador::HaySiguiente() const
{
	return it.HaySiguiente();
}


template<class S>
bool Diccstr<S>::Iterador::HayAnterior() const
{
	return it.HayAnterior();
}


template<class S>
const std::string& Diccstr<S>::Iterador::Siguiente() const
{
	return it.Siguiente();
}


template<class S>
const std::string& Diccstr<S>::Iterador::Anterior() const
{
	return it.Anterior();
}


template<class S>
void Diccstr<S>::Iterador::Avanzar()
{
	it.Avanzar();
}


template<class S>
void Diccstr<S>::Iterador::Retroceder()
{
	it.Retroceder();
}

#endif	


