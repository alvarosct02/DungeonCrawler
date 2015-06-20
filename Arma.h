/* 
 * File:   Arma.h
 * Author: JUANJO
 *
 * Created on 17 de junio de 2015, 12:04 PM
 */

#ifndef ARMA_H
#define	ARMA_H

#include "Artefacto.h"
#include "Entidad.h"


class Arma: public Artefacto {
private:
    int danho;
public:
    Arma(int);
    virtual ~Arma();
    void usar(Entidad* entidad);
};

Arma::Arma(int dan){
    danho = dan;
    setIdImg(0);
}

void Arma::usar(Entidad* entidad){
    cout << "El arma "<<nombre<< "es usada por "<<entidad->getNombre();
}

#endif	/* ARMA_H */

