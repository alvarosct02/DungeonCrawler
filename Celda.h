/* 
 * File:   Celda.h
 * Author: AlvaroPC
 *
 * Created on June 2, 2015, 12:17 AM
 */

#ifndef CELDA_H
#define	CELDA_H

#include <iostream>
using namespace std;

class Celda{
private:
    int x;
    int y;
    int tipo;
public:
//    static int cont;
    Celda(void);
    Celda(const Celda& orig);
    Celda& operator=(const Celda& orig);
    virtual ~Celda(void);
    
    Celda(int,int,char);
    void SetTipo(char tipo);
    int GetTipo() const;
    int GetY() const;
    int GetX() const;
};
//int Celda::cont = 0;

Celda::Celda(){  
//    cont ++;
//    this->Celda(0);
    cout << "Celda creada Vacia\n";
    SetTipo(0);
}

Celda::Celda(const Celda& orig) {
    *this = orig;
}
Celda& Celda::operator =(const Celda& orig){
    cout << "copiado\n" << endl;
    tipo = orig.tipo;
    return *this;
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
    SetTipo(t);
}

void Celda::SetTipo(char t) {
    switch (t){
        case '#': tipo = 0; break;
        case ' ': tipo = 1; break;
        case '-': tipo = 2; break;
        case '+': tipo = 3; break;        
    }
}

int Celda::GetTipo() const {
    char value;
    switch (tipo){
        case 0: value = '#'; break;
        case 1: value = ' '; break;
        case 2: value = '-'; break;
        case 3: value = '+'; break;     
    }
    return value;
}

int Celda::GetY() const {
    return y;
}

int Celda::GetX() const {
    return x;
}


#endif	/* CELDA_H */

