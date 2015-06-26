/* 
 * File:   Saco.h
 * Author: AlvaroPC
 *
 * Created on June 14, 2015, 10:48 PM
 */

#ifndef SACO_H
#define	SACO_H

#include "Artefacto.h"
#define SIZE_SACO 6

class Saco {
public:
    Saco();
    Saco(const Saco& orig);
    virtual ~Saco();
    
    int agregarObjeto(Artefacto*);
    void listarObjetos(void);   
    void cambiarArma(Artefacto*); 
    void cambiarArmadura(Artefacto*);
       
    Artefacto* getObjeto(int); 
    void setObjeto(Artefacto*,int);
    void setCantArtef(int cantArtef);
    int getCantArtef() const;
    void setCurArma(Artefacto* curArma);
    Artefacto* getCurArma() const;
    void setCurArmadura(Artefacto* curArmadura);
    Artefacto* getCurArmadura() const;
    
private:
    Artefacto **listaObjetos;
    Artefacto *curArmadura;
    Artefacto *curArma;
    
    int cantArtef;
//    void agrandarSaco(int);
};

void Saco::cambiarArma(Artefacto *artef){
    Artefacto* aux = curArma;
    curArma = artef;
    artef = aux;
}

void Saco::cambiarArmadura(Artefacto *artef){
    Artefacto* aux = curArmadura;
    curArmadura = artef;
    artef = aux;
}

void Saco::listarObjetos(void){
    if (cantArtef == 0) cout << "Saco Vacio\n";
    else cout << cantArtef << endl;
}

Artefacto* Saco::getObjeto(int pos){
    return listaObjetos[pos] ;
} 

void Saco::setObjeto(Artefacto* artef, int pos){
    listaObjetos[pos] = artef;
}

void Saco::setCantArtef(int cantArtef) {
    this->cantArtef = cantArtef;
}

int Saco::getCantArtef() const {
    return cantArtef;
}

void Saco::setCurArma(Artefacto* curArma) {
    this->curArma = curArma;
}

Artefacto* Saco::getCurArma() const {
    return curArma;
}

void Saco::setCurArmadura(Artefacto* curArmadura) {
    this->curArmadura = curArmadura;
}

Artefacto* Saco::getCurArmadura() const {
    return curArmadura;
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

