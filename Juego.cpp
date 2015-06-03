/* 
 * File:   Juego.cpp
 * Author: AlvaroPC
 * 
 * Created on June 2, 2015, 5:03 AM
 */

#include "Juego.h"

Juego::Juego() {
    string comando; 
    int cant = 0;
    while(true){ 
        Laberinto lab = gestLab.crear();
        if (lab.isNull()) break;
        listaLaberintosAux[cant] = &lab;
        cant++;
    }
    listaLaberintos = new Laberinto[cant];
//    for (int i = 0; i<cant; i++){
//        listaLaberintos[i] = lab;
//    }

//    Asignar el primer Laberinto
    laberintoActual = listaLaberintos[0];
    
//    Posicionar el Avatar
    int lastX = laberintoActual.getLastX();    
    int lastY = laberintoActual.getLastY();    
    avatar = Avatar("Alvaro",lastY,lastX,100);
    
    dibujador.dibujarLaberinto(avatar,laberintoActual);
    
    cout << "HLA";
}

void Juego::ejecutarComando() {
//    int valor;
//    if (comando == "mover"){
//        cin >> valor;
//        cout << "Avatar se mueve" << valor << endl;
//    }
    
}


