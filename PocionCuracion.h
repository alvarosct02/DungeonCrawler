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
    PocionCuracion(int,int);
    virtual ~PocionCuracion();
    void usar(Entidad* entidad);
private:
    int puntosVida;
};

PocionCuracion::PocionCuracion(int pV,int id) {    
    puntosVida = pV;
//    cout << "PocionCuracion Creada";
    setIdImg(id);
}

PocionCuracion::~PocionCuracion() {
    
}

void PocionCuracion::usar(Entidad* entidad){
    cout << "La pocion de curacion "<< nombre<<"es usada por " << entidad->getNombre();
}


#endif	/* POCIONCURACION_H */

