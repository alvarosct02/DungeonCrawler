/* 
 * File:   Monstruo.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 10:15 PM
 */

#ifndef MONSTRUO_H
#define	MONSTRUO_H

#include "Entidad.h"

class Monstruo: public Entidad{
    private:
        int nivel;
        
    public:
        Monstruo(void); 
        virtual ~Monstruo(void);
        Monstruo(string,int,int,int,int);        
};

Monstruo::~Monstruo(void){
//    cout << "   Monstruo destruido\n";
}

Monstruo::Monstruo(void){
    nombre = "NoName";
    posX = 0;
    posY = 0;
    maxVida = 100;
    nivel = 1;
}
Monstruo::Monstruo(string name ,int x,int y,int health,int lvl){
    nombre = name;
    posX = x;
    posY = y;
    maxVida = health;
    nivel = lvl;
}
#endif	/* MONSTRUO_H */

