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
private:
    string nombre;
    int tamMax;    
public:
    Artefacto();
    void usar(Entidad entidad);
};

#endif	/* ARTEFACTO_H */

