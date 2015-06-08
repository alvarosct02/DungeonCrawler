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
    int M;
    int N;
    double pctMonstruo;
    int *nivelesMonstruo;
    double pctArtefacto;
    int *nivelesArtefacto;    
    Celda *inicio;
    Celda *final;
    void updateSize(int,int);
    void agregarMonstruos(void);
    
    
public:
    
    Laberinto();
    Laberinto(const Laberinto& orig);    
    Laberinto& operator=(const Laberinto& orig);
    virtual ~Laberinto(void); 
    
    Laberinto(char**,int,int);
    bool isNull(void);
    void agregarCelda(int,int,int);   
    int getCelda(int,int);
    void imprimir(void);
    int getInicioY() const;
    int getInicioX() const;
    int getFinalY() const;
    int getFinalX() const;
    int getN() const;
    int getM() const;
    
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
            if (tipo == '+') final = matrixCelda[j][i];
        }
    }    
    srand (time(NULL));
    pctMonstruo = 0 + rand()%20;
    pctArtefacto = 0 +rand()%20;
    nivelesMonstruo = new int[5];
    nivelesArtefacto = new int[5];
    
    agregarMonstruos();
    
}


void Laberinto::agregarMonstruos(void){
    int count = 0;
    for (int j= 0; j<M; j++){
        for (int i= 0; i<N; i++){
            if (getCelda(j,i) != '#' && rand()%100 < pctMonstruo){
                count++;
            }
        }
    }
    cout << count << ' ';     
}

Laberinto::Laberinto(const Laberinto& orig) {
    *this = orig;
}

Laberinto& Laberinto::operator=(const Laberinto& orig) {    
    cout << "Laberinto Copiado\n";
    M = orig.M;
    N = orig.N;
    pctMonstruo = orig.pctMonstruo;
    pctArtefacto = orig.pctArtefacto;
    
    for (int i=0; i<NIVELES; i++){        
        nivelesMonstruo[i] = orig.nivelesMonstruo[i];
        nivelesArtefacto[i] = orig.nivelesArtefacto[i];
    }
    
    int rowNum = ((orig.M-1)/SIZE + 1) * SIZE;    
    int colNum = ((orig.N-1)/SIZE + 1) * SIZE;     
    matrixCelda = new Celda**[rowNum];
    for (int j= 0; j<rowNum; j++){
        Celda** fila = new Celda*[colNum];
        for (int i =0; i<colNum; i++){
            Celda* cell = orig.matrixCelda[j][i];
            if (cell != NULL) matrixCelda[j][i]  = new Celda(*cell);
//            else nueva = 
//            matrixCelda[j][i] = nueva;
        }
    }        
    return *this;
}

Laberinto::~Laberinto() {
    cout << "Destructor Laberinto" << endl;
    cout << M << " " << N;
    for (int j= 0; j<M; j++){
        for (int i= 0; i<M; i++)
            delete matrixCelda[j][i];
        delete [] matrixCelda[j];
    }
    delete [] matrixCelda;
    delete [] nivelesMonstruo; 
    delete [] nivelesArtefacto; 
    M = 0;
    N = 0;
    pctMonstruo = 0;
    pctArtefacto = 0;
    
//    int rowNum = (M/SIZE + 1) * SIZE;       
//    for (int j= 0; j<rowNum; j++) delete[] matrixCelda[j];
//    delete [] matrixCelda;    
//    
//    delete [] nivelesMonstruo;
//    delete [] nivelesArtefacto;
//    pctMonstruo = 0;
//    pctArtefacto = 0;
//    M = 0;
//    N = 0;
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

int Laberinto::getInicioY() const {
    return inicio->GetY();
}

int Laberinto::getInicioX() const {
    return inicio->GetX();
}

int Laberinto::getFinalY() const {
    return final->GetY();
}

int Laberinto::getFinalX() const {
    return final->GetX();
}

int Laberinto::getN() const {
    return N;
}

int Laberinto::getM() const {
    return M;
}

Laberinto::Laberinto(void){  
    cout << "Constructor Vacio" << endl;
}
int Laberinto::getCelda(int row, int col) {
    if (row+1 <= M && col+1 <= N) return matrixCelda[row][col]->GetTipo();        
    return 0;
}

#endif	/* LABERINTO_H */

