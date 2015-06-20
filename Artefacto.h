/* 
 * File:   Artefacto.h
 * Author: JUANJO
 *
 * Created on 2 de junio de 2015, 04:23 PM
 */

#ifndef ARTEFACTO_H
#define	ARTEFACTO_H

#include <string>

using namespace std;

class Entidad;
class Artefacto {
protected:
    string nombre;
    string descripcion;
    int tamMax;   
    int idImg;
    
public:
    Artefacto();
    virtual ~Artefacto();
    virtual void usar(Entidad* entidad)=0;
    void setIdImg(int idImg);
    int getIdImg() const;
};

Artefacto::~Artefacto() {
//    cout << "   Artefacto Eliminado\n";
}

Artefacto::Artefacto() {
    nombre = "sin_nombre";
    tamMax = 0;
}

void Artefacto::usar(Entidad* entidad){
    //el monstruo o el avatar usan los objetos
    //este modulo no hace nada porque le harán override
}

void Artefacto::setIdImg(int idImg) {
    this->idImg = idImg;
}

int Artefacto::getIdImg() const {
    return idImg;
}

#endif	/* ARTEFACTO_H */

