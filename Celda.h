/* 
 * File:   Celda.h
 * Author: AlvaroPC
 *
 * Created on June 2, 2015, 12:17 AM
 */

#ifndef CELDA_H
#define	CELDA_H

#include <iostream>

#include "Monstruo.h"
#include "Artefacto.h"
using namespace std;

class Celda{
private:
    int x;
    int y;
    int tipo;
    Monstruo* monstruo;
    Artefacto* artefacto;
public:
//    static int cont;
    Celda(void);
    virtual ~Celda(void);
    
    Celda(int,int,char);
    void SetTipo(char tipo);
    int GetTipo() const;
    int GetY() const;
    int GetX() const;
    void SetArtefacto(Artefacto* artefacto);
    void SetMonstruo(Monstruo* monstruo);
    bool estaVacia(void);
};
//int Celda::cont = 0;

Celda::Celda(){  
//    cont ++;
//    this->Celda(0);
    cout << "Celda creada Vacia\n";
    SetTipo(0);
}


Celda::~Celda() {
//    cont--;    
//    cout << "BYE\n";
//    tipo = 0;
}

Celda::Celda(int y,int x,char t) {

//    cont ++;    
//    cout << "Celda creada\n";
    this->x = x;
    this->y = y;
    monstruo = NULL;
    artefacto = NULL;
    SetTipo(t);
}

void Celda::SetTipo(char t) {
    switch (t){
        case '#': tipo = 0; break;
        case '*': tipo = 0; break;
        case ' ': tipo = 1; break;
        case '-': tipo = 2; break;
        case '+': tipo = 3; break;   
        case 'M': tipo = 4; break;
        case 'A': tipo = 5; break;
    }
}

int Celda::GetTipo() const {
    char value;
    switch (tipo){
        case 0: value = '#'; break;
        case 1: value = ' '; break;
        case 2: value = '-'; break;
        case 3: value = '+'; break; 
        case 4: value = 'M'; break;
        case 5: value = 'A'; break;      
    }
    return value;
}

int Celda::GetY() const {
    return y;
}

int Celda::GetX() const {
    return x;
}

void Celda::SetArtefacto(Artefacto* artefacto) {
    this->artefacto = artefacto;
    SetTipo('A');
}

void Celda::SetMonstruo(Monstruo* monstruo) {
    this->monstruo = monstruo;
    SetTipo('M');
    
}

bool Celda::estaVacia(){
    return ( GetTipo() != '#' && artefacto == NULL  && monstruo == NULL);
}


#endif	/* CELDA_H */

