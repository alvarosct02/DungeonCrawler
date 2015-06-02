/* 
 * File:   Laberinto.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 11:18 PM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

#include "Celda.h"

#define MAX 100

class Laberinto{
private:
    int matrixAux[MAX][MAX];
    Celda **matrixCelda;
    bool nulo;
    int M;
    int N;
    double pctMonstruo;
    int *nivelesMonstruo;
    double pctArtefacto;
    int *nivelesArtefacto;    
    
public:
    Laberinto(void);
    void setSize(int, int);
    void agregarCelda(int,int,int);    
    void crearMatrix(void);
    int getCelda(int,int);
    bool isNull() const;
};

#endif	/* LABERINTO_H */

