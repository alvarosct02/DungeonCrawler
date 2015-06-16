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
#define MAX 200
using namespace std;

class GestorLaberinto{
private:
    ifstream archivo;
    char *matrix[MAX];
public:
    Laberinto* crear(void);
    GestorLaberinto(void);
    virtual ~GestorLaberinto(void);
};

GestorLaberinto::~GestorLaberinto() {   
    cout << "   Gestor Destruido\n";
} 
GestorLaberinto::GestorLaberinto() {    
    archivo.open("labFile.txt", ios::in);
    if (!archivo){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
}

Laberinto *GestorLaberinto::crear(){  
    if (archivo.eof()) return NULL;    
    string line;
    
    int row = 0;
    int col = 0;
    while(!archivo.eof()){
        matrix[row] = new char[MAX];
        getline(archivo,line);
        if (line.length() == 0) break;
        for (col=0; col<(line.length()); col++){
            char tipo = line[col];
            matrix[row][col] = tipo;
        }
        row++;
    }       
    Laberinto *lab = new Laberinto(matrix,row,col);
    return lab;    
}

#endif	/* GESTORLABERINTO_H */

