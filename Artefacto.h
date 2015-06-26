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
    int idImg;
    string tipo;
    int eff;    
//    int sacoPos;
    
public:
    Artefacto();
    virtual ~Artefacto();
    virtual void usar(Entidad* entidad)=0;
    void setIdImg(int idImg);
    int getIdImg() const;
    void setTipo(string tipo);
    string getTipo() const;
    void setEff(int eff);
    int getEff() const;
//    void setSacoPos(int sacoPos);
//    int getSacoPos() const;
    
};

Artefacto::~Artefacto() {
//    cout << "   Artefacto Eliminado\n";
}

Artefacto::Artefacto() {
    nombre = "sin_nombre";
    setTipo("");
//    setSacoPos(-1);
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

void Artefacto::setTipo(string tipo) {
    this->tipo = tipo;
}

string Artefacto::getTipo() const {
    return tipo;
}

void Artefacto::setEff(int eff) {
    this->eff = eff;
}

int Artefacto::getEff() const {
    return eff;
}

//void Artefacto::setSacoPos(int sacoPos) {
//    this->sacoPos = sacoPos;
//}
//
//int Artefacto::getSacoPos() const {
//    return sacoPos;
//}

#endif	/* ARTEFACTO_H */

