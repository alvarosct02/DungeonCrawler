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
private:
    int dir;
public:
    Avatar(void);
    Avatar(string,int,int,int,int);
    void moverDir(int);
    void setDir(int dir);
    int getDir() const;
    
};

Avatar::Avatar(void)
    :Entidad("Alvaro",0,0,100){
    dir = 0;
}
Avatar::Avatar(string name,int y,int x,int health,int imgID)
    :Entidad(name,y,x,health){
    Entidad::setIdImg(imgID);
    dir = 0;  
}

void Avatar::moverDir(int dir){
    int posY = getPosY();
    int posX = getPosX();
    switch(dir){
        case 0: mover(posY,posX+1); break;
        case 1: mover(posY-1,posX); break;
        case 2: mover(posY-1,posX); break;
        case 3: mover(posY+1,posX); break;
    }
}

void Avatar::setDir(int dir) {
    this->dir = dir;
}

int Avatar::getDir() const {
    return dir;
}

#endif	/* AVATAR_H */

