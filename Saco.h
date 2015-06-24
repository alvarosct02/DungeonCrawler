/* 
 * File:   Saco.h
 * Author: AlvaroPC
 *
 * Created on June 14, 2015, 10:48 PM
 */

#ifndef SACO_H
#define	SACO_H

//class Entidad;
#include "Artefacto.h"
#include "Armadura.h"
#include "Arma.h"
#define SIZE_SACO 6
//class Artefacto{};
class Saco {
public:
    Saco();
    Saco(const Saco& orig);
    virtual ~Saco();
    
    int agregarObjeto(Artefacto*);
    void listarObjetos(void);
    void getObjeto(int);    
    
private:
    Artefacto **listaObjetos;
    Artefacto *curArmadura;
    Artefacto *curArma;
    
    int cantArtef;
//    void agrandarSaco(int);
};

void Saco::listarObjetos(void){
    if (cantArtef == 0) cout << "Saco Vacio\n";
    else cout << cantArtef << endl;
}

void Saco::getObjeto(int pos){    
} 

//void Saco::agrandarSaco(int cant){   
//    Artefacto **aux = new Artefacto* [cant+SIZE_SACO];
//    for (int i=0; i<cant; i++) aux[i] = listaObjetos[i];
//    delete [] listaObjetos;
//    listaObjetos = aux;
//}

int Saco::agregarObjeto(Artefacto*obj){
    
    if (curArma == NULL && obj->getTipo() == "arma"){
        curArma = obj;
    } else if (curArmadura == NULL && obj->getTipo() == "armadura"){
        curArmadura = obj;   
    } else if (cantArtef == SIZE_SACO){
        return -1;
    } else {        
        listaObjetos[cantArtef] = obj;
        cantArtef ++;
    }        
}

Saco::Saco() {
//    curAr
    cantArtef = 1;
    listaObjetos = new Artefacto*[SIZE_SACO];  
    curArma = NULL;
    curArmadura = NULL;
}

Saco::Saco(const Saco& orig) {
    
}

Saco::~Saco() {
    delete [] listaObjetos;
}

#endif	/* SACO_H */

