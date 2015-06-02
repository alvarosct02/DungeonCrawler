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
        Monstruo(string,int,int,int,int);
        
};

#endif	/* MONSTRUO_H */

