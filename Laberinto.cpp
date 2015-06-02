
#include <cstdlib>
#include <iostream>

#include "Laberinto.h"

using namespace std;
Laberinto::Laberinto() {
    nulo = true;
    
}

void Laberinto::setSize(int m,int n) {
    nulo = false;
    M = m;
    N = n;
}

void Laberinto::agregarCelda(int cellType, int row, int col) {
    matrixAux[row][col] = cellType;
}

void Laberinto::crearMatrix() {
    int w=0,h=0;
    while(matrixAux[0][w] != 0) w++;
    while(matrixAux[h][0] != 0) h++;
    cout << h << "/" << w << endl;
    
   
    matrixCelda = new Celda* [h];
    for(int j = 0; j<h; j++){
        matrixCelda[j] = new Celda [w];
        for(int i = 0; i<w; i++){ 
//            cout << matrixAux[j][i];
            matrixCelda[j][i] = Celda(matrixAux[j][i]);
        }
//        cout << endl;
    }
}

int Laberinto::getCelda(int row, int col) {
    return matrixCelda[row][col].GetTipo();
}

bool Laberinto::isNull() const {
    return nulo;
}




