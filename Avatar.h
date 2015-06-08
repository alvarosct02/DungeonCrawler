/* 
 * File:   Avatar.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 10:13 PM
 */

#ifndef AVATAR_H
#define	AVATAR_H

#include "Entidad.h"

class Avatar: public Entidad{
    
    public:
        Avatar(void);
        Avatar(string,int,int,int);
        void moverDir(int);
};

Avatar::Avatar(void){
    nombre = "Guanira";
    posX = 0;
    posY = 0;
    maxVida = 100;
}
Avatar::Avatar(string name,int y,int x,int health){
    nombre = name;
    posX = x;
    posY = y;
    maxVida = health;
}

void Avatar::moverDir(int dir){
    switch(dir){
        case 0: mover(posY,posX+1); break;
        case 1: mover(posY-1,posX); break;
        case 2: mover(posY-1,posX); break;
        case 3: mover(posY+1,posX); break;
    }
}

#endif	/* AVATAR_H */

