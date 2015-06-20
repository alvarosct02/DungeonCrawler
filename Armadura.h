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
    Armadura(int);
    virtual ~Armadura();    
    void usar(Entidad* entidad);
private:
    int defensa;
};

Armadura::Armadura(int def){
    defensa = def;
//    cout << "Armadura Creada";
    setIdImg(0);
    
 
}

Armadura::~Armadura() {
    
}

void Armadura::usar(Entidad*entidad) {
    cout << "La armadura "<<nombre<<" es usada por..." << entidad->getNombre() << endl;
}

#endif	/* ARMADURA_H */

