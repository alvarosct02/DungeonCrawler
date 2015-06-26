/* 
 * File:   PocionCuracion.h
 * Author: AlvaroPC
 *
 * Created on June 11, 2015, 5:12 PM
 */

#ifndef POCIONCURACION_H
#define	POCIONCURACION_H

#include "Artefacto.h"
#include "Entidad.h"


class PocionCuracion:public Artefacto {
public:
    PocionCuracion();
    PocionCuracion(int,int);
    virtual ~PocionCuracion();
    void usar(Entidad* entidad);
private:
};

PocionCuracion::PocionCuracion() {  
}

PocionCuracion::PocionCuracion(int pV,int id) {   
    setEff(pV);
    setIdImg(id);
    setTipo("pocion");
}

PocionCuracion::~PocionCuracion() {
    
}

void PocionCuracion::usar(Entidad* entidad){
//    Saco *saco = entidad->getSaco();//   
//    saco->cambiarArma(this);
    int curLife = entidad->getVidaActual();
    int newLife = curLife + getEff();
    entidad->setVidaActual( newLife);
//    cout << "La pocion de curacion "<< nombre<<"es usada por " << entidad->getNombre();
}


#endif	/* POCIONCURACION_H */

