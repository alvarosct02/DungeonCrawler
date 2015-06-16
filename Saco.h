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
#define SIZE 5
//class Artefacto{};
class Saco {
public:
    Saco();
    Saco(const Saco& orig);
    virtual ~Saco();
    
    void agregarObjeto(Artefacto*);
    void listarObjetos(void);
    void getObjeto(int);    
    
private:
    Artefacto **listaObjetos;
    int cantArtef;
    void agrandarSaco(int);
    
};

void Saco::listarObjetos(void){
    if (cantArtef == 0) cout << "Saco Vacio\n";
    else cout << cantArtef << endl;
//    for (int i=0; i<cantArtef; i++){
//        
//    }
}

void Saco::getObjeto(int pos){
    
} 

void Saco::agrandarSaco(int cant){   
    Artefacto **aux = new Artefacto* [cant+SIZE];
    for (int i=0; i<cant; i++) aux[i] = listaObjetos[i];
    delete [] listaObjetos;
    listaObjetos = aux;
}

void Saco::agregarObjeto(Artefacto*obj){
    if (cantArtef != 0 && (cantArtef % SIZE) == 0 ){
        agrandarSaco(cantArtef);        
    }
    listaObjetos[cantArtef] = obj;
    cantArtef ++;
}

Saco::Saco() {
    cantArtef = 0;
    listaObjetos = new Artefacto*[SIZE];    
}

Saco::Saco(const Saco& orig) {
    
}

Saco::~Saco() {
    delete [] listaObjetos;
}

#endif	/* SACO_H */

