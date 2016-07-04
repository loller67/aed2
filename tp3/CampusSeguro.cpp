#include "CampusSeguro.h"
using namespace std;
#include <cassert>

//constructor
CampusSeguro::CampusSeguro(const Campus& c, const Dicc<Agente, Posicion>& d)

{
	_campus = c;
	
	//cout << "NO ENTRA" << endl;

	inicializarMapa(c.obtenerFilas(), c.obtenerColumnas());
	
	Nat cantidadAgentes = d.CantClaves();
	Agente menorPlaca;
	
	Dicc<Agente, Posicion>::const_Iterador it_const = d.CrearIt();
	if (cantidadAgentes > 0) menorPlaca = it_const.SiguienteClave();
	while(it_const.HaySiguiente()) {
		AgentesC.AgregarRapido(it_const.SiguienteClave());
		if(it_const.SiguienteClave() < menorPlaca) {
			menorPlaca = it_const.SiguienteClave();
		}
		it_const.Avanzar();
	}
	
	
	
	AgentesD = DiccHash<tupHash>(cantidadAgentes);
	
	//Lista<tupConjNat*>* lista = new Lista<tupConjNat*>();
	//Conj<Agente> conj; // = new Conj<Agente>();
	
	tupConjNat tuplaLista = {AgentesC, 0};
	Lista<tupConjNat>::Iterador itLista = CantSanciones.lista.AgregarAdelante(tuplaLista);
	CantSanciones.actualizar = false;
	
	//lista->AgregarAdelante(tuplaLista);
	//Lista<tupConjNat>::Iterador itLista = lista->CrearIt();
	
	
	
	Dicc<Agente, Posicion>::const_Iterador it = d.CrearIt();
	tupHash tupla;
	while(it.HaySiguiente()) {
		//cout << "NO ENTRA" << endl;
		tupla.agente = it.SiguienteClave();
		tupla.pos = it.SiguienteSignificado();
		tupla.capturados = 0;
		tupla.sanciones = 0;
		Conj<Agente>::Iterador it_agente = itLista.Siguiente().conj.CrearIt();
		while(!(it_agente.Siguiente() == it.SiguienteClave())) {
			it_agente.Avanzar();
		}
		tupla.mSanc = it_agente; //itLista.Siguiente().conj.AgregarRapido(it.SiguienteClave());
		//cout << "el agente es el: " << tupla.mSanc.Siguiente() << endl;
		//cout << "el agente es el: " << it.SiguienteClave() << endl;
		tupla.lista = itLista;
		//if(!diccH.definido(it.SiguienteClave()))
		AgentesD.definir(it.SiguienteClave(), tupla);
		
		tupHash* puntTup = AgentesD.significado(it.SiguienteClave()); //aca tira error porq parece q el puntero q me guardo es temporal, o sea que cdo termina la funcion desaparece. no se como arreglarlo
		//if(&tupla == puntTup) cout << "son iguales";
		//cout << it.SiguienteClave() << endl;

		actualizarMapa(it.SiguienteSignificado().x-1, it.SiguienteSignificado().y-1, false, "", false, "", true, puntTup, false);
		
		//cout << "en la pos 1,1 hay: " << endl;
		//cout << Mapa[it.SiguienteSignificado().x-1][it.SiguienteSignificado().y-1].agente.p->agente << endl;
		
		
		//(Mapa[it.SiguienteSignificado().x-1])[it.SiguienteSignificado().y-1] //= Ocupado; //hay que hacerlo con el agregar atras del vector porq tira error sino.
		//mostraMapa(it.SiguienteSignificado().x-1, it.SiguienteSignificado().y-1);
		/*if(it.SiguienteClave() < menorPlaca) {
			menorPlaca = it.SiguienteClave();
		}*/
		//diccH.mostrar();
		//cout << it.SiguienteClave() << endl;
		it.Avanzar();
	}

	//~ cout << "en la pos 1,1 hay: " << endl;
	//~ cout << Mapa[0][0].agente.p->agente << endl;
	
	//diccH.mostrar();

	MasVigilante.ag = menorPlaca;
	MasVigilante.cant = 0;
	//CantSanciones.lista = lista;
	//CantSanciones.actualizar = false;
	//Vector<tupConjNat> array;// = Vector<tupConjNat>();
	tupConjNat tuplita;
	tuplita.conj = itLista.Siguiente().conj;
	tuplita.sanc = 0;
	sanciones.AgregarAtras(tuplita);
	//Conj<Posicion>::Iterador itc = _campus->ocupadas.CrearIt(); //aca tira error porq estamos accediendo al campo 'ocupadas' del campus, cuando ese conjunto es privado. O hacer una funcion publica que devuelva ese conjunto (no me gusta), o recorrer todas las posiciones del mapa y preguntarle al campus si estan ocupadas, y si estan ocupadas hacer lo que se tenga que hacer en el while de abajo.
	/*posX = 0;
	posY = 0;
	Posicion p;
	while(posX < _campus->obtenerColumnas()) {              //ESTO NO VA
		while(posY < _campus->obtenerFilas()) {
			p.x = posX + 1;
			p.y = posY + 1;
			if(_campus->ocupada(p)) {
				tupPersona tup1;
				tupPersona tup2;
				tupAgente tup3;
				tup1.oc = false;
				tup1.n = "";
				tup2.oc = false;
				tup2.n = "";
				tup3.oc = false;
				tup3.p = NULL;
				tupMapa Ocupado;
				Ocupado.est = tup1;
				Ocupado.hip = tup2;
				Ocupado.agente = tup3;
				Ocupado.obstaculo = true;
				(Mapa[posX])[posY] = Ocupado;
			}
			posY = posY + 1;
		}
		posX = posX + 1;
	}*/
	/*cout << endl;
	mostraMapa(1,1);
	cout << endl;
	mostraMapa(0,0);
	cout << "asd" << endl;
	mostraMapa(2,0);*/
	
}



/*
 * 
 * _campus = c;
	
	inicializarMapa(c.obtenerFilas(), c.obtenerColumnas());
	
	
	Nat cantidadAgentes = d.CantClaves();
	
	Lista<tupConjNat>* lista = new Lista<tupConjNat>();
	Conj<Agente>* conj = new Conj<Agente>();
	
	tupConjNat* tupla = new tupConjNat;
	tupla->conj = *conj;
	tupla->sanc = 0;
	
	lista->AgregarAdelante(*tupla);
	Lista<tupConjNat>::Iterador itLista = lista->CrearIt();
	DiccHash<tupHash>* diccH = new DiccHash<tupHash>(cantidadAgentes);
	Agente menorPlaca;
	
	Dicc<Agente, Posicion>::const_Iterador it = d.CrearIt();
	
	if (cantidadAgentes > 0) menorPlaca = it.SiguienteClave();
	while(it.HaySiguiente()) {
		tupHash tupla;
		tupla.agente = it.SiguienteClave();
		tupla.pos = it.SiguienteSignificado();
		tupla.capturados = 0;
		tupla.sanciones = 0;
		tupla.mSanc = itLista.Siguiente().conj.AgregarRapido(it.SiguienteClave());
		
		tupla.lista = itLista;
		//if(!diccH.definido(it.SiguienteClave()))
		diccH->definir(it.SiguienteClave(), tupla);
		
		tupHash* puntTup = diccH->significado(it.SiguienteClave()); //aca tira error porq parece q el puntero q me guardo es temporal, o sea que cdo termina la funcion desaparece. no se como arreglarlo
		//if(&tupla == puntTup) cout << "son iguales";
		//cout << it.SiguienteClave() << endl;

		actualizarMapa(it.SiguienteSignificado().x-1, it.SiguienteSignificado().y-1, false, "", false, "", true, puntTup, false);
		
		//cout << "en la pos 1,1 hay: " << endl;
		//cout << Mapa[it.SiguienteSignificado().x-1][it.SiguienteSignificado().y-1].agente.p->agente << endl;
		
		
		//(Mapa[it.SiguienteSignificado().x-1])[it.SiguienteSignificado().y-1] //= Ocupado; //hay que hacerlo con el agregar atras del vector porq tira error sino.
		//mostraMapa(it.SiguienteSignificado().x-1, it.SiguienteSignificado().y-1);
		if(it.SiguienteClave() < menorPlaca) {
			menorPlaca = it.SiguienteClave();
		}
		//diccH.mostrar();
		//cout << it.SiguienteClave() << endl;
		it.Avanzar();
	}

	//~ cout << "en la pos 1,1 hay: " << endl;
	//~ cout << Mapa[0][0].agente.p->agente << endl;
	
	//diccH.mostrar();
	AgentesD = *diccH;
	Conj<Agente> conjunto_agentes;
	Dicc<Agente, Posicion>::const_Iterador it_const = d.CrearIt();
	while(it_const.HaySiguiente()) {
		conjunto_agentes.AgregarRapido(it_const.SiguienteClave());
		it_const.Avanzar();
	}
	AgentesC = conjunto_agentes; //Claves no existe! jajaj ver como obtener las claves del conjunto lineal pasado por parametro. EDIT: creo que ya lo arregle (eze)
	MasVigilante.ag = menorPlaca;
	MasVigilante.cant = 0;
	CantSanciones.lista = *lista;
	CantSanciones.actualizar = false;
	Vector<tupItConjNat> array = Vector<tupItConjNat>();
	tupItConjNat tuplita;
	tuplita.ag = itLista.Siguiente().conj.CrearIt();
	tuplita.sanc = 0;
	array.AgregarAtras(tuplita);
	sanciones = array;
	//Conj<Posicion>::Iterador itc = _campus->ocupadas.CrearIt(); //aca tira error porq estamos accediendo al campo 'ocupadas' del campus, cuando ese conjunto es privado. O hacer una funcion publica que devuelva ese conjunto (no me gusta), o recorrer todas las posiciones del mapa y preguntarle al campus si estan ocupadas, y si estan ocupadas hacer lo que se tenga que hacer en el while de abajo.
	posX = 0;
	posY = 0;
	Posicion p;
	while(posX < _campus->obtenerColumnas()) {              //ESTO NO VA
		while(posY < _campus->obtenerFilas()) {
			p.x = posX + 1;
			p.y = posY + 1;
			if(_campus->ocupada(p)) {
				tupPersona tup1;
				tupPersona tup2;
				tupAgente tup3;
				tup1.oc = false;
				tup1.n = "";
				tup2.oc = false;
				tup2.n = "";
				tup3.oc = false;
				tup3.p = NULL;
				tupMapa Ocupado;
				Ocupado.est = tup1;
				Ocupado.hip = tup2;
				Ocupado.agente = tup3;
				Ocupado.obstaculo = true;
				(Mapa[posX])[posY] = Ocupado;
			}
			posY = posY + 1;
		}
		posX = posX + 1;
	}*/
	/*cout << endl;
	mostraMapa(1,1);
	cout << endl;
	mostraMapa(0,0);
	cout << "asd" << endl;
	mostraMapa(2,0);*/
	

//destructor
CampusSeguro::~CampusSeguro(){
	//delete AgentesD;
	/*Lista<tupConjNat*>* lista = CantSanciones.lista; 
	Lista<tupConjNat*>::Iterador it = lista->CrearIt();
	while(it.HaySiguiente()){
		delete it.Siguiente()->conj;
		delete it.Siguiente();
		it.Avanzar();
	}
	//::Iterador it 
	delete CantSanciones.lista;*/
	
	/*
	 * 
	 * tupConjNat* t = new tupConjNat; //esto estaba con new antes
												cout << "wiiiiiii" << endl;

				Conj<Agente>* agen = new Conj<Agente>();
												cout << "wiiiiiii" << endl;
				t->conj = agen;
								cout << "wiiiiiii" << endl;

				t->sanc = tupla->sanciones;
				tupla->mSanc= t->conj->AgregarRapido(ag);
				tupla->lista.AgregarComoSiguiente(t);
				
	
	tupHash* tupla = AgentesD->significado(*ag);
				tupla->lista.AgregarComoSiguiente(t);*/
}

void CampusSeguro::deletearMapa() {
	/*Nat posX = 0;
	Nat posY;
	while(posX < _campus->obtenerColumnas()) {
		posY = 0;
		while(posY < _campus->obtenerFilas()) {
			delete &Mapa[posX][posY].est;
			delete &Mapa[posX][posY].hip;
			delete &Mapa[posX][posY].agente;
			delete &Mapa[posX][posY];
			posY++;
		}
		delete &Mapa[posX];
	}*/
}

void CampusSeguro::inicializarMapa(Nat _filas, Nat _columnas) {
	Nat posX = 0;
	Nat posY;
	while(posX < _columnas) { //tal vez es primero while de filas, y dsp de columnas
		Vector<tupMapa> vector = Vector<tupMapa>();
		posY = 0;
		while(posY < _filas) {
			tupPersona tup1 = {false, ""};
			tupPersona tup2 = {false, ""};
			tupAgente tup3 = {false, NULL};
			tupMapa Libre = {tup1, tup2, tup3, false};
			vector.AgregarAtras(Libre); //VER SI LAS FILAS SON FILAS Y LAS COLUMNAS SON COLUMNAS O ES AL REVES.. POR COMO LAS CREO
			posY++;
		}
		Mapa.AgregarAtras(vector);
		posX++;
	}
}

void CampusSeguro::actualizarMapa(Nat x, Nat y, bool ocE, Nombre nE, bool ocH, Nombre nH, bool ocA, tupHash* puntHash, bool obs) {
	Mapa[x][y].est.oc = ocE;
	Mapa[x][y].est.n = nE;
	Mapa[x][y].hip.oc = ocH;
	Mapa[x][y].hip.n = nH;
	Mapa[x][y].agente.oc = ocA;
	Mapa[x][y].agente.p = puntHash;
	Mapa[x][y].obstaculo = obs;
}

//funciones
Campus CampusSeguro::obtenerCampus() {
	return _campus;
}

diccTrie<Posicion>::Iterador CampusSeguro::estudiantes() {
	/* dicc_trie esta mal hecho entonces no puede iterar diccionarios vacios */
	//DiccString<Posicion>::Iterador it(&Estudiantes); //cosas raras del trie
	diccTrie<Posicion>::Iterador it = Estudiantes.Claves();
	return it;
	//return Estudiantes.Claves();
}


diccTrie<Posicion>::Iterador CampusSeguro::hippies() {
	//DiccString<Posicion>::Iterador it(&Hippies); //cosas raras del trie
	diccTrie<Posicion>::Iterador it = Hippies.Claves();
	return it;
	//return Hippies.Claves();
}


Conj<Agente>::Iterador CampusSeguro::agentes() {
	return AgentesC.CrearIt();
}

Posicion CampusSeguro::posEstYHip(Nombre n) {
	if(Estudiantes.definido(n)) {
		return Estudiantes.obtener(n);
	} else {
		return Hippies.obtener(n);
	}
}


Posicion CampusSeguro::posAgente(Agente a) {
	return AgentesD.significado(a)->pos;
}


Nat CampusSeguro::cantSanciones(Agente a) {
	return AgentesD.significado(a)->sanciones;
}


Nat CampusSeguro::cantHippiesAtrapados(Agente a) {
	return AgentesD.significado(a)->capturados;
}


void CampusSeguro::ingresarEstudiante(Nombre n, Posicion p) {
	/*tupHash* puntTup1 = AgentesD->significado(1);
	tupHash* puntTup2 = AgentesD->significado(2);
	tupHash* puntTup3 = AgentesD->significado(3);
	cout << "EST: el agente 1 es el: " << puntTup1->agente << endl;
	cout << "EST: el agente 1 es el: " << puntTup1->mSanc.Siguiente() << endl;
	cout << "EST: el agente 2 es el: " << puntTup2->agente << endl;
	cout << "EST: el agente 2 es el: " << puntTup2->mSanc.Siguiente() << endl;
	cout << "EST: el agente 3 es el: " << puntTup3->agente << endl;
	cout << "EST: el agente 3 es el: " << puntTup3->mSanc.Siguiente() << endl;*/
	ingresarEstudianteMagicamente(n, p);
}


void CampusSeguro::ingresarHippie(Nombre n, Posicion p) {
	//cout <<"a"<<endl;
	/*cout << "en la pos 1,1 hay: " << endl;
	int s = 2;
	s = 4;
	cout << Mapa[1][1].agente.oc << endl;*/
	//cout << "en la pos 1,1 hay: " << endl;
	//cout << Mapa[0][0].agente.p->agente << endl;
 	ingresarHippieMagicamente(n, p);
 	
}

void CampusSeguro::ingresarHippieMagicamente(Nombre n, Posicion p) {
	//mostraMapa(1,1);
	Conj<Posicion> vecinasLegales = _campus.vecinosValidos(_campus.vecinos(p)); //las posiciones adyacentes estan bien!cout  << "a"<<  endl;
	
	Conj<Posicion>::Iterador it = vecinasLegales.CrearIt();
	
	bool sinEscapatoria = todasLasVecinasOcupadas(vecinasLegales);
	
	bool seNerdiza = todosEstudiantes(vecinasLegales);
	
	bool muere = (sinEscapatoria && alMenos1Agente(vecinasLegales));
	bool noSeNerdizaYQueda = (!seNerdiza && !muere); //todos los bools estan bien!
	//cout << sinEscapatoria << seNerdiza << muere << noSeNerdizaYQueda << endl;
	
	seHaceHippie(n,p);
	/*cout << "en la pos 1,1 hay: " << endl;
	cout << Mapa[0][0].agente.p->agente << endl;*/
	//cout << cantHippies() << cantEstudiantes(); //estos andan bien (las funciones)
	while(it.HaySiguiente()){
		
		Conj<Posicion> vecinasDeEstaVecina = _campus.vecinosValidos(_campus.vecinos(it.Siguiente()));
		
		//Conj<Posicion>::Iterador it_adentro = vecinasDeEstaVecina.CrearIt();
		/*while(it_adentro.HaySiguiente()) {
			cout << "(" << it_adentro.Siguiente().x << "," << it_adentro.Siguiente().y << ")," << endl;;
			it_adentro.Avanzar();
		}
		cout << endl;*/ //ESTO ANDA, DA LAS ADYACENTES VALIDAS POSTA
		if ((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.oc == true){ 
			//cout << "esto no deberia aparecer nunca!"; //muy bien!
			if(todasLasVecinasOcupadas(vecinasDeEstaVecina)){
				
				if(alMenos1Agente(vecinasDeEstaVecina)){
					muerteDelHippie((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.n); //it es un iterador de conj<posicion>, no tiene campo nombre y pos, sino que tiene campo x e y
					otorgarCapturas(it.Siguiente());
				}
			}
		}
		else{
			if ((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].est.oc == true){
				//cout << "tres veces, "; //esto anda!
				if(alMenos2Hippies(vecinasDeEstaVecina)){
					//cout << "esto no deberia aparecer parte 2" << endl;
					seHaceHippie((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].est.n, it.Siguiente());
					if(todasLasVecinasOcupadas(vecinasDeEstaVecina)){
						otorgarSanciones(it.Siguiente());
						if(alMenos1Agente(vecinasDeEstaVecina)){
							muerteDelHippie((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.n);
							otorgarCapturas(it.Siguiente());
						}
					}
				}
			}
		}
		it.Avanzar();
	}
	
		
	
	if(seNerdiza) {
		muerteDelHippie(n);
		Estudiantes.definir(n, p);
		actualizarMapa(p.x-1,p.y-1,true,n,false,"",false,NULL, false);
	}
	else{
		if(! noSeNerdizaYQueda){
			muerteDelHippie(n);
			otorgarCapturas(p);
		}
	}
	
	//cout << cantHippies() << cantEstudiantes();
	
}

void CampusSeguro::ingresarEstudianteMagicamente(Nombre n, Posicion p) {
	Conj<Posicion> vecinasLegales = _campus.vecinosValidos(_campus.vecinos(p));
	Conj<Posicion>::const_Iterador it = vecinasLegales.CrearIt();
	bool sinEscapatoria = todasLasVecinasOcupadas(vecinasLegales);
	bool muere = (sinEscapatoria && alMenos1Agente(vecinasLegales));
	bool seEnhippiza = alMenos2Hippies(vecinasLegales);
	bool seEnhippizaYQueda = (seEnhippiza && !muere);
	Estudiantes.definir(n, p);
	

		
	actualizarMapa(p.x-1,p.y-1,true,n,false,"",false,NULL,false);
	
	
	while(it.HaySiguiente()){
		Conj<Posicion> vecinasDeEstaVecina = _campus.vecinosValidos(_campus.vecinos(it.Siguiente()));
		if ((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.oc == true){
			if(todasLasVecinasOcupadas(vecinasDeEstaVecina)){
				if(alMenos1Agente(vecinasDeEstaVecina)){
					muerteDelHippie((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.n);
					otorgarCapturas(it.Siguiente());
				}
				else{
					if(todosEstudiantes(vecinasDeEstaVecina)){
						Posicion pos = it.Siguiente();
						Estudiantes.definir((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.n, pos); //creo que tira error porque el nombre del hippie no es const, y el trie necesita que sea const
						(Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].est.oc = true;
						(Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].est.n = (Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.n; // estudiante con el nombre de it.Sigiente() en hippie
						muerteDelHippie((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].hip.n);
					}
				}
			}
		}
		else{
			if ((Mapa[it.Siguiente().x - 1])[it.Siguiente().y - 1].est.oc == true){
				if(todasLasVecinasOcupadas(vecinasDeEstaVecina)){
					otorgarSanciones(it.Siguiente());
				}
			}
		}
		it.Avanzar();
	}
	if (!seEnhippiza){
		if(sinEscapatoria){
			//cout << "entra" << endl;
			otorgarSanciones(p);
		}
	}
	else{
		if(seEnhippizaYQueda){
			if(sinEscapatoria){
				
				otorgarSanciones(p);
			}
			seHaceHippie(n,p);
		}
		else{
			otorgarSanciones(p);
			otorgarCapturas(p);
			seHaceHippie(n,p);
			muerteDelHippie(n);
		}
	}
}

bool CampusSeguro::alMenos1Agente(Conj<Posicion> cP){
	Conj<Posicion>::Iterador it = cP.CrearIt();
	Nat cantAgentes = 0;
	while(it.HaySiguiente()){
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc){
			cantAgentes++;
		}
		it.Avanzar();
	}
	return (cantAgentes >= 1);
}

bool CampusSeguro::alMenos2Hippies(Conj<Posicion> cP){
	Conj<Posicion>::Iterador it = cP.CrearIt();
	Nat cantHippies = 0;
	while(it.HaySiguiente()){
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].hip.oc){
			cantHippies++;
		}
		it.Avanzar();
	}
	return (cantHippies >= 2);
}

bool CampusSeguro::todasLasVecinasOcupadas(Conj<Posicion> cP){
	Conj<Posicion>::Iterador it = cP.CrearIt();
	Nat posLibres = 0;
	Posicion p;
	while(it.HaySiguiente()){
		p.x = it.Siguiente().x;
		p.y = it.Siguiente().y;
		if ((Mapa[p.x-1])[p.y-1].est.oc == false && (Mapa[p.x-1])[p.y-1].hip.oc == false && (Mapa[p.x-1])[p.y-1].agente.oc == false && !_campus.ocupada(p)){
			posLibres++;
		}
		it.Avanzar();
	}
	return (posLibres == 0);
}

bool CampusSeguro::todosEstudiantes(Conj<Posicion> cP){
	Conj<Posicion>::Iterador it = cP.CrearIt();
	Nat cantEstudiantes = 0;
	while(it.HaySiguiente()){
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].est.oc){
			cantEstudiantes++;
		}
		it.Avanzar();
	}
	return (cantEstudiantes == cP.Cardinal());
}

void CampusSeguro::moverEstudiante(Nombre n, Direccion d) {
	Posicion posActual = (Estudiantes.obtener(n)); //por copia
	Posicion posResultante = _campus.proxPosicion(posActual,d);
	Estudiantes.borrar(n);
	tupPersona tupla;
	tupla.oc = false;
	tupla.n = "";
	(Mapa[posActual.x-1])[posActual.y-1].est = tupla; //<false,"">; //hay que poner que la posicion en el mapa esta libre
	if(_campus.posValida(posResultante)){
		ingresarEstudianteMagicamente(n, posResultante);
	}
}

void CampusSeguro::muerteDelHippie(Nombre n){
	Posicion pos = (Hippies.obtener(n)); // por copia, o sea, se copia lo desreferenciado
	Hippies.borrar(n);
	actualizarMapa(pos.x-1, pos.y-1, false, "", false, "", false, NULL, false);
}

void CampusSeguro::seHaceHippie(Nombre n, Posicion p){
	
	if(Estudiantes.definido(n)){
		Estudiantes.borrar(n);
	}
	//cout << "en la pos 1,1 hay: " << endl;
	//cout << Mapa[0][0].agente.p->agente << endl;
	Hippies.definir(n,p);
	//cout << "en la pos 1,1 hay: " << endl;
	//cout << Mapa[0][0].agente.p->agente << endl;
	
	actualizarMapa(p.x-1,p.y-1,false,"",true,n,false,NULL,false);
	
	//(Mapa[p.x-1])[p.y-1] = Ocupado; //<<false,"">,<true,"n">,<false,NULL>,false>; // revisar, la idea es con n como nombre del hippie.
	
	/*if (Mapa.Definido(p.x-1)){
		if (Mapa[p.x-1].Definido(p.y-1)){
			(Mapa[p.x-1])[p.y-1] = Ocupado; //<<false,"">,<true,"n">,<false,NULL>,false>; // revisar, la idea es con n como nombre del hippie.
		}
		else{
			Mapa[p.x-1].Definir(p.y-1, Ocupado);
		}
	}
	else{
		Arreglo(obtenerCampus().obtenerColumnas()) arreglo;
		arreglo.Definir(p.y-1, Ocupado);
		Mapa.Definir(p.x-1, arreglo);
	}*/
}

void CampusSeguro::otorgarSanciones(Posicion p){// EL CONJUNTO DE CADA NODO DE LA LISTA TIENE ITERADORES QUE NO SE ACTUALIZAN, SOLO ACTUALIZAMOS EL ITERADOR A UN ELEMENTO DEL CONJUNTO, TENEMOS QUE RECORRER TODO EL CONJUNTO PARA ACTUALIZAR LOS ITERADORES
	Conj<Posicion> vecinasLegales = _campus.vecinosValidos(_campus.vecinos(p));
	Conj<Posicion>::Iterador it = vecinasLegales.CrearIt();
	//cout << "hola?" << endl;
	while(it.HaySiguiente()){
		//cout << "hola2?" << endl;
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc){
			//cout << "hayagente?" << endl;
			CantSanciones.actualizar = true;
			Agente ag;// = new Agente;  //hay que ver si es con new o no..... mepa q no pero bueno
			ag = Mapa[it.Siguiente().x-1][it.Siguiente().y-1].agente.p->agente;
			//cout << "ya se cago?" << endl;
			//cout << *ag << it.Siguiente().x << it.Siguiente().y << endl;
			tupHash* tupla = AgentesD.significado(ag);
			//cout << tupla->pos.x << tupla->pos.y << tupla->agente << endl;
			tupla->sanciones++;
			//cout << "que me dices de esta?" << endl;
			//cout << tupla->mSanc.Siguiente() << endl;//tupla->mSanc.Siguiente();
			//cout << "asd?" << endl;
			tupla->mSanc.EliminarSiguiente();
			//cout << "entro" << endl;
			if(!tupla->mSanc.HaySiguiente() && !tupla->mSanc.HayAnterior()) {
				//cout << "elimino a el nodo de lista" << endl;
				//delete tupla->lista.Siguiente().conj;
				tupla->lista.EliminarSiguiente();
			}
			//cout << "llego!!" << endl;
			else {
			tupla->lista.Avanzar();}
			
			if(tupla->lista.HaySiguiente() && tupla->lista.Siguiente().sanc==tupla->sanciones) { //hay un nodo siguiente y ademas tiene la cant sanciones nuevas
				//cout << "lalala" << endl;
				//cout << "existe el nodo de la lista" << endl;
				tupla->mSanc= tupla->lista.Siguiente().conj.AgregarRapido(ag);
				//tupla->lista.Avanzar();
				//cout << "LO PASOS" << endl;
			} 
			else 
			{
				//cout << "no exite el nodo, CREO NODO" << endl;
				//tupla->lista.Retroceder();
				//cout << " OOOO lalala" << endl;
				tupConjNat t;// = new tupConjNat; //esto estaba con new antes
												//cout << "wiiiiiii" << endl;

				Conj<Agente> agen;// = new Conj<Agente>();
												//cout << "wiiiiiii" << endl;
				t.conj = agen;
								//cout << "wiiiiiii" << endl;

				t.sanc = tupla->sanciones;
				tupla->mSanc= t.conj.AgregarRapido(ag);
				tupla->lista.AgregarComoSiguiente(t);
				//tupla->lista.Avanzar();
				/*delete t;
				delete agen;*/
				
			}
		}
		it.Avanzar();
	}
	//cout << "termino otorgar sanciones" << endl;
}				
/*
 * 
 * Conj<Agente> actualizable = tupla-> lista.Siguiente().conj;// TENGO EL CONJUNTO DE TODOS LOS AGENTES
			Conj<Agente>::Iterador it2= actualizable.CrearIt();     //TODO ESTO SE HACE UNA VEZ QUE SE CREA EL NODO DE LA LISTA
			while(it2.HaySiguiente()){
				
				Lista<tupConjNat>::Iterador iteraLista = AgentesD->significado(it2.Siguiente())->lista.CrearIt(); 
				while
			}
			* 
			* */

void CampusSeguro::otorgarCapturas(Posicion p){
	Conj<Posicion> vecinasLegales = _campus.vecinosValidos(_campus.vecinos(p));
	Conj<Posicion>::Iterador it = vecinasLegales.CrearIt();
	
	//AgentesD.mostrar();
	while(it.HaySiguiente()){
		
		
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc) {
			Agente ag = (Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.p->agente;
			tupHash* tupla = AgentesD.significado(ag);
			tupla->capturados++;
			if(tupla->capturados > MasVigilante.cant){
				MasVigilante.cant = tupla->capturados;
				MasVigilante.ag = ag;
			}
			else{
				if(tupla->capturados==MasVigilante.cant && ag <MasVigilante.ag ){
					MasVigilante.ag = ag;		
				} //LUCA TE OLVIDASTE DE PONER ESTA LLAVE Y ESTUVE HORAS BUSCANDO ESTE ERROR, SOS UN FORRO				
			}
		}
		it.Avanzar();
	}
}


/*

Habria que poner esto en algun lado:
enum identificacion
{
nombre, placa
};
* struct identificacion {
* 	string nombre;
* int placa;
* }
* identificacion variable;
* variable.nombre = "asd";

identificacion variable;
* 
* variable = nombre;
* variable = placa;
* if(variable == nombre) {
* 
* asdd
* }
*/

Conj<Posicion> CampusSeguro::posicionesDeObjetivosDeHippies(){
	Conj<Posicion> res;
	diccTrie<Posicion>::Iterador it = Estudiantes.Claves();
	
	while(it.HaySiguiente()){
			res.AgregarRapido(Estudiantes.obtener(it.Siguiente().clave));
			it.Avanzar();
		}
	return res;
}

Conj<Posicion> CampusSeguro::posicionesDeObjetivosDeAgentes(){
	Conj<Posicion> res;
	diccTrie<Posicion>::Iterador it = Hippies.Claves();
	while(it.HaySiguiente()){
			res.AgregarRapido(Hippies.obtener(it.Siguiente().clave));
			it.Avanzar();
		}
	return res;
}

void CampusSeguro::moverHippie(const Nombre& n) {
	Posicion posActual = Hippies.obtener(n);
	diccTrie<Posicion>::Iterador it2 = Estudiantes.Claves();
	//DiccString<Posicion>::Iterador it2(&Estudiantes);
	Conj<Posicion> masCercanos;
	if (it2.HaySiguiente()){
		Conj<Posicion> objetivos = posicionesDeObjetivosDeHippies();
		Posicion p = _campus.posicionMinimaDistancia(posActual, objetivos);
		Nat minimaDistancia = _campus.distancia(posActual, p);
		masCercanos = _campus.objetivosDeMinimaDistancia(posActual, objetivos, minimaDistancia);
	}
	else{
		Conj<Posicion> ingresosConEsteX;
		Posicion posAux1;
		posAux1.x = posActual.x;
		posAux1.y = 1;
		Posicion posAux2;
		posAux2.x = posActual.x;
		posAux2.y = _campus.obtenerFilas();
		ingresosConEsteX.AgregarRapido(posAux1);
			ingresosConEsteX.AgregarRapido(posAux2);
			Posicion p = _campus.posicionMinimaDistancia(posActual, ingresosConEsteX);
		Nat minimaDistancia = _campus.distancia(posActual, p);
		masCercanos = _campus.objetivosDeMinimaDistancia(posActual, ingresosConEsteX, minimaDistancia);
	}

	Conj<Posicion>::Iterador it3 = masCercanos.CrearIt();
	Conj<Direccion> cD = _campus.enQueDireccionesVoy(posActual, it3.Siguiente());
	Conj<Direccion>::Iterador it = cD.CrearIt();
	Posicion posResultante = _campus.proxPosicion(posActual, it.Siguiente());
	while (it3.HaySiguiente() && _campus.ocupada(posResultante)){
		cD = _campus.enQueDireccionesVoy(posActual, it3.Siguiente());
		it = cD.CrearIt();
		while (it.HaySiguiente() && _campus.ocupada(_campus.proxPosicion(posActual, it.Siguiente()))){
			it.Avanzar();
		}
		posResultante = _campus.proxPosicion(posActual, it.Anterior());
		it3.Avanzar();
	}

	if (!_campus.ocupada(posResultante)){
		muerteDelHippie(n);
		ingresarHippieMagicamente(n, posResultante);
	}
}


void CampusSeguro::moverAgente(Agente a){
	Posicion posActual = posAgente(a);
	//cout << "(" << posActual.x << "," << posActual.y << ")" << endl; //esto anda
	diccTrie<Posicion>::Iterador it2 = Hippies.Claves();
	/*while(it2.HaySiguiente()) {
		cout << it2.Siguiente().significado.x << it2.Siguiente().significado.y;
		it2.Avanzar();
	}*/
	Conj<Posicion> masCercanos;
	if(it2.HaySiguiente()){
		//cout << "IMPRIME";
		Conj<Posicion> objetivos = posicionesDeObjetivosDeAgentes();
		
		/*Conj<Posicion>::Iterador a = objetivos.CrearIt();
		while(a.HaySiguiente()) {
		//cout << a.Siguiente().x << a.Siguiente().y;
		a.Avanzar();
		}*/
		
		Posicion p = _campus.posicionMinimaDistancia(posActual,objetivos);
		//cout << "(" << p.x << "," << p.y << ")" << endl;
		
		Nat minimaDistancia = _campus.distancia(posActual,p);
		//cout << minimaDistancia << endl;
		
		masCercanos = _campus.objetivosDeMinimaDistancia(posActual,objetivos,minimaDistancia);
		//cout << masCercanos.Cardinal();
		//Conj<Posicion>::Iterador b = masCercanos.CrearIt();
		/*while(b.HaySiguiente()) {
		//cout << b.Siguiente().x << b.Siguiente().y << endl;
		b.Avanzar();
		} // DA LO QUE TIENE QUE DAR*/
		
	}
	else{
		//cout << "esto no lo imprime";
		Conj<Posicion> ingresosConEsteX;
		Posicion posAux1;
		posAux1.x = posActual.x;
		posAux1.y = 1;
		Posicion posAux2;
		posAux2.x = posActual.x;
		posAux2.y = _campus.obtenerFilas();
		ingresosConEsteX.AgregarRapido(posAux1);
		ingresosConEsteX.AgregarRapido(posAux2);
		Posicion p = _campus.posicionMinimaDistancia(posActual,ingresosConEsteX);
		Nat minimaDistancia = _campus.distancia(posActual,p);
		masCercanos = _campus.objetivosDeMinimaDistancia(posActual,ingresosConEsteX,minimaDistancia);
	}
	
	Conj<Posicion>::Iterador it3 = masCercanos.CrearIt();
	Conj<Direccion> cD = _campus.enQueDireccionesVoy(posActual,it3.Siguiente());
	Conj<Direccion>::Iterador it = cD.CrearIt();
	//si no hay hippies, y el agente esta en un ingreso, el conjunto de direcciones es vacio y dsp se le pide siguiente.. ahi puede joderse todo
	/*while(it.HaySiguiente()) {
		cout << "it.Siguiente()" << "it.Siguiente()" << endl;
		it.Avanzar();
	}*/
	
	Posicion posResultante = _campus.proxPosicion(posActual,it.Siguiente());
	//cout << posResultante.x << posResultante.y << endl; //hasta aca ponele q esta bien
	
	while(it3.HaySiguiente() && _campus.ocupada(posResultante)){
		cD = _campus.enQueDireccionesVoy(posActual,it3.Siguiente());
		it = cD.CrearIt();
		while(it.HaySiguiente() && _campus.ocupada(_campus.proxPosicion(posActual,it.Siguiente()))){
			it.Avanzar();
		}
		posResultante = _campus.proxPosicion(posActual,it.Anterior());
		it3.Avanzar();
	}
	if(! _campus.ocupada(posResultante)){
		// linea del puntero
		// linea del mapa
		// linea del puntero
		// linea del mapa
		
		tupHash* punterito = (Mapa[posActual.x-1])[posActual.y-1].agente.p;

		actualizarMapa(posActual.x-1, posActual.y-1,false,"",false,"",false,NULL,false);
		
		punterito->pos = posResultante;
		
		actualizarMapa(posResultante.x-1, posResultante.y-1, false, "", false, "", true, punterito, false);
		
		tupHash* posicionEnHash = AgentesD.significado(a);
		posicionEnHash->pos = posResultante;
		
		Conj<Posicion> losVecinosValidos = _campus.vecinos(posResultante);
		losVecinosValidos = _campus.vecinosValidos(losVecinosValidos);
		Conj<Posicion>::Iterador it2 = losVecinosValidos.CrearIt();
		while(it2.HaySiguiente()){
			Conj<Posicion> vecinasDeEstaVecina = _campus.vecinosValidos(_campus.vecinos(it2.Siguiente()));
			if((Mapa[it2.Siguiente().x-1])[it2.Siguiente().y-1].hip.oc) {
				cout << "asd" << endl;
				if(todasLasVecinasOcupadas(vecinasDeEstaVecina)){
					cout <<"llega" << endl;
					if(alMenos1Agente(vecinasDeEstaVecina)){
						cout << "mata y otorga" << endl;
						muerteDelHippie((Mapa[it2.Siguiente().x - 1])[it2.Siguiente().y - 1].hip.n);
						otorgarCapturas(it2.Siguiente());
					}
				}
			}
			else{
				if ((Mapa[it2.Siguiente().x - 1])[it2.Siguiente().y - 1].est.oc) {
					if(todasLasVecinasOcupadas(vecinasDeEstaVecina)){
						otorgarSanciones(it2.Siguiente());
					}
				}
			}
			it2.Avanzar();
		}
	}
}

Agente CampusSeguro::masVigilante() {
	return MasVigilante.ag;
}

Nat CampusSeguro::cantEstudiantes() {
	diccTrie<Posicion>::Iterador it = Estudiantes.Claves();
	int i = 0;
	while(it.HaySiguiente()) {
		i++;
		//std::cout << i << std::endl;
		it.Avanzar();
	}
	//std::cout << i << std::endl;
	return i;
}

Nat CampusSeguro::cantHippies() {
	diccTrie<Posicion>::Iterador it = Hippies.Claves();
	int i = 0;
	while(it.HaySiguiente()) {
		i++;
		
		it.Avanzar();
	}
	return i;
}

Nat CampusSeguro::busquedaBinaria(Vector<tupConjNat> v, Nat e) {
	return busquedaDC(v,e,0,v.Longitud()-1);
}

Nat CampusSeguro::busquedaDC(Vector<tupConjNat> v, Nat e, Nat bajo, Nat alto) {
	Nat res;
	if(alto == bajo){
		if(v[alto].sanc == e){
			res = alto;
		}
	}
	Nat medio = (bajo + alto)/2;
	if(v[medio].sanc < e){
			res = busquedaDC(v,e,medio+1,alto);
	}
	else{
		res = busquedaDC(v,e,bajo,medio);
	}
	return res;
}

Conj<Agente> CampusSeguro::conMismasSanciones(Agente a) {
	return AgentesD.significado(a)->lista.Siguiente().conj;
}

Conj<Agente> CampusSeguro::conKSanciones(Nat k) { //No existe el redimensionar. hay que ver como hacer esta funcion.
	Conj<Agente> conj2;
	
	/*Lista<tupConjNat>::Iterador it = CantSanciones.lista->CrearIt();
	while(it.HaySiguiente()) {
		cout << "hola: " << it.Siguiente().sanc << endl;
		Conj<Agente>::Iterador itagente = it.Siguiente().conj.CrearIt();
		while(itagente.HaySiguiente()) {
			cout << "agente: " << itagente.Siguiente() << endl;
			itagente.Avanzar();
		}
		it.Avanzar();
	}*/
	if (CantSanciones.actualizar) {
		//cout << "actualizar" << endl;
		CantSanciones.actualizar = false;
		Nat i = 0;
		Lista<tupConjNat>::Iterador it = CantSanciones.lista.CrearIt();
		while (it.HaySiguiente()) {
			//cout << "iteracion" << it.Siguiente().sanc << endl;
			if (it.Siguiente().sanc == k) {
				//cout << "entro, k = " << k << endl;
				conj2 = it.Siguiente().conj;
				
			}
			tupConjNat tupla;
			tupla.conj = it.Siguiente().conj;
			tupla.sanc = it.Siguiente().sanc;
			sanciones.Agregar(i, tupla);
			i++;
			it.Avanzar();
		}
	}
	else {
		//cout << "122" << endl;
		bool aux = false;
		Lista<tupConjNat>::Iterador it = CantSanciones.lista.CrearIt();
		while (it.HaySiguiente()) {
			if(it.Siguiente().sanc == k) aux = true;
			it.Avanzar();
		}
		if(aux) {
		Nat indice = busquedaBinaria(sanciones, k);
		//cout << indice << endl;
		conj2 = sanciones[indice].conj;
		}
		
	}
	/*cout << it2.HaySiguiente() << endl;
	while(it2.HaySiguiente()) {
		cout << it2.Siguiente() << endl;
		it2.Avanzar();
	}*/
	/*while(it2.HaySiguiente()) {
					cout << "agente: " << it2.Siguiente() << endl;
					it2.Avanzar();*/
				//}
	return conj2;
}

/*
Nat CampusSeguro::cantHippies() {
	return Hippies.claves().Longitud();
}


Nat CampusSeguro::cantEstudiantes() {
	return Estudiantes.claves().Longitud();
}


Agente CampusSeguro::masVigilante() {
	return MasVigilante.ag;
}

*/

/*
bool CampusSeguro:: alMenosUnAgente(Conj<Posicion> cp) {
	Iterador it = cp.CrearIt();
	Nat cantAgentes=0;
	while (it.HaySiguiente()) {

		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc) {

			cantAgentes++;

		} 	

		it.Avanzar();
	}
	
	return (cantAgentes>=1);
}

bool CampusSeguro:: alMenosDosHippies(Conj<Posicion> cp) {

	Iterador it = cp.CrearIt();
	Nat cantHippies=0;
	while (it.HaySiguiente()){

		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].hip.oc) {

			cantHippies++;

		} 	

		it.Avanzar();
	}
	
	return (cantHippies>=1);
	
}
*//*
bool CampusSeguro:: todasLasVecinasOcupadas(Conj<Posicion> cp) {

	Iterador it = cp.CrearIt();
	Nat posLibres=0;
	while (it.HaySiguiente()) {

		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].hip.oc==false && Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].est.oc==false && Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc==false && Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].obstaculo==false ) {

			posLibres++;

		} 	

		it.Avanzar();
	}
	
	return (posLibres==0);
}
*/
/*bool CampusSeguro:: todosEstudiantes(Conj<Posicion> cp) {

	Iterador it = cp.CrearIt();
	Nat cantEst=0;
	while (it.HaySiguiente()) {

		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].est.oc) {

			cantEst++;

		} 	

		it.Avanzar();
	}
	
	return (cantEst== cp.Cardinal());
}*/


/*
void CampusSeguro::OtorgarSanciones(Posicion p){
	Conj<Posicion> vecinasLegales = campus.vecinosValidos(campus.Vecinos(p));
	Conj<Posicion>::Iterador it = vecinasLegales.CrearIt();
	while(it.HaySiguiente()){
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc){
			
		}
	}
}

void CampusSeguro::OtorgarCapturas(Posicion p){
	Conj<Posicion> vecinasLegales = campus.vecinosValidos(campus.Vecinos(p));
	Iterador it = vecinasLegales.CrearIt;
	while(it.HaySiguiente()){
		if((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc){
			
		}
	}
}
*/
/*
Conj<Posicion> CampusSeguro:: posicionesDeObjetivos(Nombre n) {
	Conj<Posicion> res;
	Iterador it;
	if(Hippies.Definido?(i)){
		it = Estudiantes.CrearItClaves;
	}
	else{
		it = Hippies.CrearItClaves;
	}
	while(it.HaySiguiente()){
			res.AgregarRapido(it.Siguiente.Significado);
			it.Avanzar();
		}
	return res;
}
*/
/*
bool CampusSeguro:: todasOcupadas(Conj<Posicion> cp) {
	
	Iterador it = cp.CrearIt();
	bool chequeo = true;
	Posicion pos;
	while(it.HaySiguiente()){

		if(!((Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].hip.oc==true || Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].est.oc==true|| Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].agente.oc==false || Mapa[it.Siguiente().x-1])[it.Siguiente().y-1].obstaculo==true )) {


			chequeo = false;

		}

	}
		return chequeo;

}
Nat CampusSeguro:: busquedaBinaria(Vector<tupItConjNat> v, Nat e) {

	return BusquedaDC(v,e,0,v.Longitud()-1);

}
Nat CampusSeguro:: BusquedaDC(Vector<tupItConjNat> v, Nat e,Nat bajo,Nat alto) {

	if(alto==bajo) {

		if(v[alto].sanc==e) {
			return alto;
		}
		
		

	}
	Nat medio = (alto+bajo)/2;
	if(v[medio].sanc<e) {

		return BusquedaDC(a,e,medio+1,alto);

	} else {

		return BusquedaDC(a,e,bajo,medio);

	}

}
*/


