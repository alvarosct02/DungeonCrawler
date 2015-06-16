/* 
 * File:   PocionCuracion.h
 * Author: AlvaroPC
 *
 * Created on June 11, 2015, 5:12 PM
 */

#ifndef POCIONCURACION_H
#define	POCIONCURACION_H

#include "Artefacto.h"


class PocionCuracion:public Artefacto {
public:
    PocionCuracion(int);
    virtual ~PocionCuracion();
private:
    int puntosVida;
};

PocionCuracion::PocionCuracion(int pV) {    
    puntosVida = pV;
//    cout << "PocionCuracion Creada";
}

PocionCuracion::~PocionCuracion() {
    
}



#endif	/* POCIONCURACION_H */

