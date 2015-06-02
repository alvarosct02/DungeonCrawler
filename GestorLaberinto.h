/* 
 * File:   GestorLaberinto.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 11:17 PM
 */

#ifndef GESTORLABERINTO_H
#define	GESTORLABERINTO_H

#include "Laberinto.h"
#include <fstream>
#include <iostream>

using namespace std;
class GestorLaberinto{
private:
    ifstream archivo;
public:
    Laberinto crear();
    GestorLaberinto(void);
};

#endif	/* GESTORLABERINTO_H */

