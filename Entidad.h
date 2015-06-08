/* 
 * File:   Entidad.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 10:10 PM
 */

#ifndef ENTIDAD_H
#define	ENTIDAD_H

#include <string>
using namespace std;

class Entidad{
protected:
    int posX;
    int posY;
    int maxVida;
    int vidaActual;
    string nombre;
    
public:
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
};


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

#endif	/* ENTIDAD_H */

