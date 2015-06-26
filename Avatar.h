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
    int anim; //0,1 
public:
    Avatar(void);
    Avatar(string,int,int,int,int);
    void setDir(int dir);
    int getDir() const;
    int getAnim() const;
    
    void setDef(int );
    void setAtk(int );  
    void setMaxVida(int);
};


Avatar::Avatar(void)
    :Entidad("Alvaro",0,0,1){
    dir = 0;
    anim = 0;
}
Avatar::Avatar(string name,int y,int x,int lvl,int imgID)
    :Entidad(name,y,x,lvl){
    Entidad::setIdImg(imgID);
    
    dir = 0;  
    anim  = 0;
}


void Avatar::setMaxVida(int lvl) {
    Entidad::setMaxVida(100*10*lvl*lvl);
}

void Avatar::setAtk(int lvl) {
    setAtk(15+5*lvl);
}

void Avatar::setDef(int lvl) {
    setDef(10+5*lvl);
}

void Avatar::setDir(int dir) {
    this->dir = dir;
    anim = !anim;
}

int Avatar::getDir() const {
    return dir;
}

int Avatar::getAnim() const{
    return anim;
}

#endif	/* AVATAR_H */

