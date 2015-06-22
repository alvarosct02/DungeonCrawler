/* 
 * File:   Laberinto.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 11:18 PM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

#include "Celda.h"
#include <iostream>
#include <ctime>

#define SIZE 5
#define NIVELES 5

using namespace std;

class Laberinto{
private:
    Celda ***matrixCelda;
    int M,N;
    double pctMonstruo, pctArtefacto;
    int *nivelesMonstruo, *nivelesArtefacto;    
    Celda *inicio;
    int nivel;
    
    void updateSize(int,int);
    
public:     
    virtual ~Laberinto(void); 
    
    Laberinto(char**,int,int);
    int getCeldaRandom(int,int);
    char getCelda(int,int);
    int getCeldaID(int,int);
    Celda* getCeldaPtr(int,int);
    bool estaVacia(int,int);    
    void setMonstruo(int,int,Monstruo*);
    void setArtefacto(int,int,Artefacto*);
    
    void imprimir(void);
    
    int getInicioY() const;
    int getInicioX() const;
    
    int getN() const;
    int getM() const;
    
    void setNivel(int nivel);
    int getNivel() const;
    
    double getPctArtefacto() const;
    double getPctMonstruo() const;
    
    
    
};

Laberinto::Laberinto(char **matriz,int m, int n){  
//    cout << "Laberinto Creado\n";
    M = m;
    N = n;
    matrixCelda = new Celda**[M];
    for (int j= 0; j<M; j++){
        matrixCelda[j] = new Celda*[N];
        for (int i= 0; i<N; i++){
            char tipo = matriz[j][i];
            matrixCelda[j][i] = new Celda(j,i,tipo);
            if (tipo == '-') inicio = matrixCelda[j][i];
        }
    }    
    
    srand (time(NULL));    
    pctMonstruo =   2 + rand()%4;
    pctArtefacto =  5 + rand()%2;  
}

Laberinto::~Laberinto() {
    for (int j= 0; j<M; j++){
        for (int i= 0; i<N; i++)
            delete matrixCelda[j][i];
        delete [] matrixCelda[j];
    }
    delete [] matrixCelda;
    delete [] nivelesMonstruo; 
    delete [] nivelesArtefacto; 
    
    cout << "Laberinto Destruido" << endl;
}

void Laberinto::imprimir(void){
    for (int j=0; j<M; j++){
        for (int i=0; i<N; i++){
            char tipo = matrixCelda[j][i]->GetTipo();
            cout << tipo;
        }
        cout <<endl;
    }
}

Celda* Laberinto::getCeldaPtr(int row, int col) {
    if (row+1 <= M && col+1 <= N) return matrixCelda[row][col];        
    return NULL;
}

char Laberinto::getCelda(int row, int col) {
    if (row+1 <= M && col+1 <= N) return matrixCelda[row][col]->GetTipo();        
    return 0;
}

int Laberinto::getCeldaRandom(int row, int col){
    if (row+1 <= M && col+1 <= N) return matrixCelda[row][col]->GetRandom();        
    return 0;
}

int Laberinto::getCeldaID(int row, int col) {
    if (row > -1 && col > -1 && row < M && col < N) 
        return matrixCelda[row][col]->getId();        
    return 0;
}

bool Laberinto::estaVacia(int row, int col) {
    if (row+1 <= M && col+1 <= N) return matrixCelda[row][col]->estaVacia();        
    return false;
}

void Laberinto::setMonstruo(int row, int col, Monstruo* mons) {
    matrixCelda[row][col]->SetMonstruo(mons);
}

void Laberinto::setArtefacto(int row, int col, Artefacto* artef) {
    matrixCelda[row][col]->SetArtefacto(artef);
}


void Laberinto::setNivel(int nivel) {
    this->nivel = nivel+1;
    nivelesMonstruo = new int[5];
    nivelesArtefacto = new int[5];
    for (int i=0, j= this->nivel - 2; i<5; i++,j++){
        nivelesMonstruo[i] = max(1,j);
        nivelesArtefacto[i] = max(1,j+1);
    }
}

int Laberinto::getNivel() const {
    return nivel;
}

double Laberinto::getPctArtefacto() const {
    return pctArtefacto;
}

double Laberinto::getPctMonstruo() const {
    return pctMonstruo;
} 

int Laberinto::getInicioY() const {
    return inicio->GetY();
}

int Laberinto::getInicioX() const {
    return inicio->GetX();
}

int Laberinto::getN() const {
    return N;
}

int Laberinto::getM() const {
    return M;
}


#endif	/* LABERINTO_H */

