/* 
 * File:   Laberinto.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 11:18 PM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

class Laberinto{
private:
    bool isNull;
    int M;
    int N;
    double pctMonstruo;
    int *nivelesMonstruo;
    double pctArtefacto;
    int *nivelesArtefacto;
    
public:
    Laberinto(void);
    void setSize(int, int);
};

#endif	/* LABERINTO_H */

