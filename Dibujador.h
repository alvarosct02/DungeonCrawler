/* 
 * File:   Dibujador.h
 * Author: AlvaroPC
 *
 * Created on June 2, 2015, 10:47 PM
 */

#ifndef DIBUJADOR_H
#define	DIBUJADOR_H

#include "Laberinto.h"
#include "Avatar.h"


class Dibujador {
private:
    int A;
    int B;
public:
    Dibujador();
    Dibujador(int,int);
    void dibujarLaberinto(Avatar,Laberinto);
    void dibujarCeldas(Avatar,Laberinto);
    void dibujarXY(int,int,string);
};

#endif	/* DIBUJADOR_H */

