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
    int armaActual;
    int armaduraActual;
    
public:
    void mover(int,int);
    void setArmaduraActual(int armaduraActual);
    int getArmaduraActual() const;
    void setArmaActual(int armaActual);
    int getArmaActual() const;
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

#endif	/* ENTIDAD_H */

