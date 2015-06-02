/* 
 * File:   Artefacto.cpp
 * Author: JUANJO
 * 
 * Created on 2 de junio de 2015, 04:23 PM
 */

#include "Artefacto.h"

Artefacto::Artefacto() {
    nombre = "sin_nombre";
    tamMax = 0;
}

void Artefacto::usar(Entidad entidad){
    //el monstruo o el avatar usan los objetos
    //este modulo no hace nada porque le harán override
}

