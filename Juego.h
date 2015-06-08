/* 
 * File:   Juego.h
 * Author: AlvaroPC
 *
 * Created on June 2, 2015, 5:03 AM
 */

#ifndef JUEGO_H
#define	JUEGO_H
//#define MAX 100

#include "Laberinto.h"
#include "GestorLaberinto.h"
#include "Avatar.h"
#include "Dibujador.h"
#include "Armadura.h"
#include <ctime>
#include <cmath>
#define SIZE 5
#define PI 3.14159

class Juego {
private:
    Laberinto *laberintoActual;
    int cantLab;
    Laberinto **listaLaberintos;
    GestorLaberinto gestLab;
    Avatar* avatar;
    Dibujador dibujador;
    
    void cargarLaberintos(void);
    void desordenarLaberintos(void);
    void imprimirLaberintos(void);
    void initJuego(void); 
    void dir_Mover(void);      
    void dir_Exit(void); 
   
    bool ejecutarComando(string);
public:
    Juego();

};

void Juego::imprimirLaberintos(void){  
    cout << "\nIMPRIMIR LABS\n";
    for (int i=0 ; i<cantLab; i++){
        listaLaberintos[i]->imprimir();
        cout << endl;
    }
}

void Juego::cargarLaberintos(void){    
    int cant = 0;
    while(true){ 
        Laberinto *lab = gestLab.crear();
        if (lab==NULL) break;
        if (cant != 0 && cant%5 == 0){
            Laberinto** aux = new Laberinto*[cant+SIZE];
            for (int i=0; i < cant; i++){
                aux[i] = listaLaberintos[i];
            }
            listaLaberintos = aux;
        }
        listaLaberintos[cant] = lab;
        cant++;
    }
    cantLab = cant;
}

void Juego::desordenarLaberintos(void){  
    srand (time(NULL));

  /* generate secret number between 1 and 10: */
    int randIndex;
    for (int i=0 ; i<cantLab-1; i++){
        randIndex = i + rand() % (cantLab-i);
        Laberinto *aux = listaLaberintos[randIndex];
        listaLaberintos[randIndex] = listaLaberintos[i];
        listaLaberintos[i] = aux;        
    }
}

void Juego::initJuego(void){
    
    listaLaberintos = new Laberinto*[SIZE];
    cargarLaberintos();
//    desordenarLaberintos();
    
//    Asignar el primer Laberinto
    laberintoActual = listaLaberintos[0];
    
//    Posicionar el Avatar
    int lastX = laberintoActual->getInicioX();    
    int lastY = laberintoActual->getInicioY();
    avatar = new Avatar("Alvaro",lastY,lastX,100);
    
    dibujador.setSize(5,20);    
    dibujador.dibujarLaberinto(avatar,laberintoActual);
}

Juego::Juego() {
    initJuego();
    string comando; 
    while(true){
        cin >> comando;
        if (ejecutarComando(comando)) break;
        dibujador.dibujarLaberinto(avatar,laberintoActual);        
        
    }
//    Armadura arm;
//    arm.usar(avatar);
        
    cout << "\n\n";
}

bool Juego::ejecutarComando(string comando) {
    
    dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    if (comando == "mover"){        
        cout << "Ingrese una direccion";
        dibujador.dibujarXY(Dibujador::inputPos,comando.length()+2);        
        dir_Mover();
    } else if (comando == "exit"){
        return true;
    } else {
        cout << "Error: Comando Invalido";
    }
    
//    Limpiar espacio Comando
    dibujador.borrarLinea(Dibujador::inputPos,1,Dibujador::ancho1);
    
    return false;
    
}

void Juego::dir_Mover(void){
    string aux;
    cin >> aux;
    dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    int dir;
    if (aux == "d") dir = 0;
    else if (aux == "w") dir = 3;
    else if (aux == "a") dir = 2;
    else if (aux == "s") dir = 1;
    else{
        cout << "Error: Direccion invalida";
        return;
    }
        
    float xDir = (cos(PI*dir/2.0));
    float yDir = (sin(PI*dir/2.0));
    int destX = avatar->getPosX() + int(xDir);
    int destY = avatar->getPosY() + int(yDir);
    
    if (laberintoActual->getCelda(destY,destX) != '#'){
        avatar->mover(destY,destX);
        dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    }
    else{        
        dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
        cout << "Error: Es una pared";
    }
}


#endif	/* JUEGO_H */

