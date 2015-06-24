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

Monstruo::Monstruo(void)
    :Entidad("NoName",0,0,100){
    nivel = 1;
}
Monstruo::Monstruo(string name ,int y,int x,int lvl,int id)
    :Entidad(name,y,x,100+(lvl-1)*20){
//    int imgID = rand()%7;
    
    Entidad::setIdImg(id);
    nivel = lvl;    
}
#endif	/* MONSTRUO_H */

