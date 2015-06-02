/* 
 * File:   Juego.cpp
 * Author: AlvaroPC
 * 
 * Created on June 2, 2015, 5:03 AM
 */

#include "Juego.h"

Juego::Juego() {
    string comando; 
    gestLab.crear();
    int cant = 0;
    while(true){ 
        Laberinto lab = gestLab.crear();
        if (lab.isNull()) break;
        listaLaberintosAux[cant] = &lab;
        cant++;
//        cin >> comando;
//        break;
//        if (comando == "exit") break;
//        else break;
//        ejecutarComando(comando);
    }
    cout << "HLA";
}

void Juego::ejecutarComando() {
//    int valor;
//    if (comando == "mover"){
//        cin >> valor;
//        cout << "Avatar se mueve" << valor << endl;
//    }
    
}


