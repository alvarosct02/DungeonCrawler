#include <cstdlib>
#include <cstdio>

#include <fstream>
#include <iostream>
#include "GestorLaberinto.h"
#include "Laberinto.h"
#include "Celda.h"
using namespace std;

GestorLaberinto::GestorLaberinto() {    
    archivo.open("labFile.txt", ios::in);
    if (!archivo){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
}

Laberinto GestorLaberinto::crear(){
    string line;
    Laberinto lab;    
    if (archivo.eof()) return lab;
    int first = 1;
    cout << "LAB" << endl;
    int row = 0;
    while(!archivo.eof()){     
        getline(archivo,line);
        if (line.length() == 0) break;
        if (first){
//            lab(line.length());
            first = 0;
        }
        for (int col=0; col<(line.length()); col++){
            int num = line[col] - '0';
            lab.agregarCelda(num,row,col);
            cout << line[col];
        }
        cout << endl;
        row++;
    }
    lab.crearMatrix();
    
    return lab;
    
}