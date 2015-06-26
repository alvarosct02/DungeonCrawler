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
    int nivel; // En base 1;
public:
    Monstruo(void); 
    virtual ~Monstruo(void);
    Monstruo(string,int,int,int,int);   
    
    void setDef(int );
    void setAtk(int );  
    void setMaxVida(int);
    
};

Monstruo::~Monstruo(void){
//    cout << "   Monstruo destruido\n";
}

Monstruo::Monstruo(void)
    :Entidad("NoName",0,0,1){
    nivel = 1;
}
Monstruo::Monstruo(string name ,int y,int x,int lvl,int id)
    :Entidad(name,y,x,lvl){
    
    
    Entidad::setIdImg(id);
    nivel = lvl;    
}


void Monstruo::setMaxVida(int lvl) {
    Entidad::setMaxVida(100*10*lvl*lvl);
}

void Monstruo::setAtk(int lvl) {
    setAtk(15+5*lvl);
}

void Monstruo::setDef(int lvl) {
    setDef(10+5*lvl);
}

#endif	/* MONSTRUO_H */

