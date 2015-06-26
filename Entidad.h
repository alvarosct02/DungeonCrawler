/* 
 * File:   Entidad.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 10:10 PM
 */

#ifndef ENTIDAD_H
#define	ENTIDAD_H

#include <string>

#include "Saco.h"
using namespace std;

class Entidad{
private:
    int posX;
    int posY;
    int maxVida;
    int vidaActual;
    int def;
    int atk;    
    string nombre;
    int idImg;
    int atkSP;
    int defSP;
    
protected:
    Saco *saco;
    
public:
    Entidad();
    Entidad(string,int,int,int,int,int);
    void mover(int,int);
    void setNombre(string nombre);
    string getNombre() const;
    void setVidaActual(int vidaActual);
    int getVidaActual() const;
    void setMaxVida(int maxVida);
    int getMaxVida() const;
    void setPosY(int posY);
    int getPosY() const;
    void setPosX(int posX);
    int getPosX() const;
    virtual ~Entidad(void);
    
    int agregarObjeto(Artefacto*);
    void listarObjetos(void);
    Artefacto* getObjeto(int);
    void setIdImg(int idImg);
    int getIdImg() const;
    
    void setAtk(int atk);
    int getAtk() const;
    void setDef(int def);
    int getDef() const; 
        
    int takeDamage(int);
    Saco* getSaco();
    void setDefSP(int defSP);
    int getDefSP() const;
    void setAtkSP(int atkSP);
    int getAtkSP() const;
};

int Entidad::takeDamage(int dano){
    int trueDamage = dano - getDef();
    int curLife = max(0,getVidaActual()-trueDamage);
    setVidaActual(curLife);
    return curLife;
}

Saco* Entidad::getSaco(){
    return saco;
}


int Entidad::agregarObjeto(Artefacto* obj){
    saco->agregarObjeto(obj);
}

void Entidad::listarObjetos(void){
    saco->listarObjetos();
}

Artefacto* Entidad::getObjeto(int pos){
    return saco->getObjeto(pos);
}

void Entidad::setIdImg(int idImg) {
    this->idImg = idImg;
}

int Entidad::getIdImg() const {
    return idImg;
}

void Entidad::setAtk(int atk) {
    this->atk = atk;
}

int Entidad::getAtk() const {
    int ataque = atk;
    if (saco->getCurArma() != NULL){
        ataque += saco->getCurArma()->getEff();
    }
    return ataque;
    
}

void Entidad::setDef(int def) {
    this->def = def;
}

int Entidad::getDef() const {
    return def;
}

Entidad::Entidad(){
    
}

Entidad::Entidad(string name,int y,int x,int health,int atk,int def){
    setNombre(name);
    setPosX(x);
    setPosY(y);
    setMaxVida(health);
    setVidaActual(health);
    
    setAtk(atk);
    setDef(def);    
    
    setAtkSP(0);
    setDefSP(0);
    
    saco = new Saco();
    setIdImg(0);
}

Entidad::~Entidad(void){
//    cout << "   Entidad Destruida\n";
    
}
void Entidad::mover(int y,int x){
    posX = x;
    posY = y;
}

void Entidad::setNombre(string nombre) {
    this->nombre = nombre;
}

string Entidad::getNombre() const {
    return nombre;
}

void Entidad::setVidaActual(int vidaActual) {
    this->vidaActual = vidaActual;
}

int Entidad::getVidaActual() const {
    return vidaActual;
}

void Entidad::setMaxVida(int maxVida) {
    this->maxVida = maxVida;
}

int Entidad::getMaxVida() const {
    return maxVida;
}

void Entidad::setPosY(int posY) {
    this->posY = posY;
}

int Entidad::getPosY() const {
    return posY;
}

void Entidad::setPosX(int posX) {
    this->posX = posX;
}

int Entidad::getPosX() const {
    return posX;
}

void Entidad::setDefSP(int defSP) {
    this->defSP = defSP;
}

int Entidad::getDefSP() const {
    return defSP;
}

void Entidad::setAtkSP(int atkSP) {
    this->atkSP = atkSP;
}

int Entidad::getAtkSP() const {
    return atkSP;
}

#endif	/* ENTIDAD_H */

