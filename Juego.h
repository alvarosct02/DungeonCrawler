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
#include "GestorImagenes.h"
#include <ctime>
#include <cmath>
#include <conio.h> 
#define SIZE 5
#define PI 3.14159
#define A 7
#define B 10

class Juego {
private:
    Laberinto *laberintoActual;
    Laberinto **listaLaberintos;
    Monstruo ***matrizMonstruos;    
    Artefacto ***matrizArtefactos;
    int* cantMonstruos; 
    int* cantArtefactos; 
    
    int cantLab;
    Avatar* avatar;
    Dibujador *dibujador;
    GestorImagenes *gestAvatar;
    GestorLaberinto gestLab;
    
    void cargarLaberintos(void);
    void desordenarLaberintos(void);
    void imprimirLaberintos(void);
    void initJuego(void);     
    void dir_Exit(void);
    
    bool cmd_MoverManual(void);  
    bool cmd_MoverKeyboard(void);
    bool cmd_SalirJuego(void);    
    bool cmd_Interactuar(void);    
    bool cmd_Usar(void);
    
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
                int id  = rand() % gestAvatar->getCountMonstruo();                   
                Monstruo* monst = new Monstruo("Guanira",j,i,1,id);
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
                    
                    int id  = rand() % gestAvatar->getCountArma();      
                    artef = new Armadura(4,id);
                } else {
                    int id  = rand() % gestAvatar->getCountArma();     
                    artef = new PocionCuracion(4,id);
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
        agregarMyA(matrizMonstruos[i],matrizArtefactos[i],cantMonstruos[i],cantArtefactos[i],listaLaberintos[i]);  
    }
    listaLaberintos[cantLab-1]->setNivel(cantLab-1);
    agregarMyA(matrizMonstruos[cantLab-1],matrizArtefactos[cantLab-1],
        cantMonstruos[cantLab-1],cantArtefactos[cantLab-1],listaLaberintos[cantLab-1]);  

}

void Juego::initJuego(void){
    
    listaLaberintos = new Laberinto*[SIZE];
    matrizMonstruos = new Monstruo**[SIZE];
    matrizArtefactos = new Artefacto**[SIZE];
    cantMonstruos = new int[SIZE];
    cantArtefactos = new int[SIZE];
    
    cargarLaberintos();
    desordenarLaberintos();
    
//    Asignar el primer Laberinto
    laberintoActual = listaLaberintos[0];
    
//    Posicionar el Avatar
    int lastX = laberintoActual->getInicioX();    
    int lastY = laberintoActual->getInicioY();
    
    
    int idAvatar = dibujador->escogerAvatar(); //ESTO LO DEBE HACER DIBJADOR
    avatar = new Avatar("Alvaro",lastY,lastX,100,idAvatar);
    
    dibujador->setSize(A,B);    
    dibujador->dibujarLaberinto(avatar,laberintoActual);
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
    delete dibujador;
}
  
Juego::Juego() { 
    gestAvatar = new GestorImagenes();
    dibujador = new Dibujador(this,gestAvatar);
    
    initJuego();
    
    string comando;
    while(true){
        dibujador->writeCommand();
        cin >> comando;
        if ( ejecutarComando(comando) )
            break;
        dibujador->dibujarLaberinto(avatar,laberintoActual);        
    }
//    
    
    cout << "\n\n";
}

bool Juego::ejecutarComando(string comando) {
    bool flag = false;
    if (comando == "mover"){        
        flag = cmd_MoverManual();
    } else if (comando == "run"){
        flag = cmd_MoverKeyboard();
    } else if (comando == "exit"){
        flag = cmd_SalirJuego();
    } else if (comando == "interactuar"){
        flag = cmd_Interactuar();
    } else {        
        dibujador->writeCommandComment("Error Comando Invalido");
    }
    
//    Limpiar espacio Comando
    return flag;
}

bool Juego::cmd_Usar(void) {
    return false;
}
bool Juego::cmd_Interactuar(void) {
    int dir;
    dir = avatar->getDir();    
//    cout << "Avatar >> " << dir;
    
    float xDir = (cos(PI*dir/2.0));
    float yDir = (sin(PI*dir/2.0));
    int destX = avatar->getPosX() + int(xDir);
    int destY = avatar->getPosY() + int(yDir);    
    
//    Pasar al siguiente NIVEL
    if (laberintoActual->getCelda(destY,destX) == 'A'){
        dibujador->writeCommandComment("Es un artefacto");
        Celda* celda = laberintoActual->getCeldaPtr(destY,destX);
        avatar->agregarObjeto(celda->GetArtefacto());
        avatar->listarObjetos();
        celda->SetArtefacto(NULL);
    }
    else if (laberintoActual->getCelda(destY,destX) == 'M'){
        dibujador->writeCommandComment("Es un monstruo");
//        Celda* celda = laberintoActual->getCeldaPtr(destY,destX);
//        avatar->agregarObjeto(celda->GetMonstruo());
//        celda->SetArtefacto(NULL);
    } 
    else {
        dibujador->writeCommandComment("Aqui no hay nada");
        
    }
    dibujador->dibujarLaberinto(avatar,laberintoActual);
    return false;
}

bool Juego::cmd_MoverKeyboard(void) {    
    dibujador->writeCommand("Running mode...");
    int c;
    bool flag = false;
    while(true){
        c = getch();
        
        if (c == 101){
            cmd_Interactuar();      
            continue;
        }  
        else if (c != 224) break;   
        
        c = getch();
        switch(c) {
            case 72: flag = moverTo(3); break;
            case 80: flag = moverTo(1); break;
            case 77: flag = moverTo(0); break;
            case 75: flag = moverTo(2); break;
            default: break;
        }
        if (flag) break;       
        dibujador->dibujarLaberinto(avatar,laberintoActual);
    }
    return flag;
}

bool Juego::moverTo(int dir){    
    avatar->setDir(dir);
    float xDir = (cos(PI*dir/2.0));
    float yDir = (sin(PI*dir/2.0));
    int destX = avatar->getPosX() + int(xDir);
    int destY = avatar->getPosY() + int(yDir);    
    
//    Pasar al siguiente NIVEL
    if (laberintoActual->getCelda(destY,destX) == '+'){        
        int nextNivel = 1 + laberintoActual->getNivel();
        if (cantLab+1 == nextNivel) return true;
        laberintoActual = listaLaberintos[nextNivel-1];
        int lastX = laberintoActual->getInicioX();    
        int lastY = laberintoActual->getInicioY();
//        avatar->setPosX(lastX);                                                    //JJ: ESTO NO DEBERIA HACERSE CON ENTIDAD::MOVER??
//        avatar->setPosY(lastY);  
        avatar->mover(lastY,lastX);
        dibujador->dibujarLaberinto(avatar,laberintoActual);
        
//        avatar->mover(destY,destX);
    } 
//    Ir al NIVEL anterior
    else if (laberintoActual->getCelda(destY,destX) == '-'){  
//        dibujador->writeCommandComment("Vamos al nivel anterior");
        
        int lastNivel = -1 + laberintoActual->getNivel();
        if (0 == lastNivel)  {
            dibujador->writeCommandComment("No puedes volver atras");
            return false;
        }
        else{
            laberintoActual = listaLaberintos[lastNivel-1];
            int lastX = laberintoActual->getFinalX();    
            int lastY = laberintoActual->getFinalY();
    //        avatar->setPosX(lastX);                                                    //JJ: ESTO NO DEBERIA HACERSE CON ENTIDAD::MOVER??
    //        avatar->setPosY(lastY);  
            avatar->mover(lastY,lastX);
            dibujador->dibujarLaberinto(avatar,laberintoActual);
        }
    }
//    Mover a la celda indicada
    else if (laberintoActual->getCelda(destY,destX) == ' '){
        avatar->mover(destY,destX);
        dibujador->writeCommandComment();
    } 
//    Mostrar el error correspondiente
    else if (laberintoActual->getCelda(destY,destX) == 'M'){
        avatar->mover(destY,destX);
        dibujador->writeCommandComment();
    } 
    else if (laberintoActual->getCelda(destY,destX) == 'A'){
        dibujador->writeCommandComment("Wow es un artefacto!");
    } 
    else{        
        dibujador->writeCommandComment("Error: Es una pared");
    }    
    return false;
}

bool Juego::cmd_SalirJuego(void){    
    return true;
}
bool Juego::cmd_MoverManual(void){   
    string aux;
    int dir;
    
    dibujador->writeCommandComment("Falta ingresar direccion");    
    dibujador->writeCommand("mover ");    
    cin >> aux;          
    dibujador->writeCommand();
    
    if (aux == "d")      dir = 0;
    else if (aux == "w") dir = 3;
    else if (aux == "a") dir = 2;
    else if (aux == "s") dir = 1;
    else{
        dibujador->writeCommandComment("Error: Direccion invalida");    
        return false;
    }
    return moverTo(dir);
}

#endif	/* JUEGO_H */

