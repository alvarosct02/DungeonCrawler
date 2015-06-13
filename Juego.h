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
#include "PocionCuracion.h"
#include <ctime>
#include <cmath>
#include <conio.h> 
#define SIZE 5
#define PI 3.14159
#define A 8
#define B 8

class Juego {
private:
    Laberinto *laberintoActual;
    Laberinto **listaLaberintos;
    Monstruo ***matrizMonstruos;    
    Artefacto ***matrizArtefactos;
    int* cantMonstruos; 
    int* cantArtefactos; 
    
    int cantLab;
    GestorLaberinto gestLab;
    Avatar* avatar;
    Dibujador dibujador;
//    bool win
    
    void cargarLaberintos(void);
    void desordenarLaberintos(void);
    void imprimirLaberintos(void);
    void initJuego(void); 
    bool dir_Mover(void);      
    void dir_Exit(void);
    
    bool moverKeyboard(void);
    
    bool moverTo(int);
    
   
    bool ejecutarComando(string);
    
    void agrandarListaMonstruo(Monstruo**&,int);
    void agrandarListaArtefacto(Artefacto**&,int);
    
    void agregarMyA(Monstruo**&,Artefacto**&,int&,int&,Laberinto*);
public:
    Juego();
    virtual ~Juego(void); 

};

void Juego::imprimirLaberintos(void){  
    cout << "\nIMPRIMIR LABS\n";
    for (int i=0 ; i<cantLab; i++){
        listaLaberintos[i]->imprimir();
        cout << endl;
    }
}


void Juego::agrandarListaMonstruo(Monstruo** &lista,int cant){    
    Monstruo **aux = new Monstruo*[cant+SIZE];
    for (int i=0; i<cant; i++){
//        string nom = lista[i]->getNombre();
//        cout << nom << endl;
        aux[i] = lista[i];
    }
    delete [] lista;
    lista = aux;
}

void Juego::agrandarListaArtefacto(Artefacto** &lista,int cant){    
    Artefacto **aux = new Artefacto*[cant+SIZE];
    for (int i=0; i<cant; i++) aux[i] = lista[i];
    delete [] lista;
    lista = aux;
}

void Juego::agregarMyA(Monstruo **&listaMonstruo,Artefacto **&listaArtefacto,int &cM, int &cA, Laberinto *lab){
    int randMonst = 0, randArtef = 0;
    int M = lab->getM();
    int N = lab->getN();    
//    Para cada celda, decidir si incluir un monstruo
    for (int j= 0; j<M; j++){
        for (int i= 0; i<N; i++){
            randMonst = rand()%100;            
            randArtef = rand()%100;
//            si celda vacia, Agregar el monstruo
            if (lab->estaVacia(j,i) && randMonst < lab->getPctMonstruo()){                
                Monstruo* monst = new Monstruo("Guanira",j,i,100,1);
                lab->setMonstruo(j,i,monst);
                if (cM != 0 && cM%SIZE == 0)
                    agrandarListaMonstruo(listaMonstruo,cM);
                listaMonstruo[cM] = monst;
                cM++;
            }
            
//            si celda vacia, Agregar el artefacto
            if (lab->estaVacia(j,i) && randArtef < lab->getPctArtefacto()){
                Artefacto* artef;
                if (i%2 == 0){
                    artef = new Armadura(4);
                } else {
                    artef = new PocionCuracion(4);
                }
                lab->setArtefacto(j,i,artef);
                if (cA != 0 && cA%SIZE == 0)
                    agrandarListaArtefacto(listaArtefacto,cA);
                listaArtefacto[cA] = artef;
                cA++;
            }
        }
    }
    cout << cM << '/' << cA << "  ";     
}


void Juego::cargarLaberintos(void){    
    cantLab = 0;
    
    srand (time(NULL));
    
    while(true){ 
//        Crear Nuevo Laberinto
        Laberinto *lab = gestLab.crear();
        if (lab==NULL) break; // Si no hay mas Laberintos, terminar
        lab->setNivel(cantLab);
//        Agrandar Arreglo Dinamico (x5)
        if (cantLab != 0 && cantLab%SIZE == 0){
            Laberinto** auxLab = new Laberinto*[cantLab+SIZE];
            Monstruo*** auxMonst = new Monstruo**[cantLab+SIZE];            
            Artefacto*** auxArtef = new Artefacto**[cantLab+SIZE];
            int* auxCantMonst = new int[cantLab+SIZE];
            int* auxCantArtef = new int[cantLab+SIZE];
            for (int i=0; i < cantLab; i++){
                auxLab[i] = listaLaberintos[i];
                auxMonst[i] = matrizMonstruos[i];
                auxArtef[i] = matrizArtefactos[i];                
                auxCantMonst[i] = cantMonstruos[i];
                auxCantArtef[i] = cantArtefactos[i];
            }
            listaLaberintos = auxLab;
            matrizMonstruos = auxMonst;            
            matrizArtefactos = auxArtef;
            cantMonstruos = auxCantMonst;            
            cantArtefactos = auxCantArtef;
        }
   
//        Crear nueva lista vacia de Monstruos
        Monstruo **listaMonstruo = new Monstruo*[SIZE];        
//        Crear nueva lista vacia de Artefactos
        Artefacto **listaArtefacto = new Artefacto*[SIZE];
        
//        Llenar nueva lista de Monstruos
        int cM =0, cA = 0;
        agregarMyA(listaMonstruo,listaArtefacto,cM,cA,lab);      
        
//        Asignar al Arreglo en la posicion correcta
        listaLaberintos[cantLab] = lab;     
        matrizMonstruos[cantLab] = listaMonstruo;
        matrizArtefactos[cantLab] = listaArtefacto;
        cantMonstruos[cantLab] = cM;
        cantArtefactos[cantLab] = cA;
        
        cantLab++;
    }
}

void Juego::desordenarLaberintos(void){  
    srand (time(NULL));
    int randIndex;
    for (int i=0 ; i<cantLab-1; i++){
        randIndex = i + rand() % (cantLab-i);
        Laberinto *aux = listaLaberintos[randIndex];
        listaLaberintos[randIndex] = listaLaberintos[i];
        listaLaberintos[i] = aux;
        listaLaberintos[i]->setNivel(i);
    }
    listaLaberintos[cantLab-1]->setNivel(cantLab-1);
}

void Juego::initJuego(void){
    
    listaLaberintos = new Laberinto*[SIZE];
    matrizMonstruos = new Monstruo**[SIZE];
    matrizArtefactos = new Artefacto**[SIZE];
    cantMonstruos = new int[SIZE];
    cantArtefactos = new int[SIZE];
    
    cargarLaberintos();
//    desordenarLaberintos();
    
//    Asignar el primer Laberinto
    laberintoActual = listaLaberintos[0];
    
//    Posicionar el Avatar
    int lastX = laberintoActual->getInicioX();    
    int lastY = laberintoActual->getInicioY();
    avatar = new Avatar("Alvaro",lastY,lastX,100);
    
    dibujador.setSize(A,B);    
    dibujador.dibujarLaberinto(avatar,laberintoActual);
}

Juego::~Juego() {
    laberintoActual = NULL;
    cout << cantLab << endl;;
    for (int j= 0; j< cantLab; j++){
        
        
        cout << "Hay " << cantMonstruos[j] << " Monstruos" << endl;
        for (int i=0; i< cantMonstruos[j]; i++ )
            delete matrizMonstruos[j][i];        
        delete [] matrizMonstruos[j];
        
        cout << "Hay " << cantArtefactos[j] << " Artefactos" << endl;
        for (int i=0; i< cantArtefactos[j]; i++ )
            delete matrizArtefactos[j][i];        
        delete [] matrizArtefactos[j];  
        
        
        delete listaLaberintos[j];
        cout << endl;
        
        
    }
    delete [] matrizMonstruos;
    delete [] matrizArtefactos;
    delete [] cantMonstruos;
    delete [] cantArtefactos;
    delete [] listaLaberintos;
    
//    cout << "Laberintos Eliminados" << endl;
    delete avatar;
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
    bool flag = false;
    dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    if (comando == "mover"){        
        cout << "Ingrese una direccion";
        dibujador.dibujarXY(Dibujador::inputPos,comando.length()+2);        
        flag = dir_Mover();
    } else if (comando == "run"){
        flag = moverKeyboard();
    } else if (comando == "exit"){
        flag = true;
    } else {
        cout << "Error: Comando Invalido";
    }
//    Limpiar espacio Comando
    dibujador.borrarLinea(Dibujador::inputPos,1,Dibujador::ancho1);
    return flag;
}




bool Juego::moverKeyboard(void) {
//    bool flag = false;
     
//    dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    
    
    dibujador.borrarLinea(Dibujador::inputPos,1,Dibujador::ancho1); 
    cout << "Running mode...";
    int c;
//    char c2;
    bool flag = false;
    while(1)
    {
        c = getch();
        if (c != 224) break;
        c = getch();
        switch(c) {
        case 72:
            
            flag = moverTo(3);            
            break;
        case 80:
            flag = moverTo(1);
            break;
        case 77:
            flag = moverTo(0);
            break;
        case 75:
            flag = moverTo(2);
            break;
        default:
            cout << c;
            break;
//            return false;
//            break;
        }
        if (flag) break;
        dibujador.borrarLinea(Dibujador::inputPos,1,Dibujador::ancho1);        
        dibujador.dibujarLaberinto(avatar,laberintoActual);

    }
    
}

bool Juego::moverTo(int dir){
    
    float xDir = (cos(PI*dir/2.0));
    float yDir = (sin(PI*dir/2.0));
    int destX = avatar->getPosX() + int(xDir);
    int destY = avatar->getPosY() + int(yDir);
    
    
    if (laberintoActual->getCelda(destY,destX) == '+'){
        
        int nextNivel = 1 + laberintoActual->getNivel();
        if (cantLab == nextNivel) 
            return true;
        laberintoActual = listaLaberintos[nextNivel];
        int lastX = laberintoActual->getInicioX();    
        int lastY = laberintoActual->getInicioY();
        avatar->setPosX(lastX);
        avatar->setPosY(lastY);        
        dibujador.dibujarLaberinto(avatar,laberintoActual);
        
//        avatar->mover(destY,destX);
        dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    } else if (laberintoActual->getCelda(destY,destX) != '#'){
        avatar->mover(destY,destX);
        dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
    } else{        
        dibujador.borrarLinea(Dibujador::inputPos+1,1,Dibujador::ancho1);
        cout << "Error: Es una pared";
    }
    return false;
}

bool Juego::dir_Mover(void){
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
        return false;
    }
    bool flag = moverTo(dir); 
    return flag;
}


#endif	/* JUEGO_H */

