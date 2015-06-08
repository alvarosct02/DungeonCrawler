/* 
 * File:   Armadura.h
 * Author: AlvaroPC
 *
 * Created on June 3, 2015, 2:58 AM
 */

#ifndef ARMADURA_H
#define	ARMADURA_H

#include "Entidad.h"
#include "Artefacto.h"

class Armadura : public Artefacto {
public:
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();    
    void usar(Entidad entidad);
private:

};

Armadura::Armadura() {
}

Armadura::Armadura(const Armadura& orig) {
}

Armadura::~Armadura() {
}

void Armadura::usar(Entidad entidad) {
    cout << "La armadura es usada por..." << entidad.getNombre() << endl;
}

#endif	/* ARMADURA_H */

