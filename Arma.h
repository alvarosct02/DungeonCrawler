/* 
 * File:   Armadura.h
 * Author: AlvaroPC
 *
 * Created on June 3, 2015, 2:58 AM
 */

#ifndef ARMA_H
#define	ARMA_H

#include "Entidad.h"
#include "Artefacto.h"

class Arma : public Artefacto {
public:
    Arma();
    Arma(int,int);
    virtual ~Arma();    
    void usar(Entidad* entidad);
private:
};


Arma::Arma(){
    
}

Arma::Arma(int atk, int id){    
    setTipo("arma");
    setEff(atk);
    setIdImg(id);
}

Arma::~Arma() {    
}

void Arma::usar(Entidad *entidad) {    
    Saco *saco = entidad->getSaco();//   
    saco->cambiarArma(this);
}

#endif	/* ARMA_H */

