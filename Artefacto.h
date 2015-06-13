/* 
 * File:   Artefacto.h
 * Author: JUANJO
 *
 * Created on 2 de junio de 2015, 04:23 PM
 */

#ifndef ARTEFACTO_H
#define	ARTEFACTO_H

#include <string>

#include "Entidad.h"

using namespace std;

class Artefacto {
protected:
    string nombre;
    int tamMax;    
    
public:
    Artefacto();
    virtual ~Artefacto();
    virtual void usar(Entidad entidad);
};

Artefacto::~Artefacto() {
//    cout << "   Artefacto Eliminado\n";
}

Artefacto::Artefacto() {
    nombre = "sin_nombre";
    tamMax = 0;
}

void Artefacto::usar(Entidad entidad){
    //el monstruo o el avatar usan los objetos
    //este modulo no hace nada porque le harán override
}

#endif	/* ARTEFACTO_H */

