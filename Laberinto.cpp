
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
            int val = matrixAux[j][i];
            if (val == 3){ lastX = i; lastY = j;}           
            else if (val == 4){ nextX = i; nextY = j;};
            matrixCelda[j][i] = Celda(val);
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

void Laberinto::setNextY(int nextY) {
    this->nextY = nextY;
}

int Laberinto::getNextY() const {
    return nextY;
}

void Laberinto::setNextX(int nextX) {
    this->nextX = nextX;
}

int Laberinto::getNextX() const {
    return nextX;
}

void Laberinto::setLastY(int lastY) {
    this->lastY = lastY;
}

int Laberinto::getLastY() const {
    return lastY;
}

void Laberinto::setLastX(int lastX) {
    this->lastX = lastX;
}

int Laberinto::getLastX() const {
    return lastX;
}




