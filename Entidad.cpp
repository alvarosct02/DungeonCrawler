#include <cstdio>
#include <cstdio>
#include "Entidad.h"
#include <string>

void Entidad::mover(int y,int x){
    posX = x;
    posY = y;
}

void Entidad::setArmaduraActual(int armaduraActual) {
    this->armaduraActual = armaduraActual;
}

int Entidad::getArmaduraActual() const {
    return armaduraActual;
}

void Entidad::setArmaActual(int armaActual) {
    this->armaActual = armaActual;
}

int Entidad::getArmaActual() const {
    return armaActual;
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

