#ifndef GARA_H
#define GARA_H
#include "Veicoli.cpp"
#include <cstdlib>
#include <iostream>

class Gara {
	int durata;
	int numeroPartecipanti;
	int numeroIscritti;

	Veicolo ** veicoli;

	public:
    	void controlla(int t);
    	void controlla();
	Gara(int durata, int partecipanti) : durata(durata), numeroPartecipanti(partecipanti) {
		veicoli = new Veicolo*[numeroPartecipanti];
		numeroIscritti = 0;
	}

	~Gara() {
		delete [] veicoli;
	}

	void partenza();
	void stampaClassifica();
	void aggiungiPartecipante(Veicolo& v);
};

#endif

void Gara::aggiungiPartecipante(Veicolo& v) {
	//mi serve sapere il numero dei partecipanti iscritti finora
	//A. aggiungo un parametro a questo metodo
	//B. utilizzo una costante
	//C. aggiungo un attributo alla classe
	//D. vado al mare
	//std::cout << "Riga 37 file Gara - metodo aggiungiPartecipante" << std::endl;
	veicoli[numeroIscritti++] = &v;
}

void Gara::controlla(){
    controlla(numeroIscritti);
}

void Gara::controlla(int t) {
    if(t==1) return;
    int massimo= veicoli[0]->getVelocita();
    int index=0;
    for(int i=1; i<t; i++){
        if(veicoli[i]->getVelocita()>massimo){
            massimo= veicoli[i]->getVelocita();
            index=i;
        }
    }
    Veicolo * d= veicoli[index];
    veicoli[index]= veicoli[t-1];
    veicoli[t-1]= d;
    controlla(t-1);

}

void Gara::partenza() {
	srand(42);
	for(int i=0; i < durata; i++) {
		for(int j=0; j < numeroIscritti; j++) {

			//std::cout << "Riga 71 file Gara - metodo partenza" << std::endl;

			int scelta = rand() % 2;
			if(scelta == 1)
				veicoli[j]->accelera();
			else
				veicoli[j]->decelera();

		}
		this->controlla();
	}

	this->stampaClassifica();
}

void Gara::stampaClassifica() {
	std::cout << "Stampa Classifica..." << std::endl;
    for(int i = numeroIscritti-1; i>=0; i--){
        static int b=1;
        std::cout << b++ << " posizione: " << *veicoli[i] << " con velocita' " << veicoli[i]->getVelocita() << std::endl;
    }

}
