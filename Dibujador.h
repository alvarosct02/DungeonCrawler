/* 
 * File:   Dibujador.h
 * Author: AlvaroPC
 *
 * Created on June 2, 2015, 10:47 PM
 */

#ifndef DIBUJADOR_H
#define	DIBUJADOR_H

#include "Laberinto.h"
#include "Avatar.h"
#include "Juego.h"
#include "GestorImagenes.h"
#include <conio.h>
#include <windows.h>


#define B_BLANCO 240
#define WIN_W 59
#define WIN_H 52
#define log_size 4

class Juego;

class Dibujador {
private:
    Juego *myParent;
    GestorImagenes *imageRep;
    int A;
    int B;
    int widthLeft;
    int inputPos;
    string combatLog[log_size] ;
public:
    
    Dibujador(Juego*,GestorImagenes*);
    
    void writeCommand(string);
    void console(string);
    void writeCommandList(int);
    
    void setSize(int,int);
    void dibujarLaberinto(Avatar*,Laberinto*);
    void dibujarCeldas(Avatar*,Laberinto*);
    void dibujarZoom(Avatar *hero, Laberinto *map);
    void dibujarYX(int,int,char,WORD);
    void dibujarFondo(void);
    void setWindowsSize(int, int);
    void borrarLinea(int, int, int);

    int escogerAvatar(void);    
    
    void mostrarAvatarFull(int,int,int);  
    
    void mostrarAvatar(int,int,int,int,int);  
    void mostrarPared(int,int,int,int);
    void mostrarArma(int,int,int);  
    void mostrarEspacio(int,int,int);  
    void mostrarMonstruo(int,int,int);  
    void drawRect(int,int,int,int,int);
    
    void drawInfo(Entidad*,int, int);
    
    
    
};

void Dibujador::drawInfo(Entidad* entidad, int tileY, int tileX){
    int idImg = entidad->getIdImg();
    
//    int atk = entidad->
//    Dibujar el Arma Actual
    Artefacto *arma = entidad->getSaco()->getCurArmadura();
    if (arma != NULL){
        int itemIMG = arma->getIdImg();
//      dibujar la imagen                
    }
    
//    Dibujar el Armadura Actual
    Artefacto *armadura = entidad->getSaco()->getCurArma();
    if (armadura != NULL){
        int itemIMG = armadura->getIdImg();
//      dibujar la imagen                
    }
    
//    Dibujar el saco
    for (int j=0 ; j<2; j++){
        for (int i=0; i<3 ; i++){
            int pos = j*3 + i;
            Artefacto *item = entidad->getSaco()->getObjeto(pos);
            if (item != NULL){
                int itemIMG = item->getIdImg();
//                dibujar la imagen                
            }             
        }
    }
    
    
    
    
}
Dibujador::Dibujador(Juego *parent, GestorImagenes *gest) {
    widthLeft = 30;
    inputPos = 0;
    myParent = parent;
    imageRep = gest;
    for(int i=0; i<log_size;i++)
        combatLog[i] = "";
    A = 0;
    B = 0;
}

void Dibujador::dibujarYX(int Y, int X, char cadena = 0, WORD color = 7){	
    HANDLE OutputH;	
    COORD position = {X, Y};				
    
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);	
    
    SetConsoleTextAttribute(OutputH,color);		

    SetConsoleCursorPosition(OutputH, position);	
    if (cadena) cout << cadena; 		
}

void Dibujador::borrarLinea(int y, int x, int dist) {
    dibujarYX(y,x,'/',0);
    for (int i= 0; i<dist-1; i++)
        cout << '/';
    dibujarYX(y,x);
//    dibujarCeldas(hero,map);
}
void Dibujador::writeCommand(string cad = ""){
    borrarLinea(inputPos,6,widthLeft); //modificar aqui la linea de comando **
    if (cad != "")
        cout << cad;   
}
void Dibujador::console(string cad = ""){
//    borrarLinea(inputPos+1,1,widthLeft);
    if(cad != ""){
        for(int i=log_size-1;i>0;i--){
            combatLog[i] = combatLog[i-1];
            borrarLinea(inputPos-i-3,3,widthLeft);
            cout << combatLog[i] << endl;
        }
        combatLog[0] = cad;
        borrarLinea(inputPos-0-3,3,widthLeft);
        cout << combatLog[0] << endl;
    
    }
//    if (cad != "")
//        cout << cad;   
}
void Dibujador::writeCommandList(int id){
    //segun el int escribe tipos de comandos
    switch(id){
        case 0: 
            console("Comandos Normales");
            break;
        case 1:
            console("Comandos de Batalla");
            break; 
    }
}

void Dibujador::mostrarAvatarFull(int id,int y, int x){    
    for (int j = 0 ; j<16; j++)
        for (int i=0; i< 16; i++)
            dibujarYX(j+y,i+x,' ',0);
    
    for (int j = 0 ; j< imageRep->getEntidad_NumRow(); j++){
        for (int i=0; i< imageRep->getEntidad_NumCol(); i++){
            int val = 16* imageRep->getEntidad_Value(id,j,i);
            dibujarYX(j+y,i+x,' ',val);
            //            personajeArr[count][j][i] = val;
        }
    }
}

void Dibujador::mostrarAvatar(int id,int anim, int dir, int y, int x){  
    for (int j = 0 ; j< 10; j++){
        for (int i=0; i< 10; i++){                   
            int val = 16* imageRep->getPersonaje_Value(id,anim,dir,j,i);
            dibujarYX(j+y,i+x,' ',val);
        }
    }
}

void Dibujador::mostrarPared(int id,int random, int y,int x){
    for (int j = 0 ; j< 10; j++){
        for (int i=0; i< 10; i++){                   
            int val = 16* imageRep->getPared_Value(id,random,j,i);
            dibujarYX(j+y,i+x,' ',val);
        }
    }         
              
}

void Dibujador::mostrarEspacio(int id,int y, int x){  
    for (int j = 0 ; j< 10; j++)
        for (int i=0; i< 10; i++)       
            dibujarYX(j+y,i+x,' ');
}

void Dibujador::mostrarArma(int id,int y, int x){  
    for (int j = 0 ; j< 10; j++){
        for (int i=0; i< 10; i++){                   
            int val = 16* imageRep->getArma_Value(id,j,i);
            dibujarYX(j+y,i+x,' ',val);
        }
    } 
}

void Dibujador::mostrarMonstruo(int id,int y, int x){  
    for (int j = 0 ; j< 10; j++){
        for (int i=0; i< 10; i++){                   
            int val = 16* imageRep->getMonstruo_Value(id,j,i);
            dibujarYX(j+y,i+x,' ',val);
        }
    } 
}

int Dibujador::escogerAvatar(void){
    cout << "Bienvenido!\n";
    cout << "Desplazate usando las flechas del teclado\n";
    int c;
    int id = 0;
    bool flag = false;
    mostrarAvatarFull(id,5,5);
    while(true){
        c = getch();
        if (c != 224) break;   
        
        c = getch();
        switch(c) {
            case 77: id = (id+1)%(imageRep->getCountEntidad()); break;
            case 75: id = (imageRep->getCountEntidad()+id-1)%imageRep->getCountEntidad(); break;
            default: flag = true; break;
        }
        if (flag) break;
        mostrarAvatarFull(id,5,5);
    }
    return id;
}
void Dibujador::setSize(int b, int a) {
    A = a;
    B = b;    
    inputPos = 49;        
    widthLeft = max(widthLeft,2 + 2*(A+1));    
    dibujarFondo();    
}



void Dibujador::dibujarZoom(Avatar *hero, Laberinto *map){
//    dibujarYX(4,ancho1+3,' ',B_BLANCO); este es el offset inicial
    int initX = 2;
    int initY = 2;
    
    int posX = hero->getPosX();
    int posY = hero->getPosY();  
    
    char tipo;
    int id;
    
    for (int j=-1; j<=1; j++){
        for (int i = -1; i<=1; i++){
            //asumiendo que el laberinto esta bien hecho
            //y el heroe nunca tiene adyacente una celda inexistente
            //(osea siempre hay al menos pared cerca)
            
            if (i==0 && j==0)
                mostrarAvatar(hero->getIdImg(),hero->getAnim(),hero->getDir(),initY+(1+j)*10,initX+(1+i)*10);
            else {                
                tipo =  map->getCelda(posY+j,posX+i);            
                id = map->getCeldaID(posY+j,posX+i);     
    //            dibujarYX(initY+1+j,initX+1+i,tipo);
                if (tipo == 'A')
                    mostrarArma(id,initY+(1+j)*10,initX+(1+i)*10);
                else if (tipo == '#')
                    mostrarPared(map->getNivel()-1,map->getCeldaRandom(posY+j,posX+i),initY+(1+j)*10,initX+(1+i)*10);
//                    mostrarPared(map->getNivel()-1,0,initY+(1+j)*10,initX+(1+i)*10);
                else if (tipo == 'M')
                    mostrarMonstruo(id,initY+(1+j)*10,initX+(1+i)*10); 
                else mostrarEspacio(id,initY+(1+j)*10,initX+(1+i)*10);
            }                  
        }
    }   
}

void Dibujador::dibujarCeldas(Avatar *hero, Laberinto *map) {
    int posX = hero->getPosX();
    int posY = hero->getPosY();  
    
    int initX = 34;
    int initY = 34;
    
//    Pintar el Espacio del Laberinto (esq. superior izquierda)
    for (int j = posY-B-1, j2 = initY; j2<=initY+2*B+2; j++, j2++){
        for (int i = posX-A-1, i2 = initX; i2<=initX + 2*A+2; i++, i2++){
            if (j2==initY || j2 == initY+2*B+2 || i2==initX || i2 == initX+2*A+2)
                dibujarYX(j2,i2,' ',B_BLANCO);   
            else {
                if (i<0 || j<0 || i >= map->getN() || j >= map->getM())
                    dibujarYX(j2,i2,'F',0);        
                else if (map->getCelda(j,i) == '*'){                    
                    dibujarYX(j2,i2,'F',0);                    
                }
                else {                    
                    dibujarYX(j2,i2,map->getCelda(j,i),12);                    
                }                    
            }
        }        
    }
    dibujarYX(initY+B+1,initX+A+1,'A',15);
    
}

void Dibujador::dibujarLaberinto(Avatar *hero, Laberinto *map) {    
    dibujarCeldas(hero,map);
    dibujarZoom(hero,map);
}

void Dibujador::setWindowsSize(int h, int w){
    HANDLE OutputH;										// This will be used for our handle to the output (basically, holds permission to change the output settings)
    COORD position = {WIN_W, WIN_H};    
    SMALL_RECT r;
    r.Left   = 0;
    r.Top    = 0;
    r.Right  = WIN_W -1;
    r.Bottom = WIN_H -1;
//    SetConsoleWindowInfo( hConOut, TRUE, &r );
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);	
    SetConsoleScreenBufferSize(OutputH,position);
    SetConsoleWindowInfo(OutputH,TRUE,&r);
    
}

void Dibujador::drawRect(int y, int x, int h, int w, int color){
    h++;
    w++;
    
    for (int i = 0; i<=w; i++){
        dibujarYX(y, x+i,' ',color);
        dibujarYX(y+h, x+i,' ',color);
    }   
    for (int i = 0; i<=h; i++){
        dibujarYX(y+i, x,' ',color);
        dibujarYX(y+i, x+w,' ',color);
    }
}

void Dibujador::dibujarFondo() {   
    
    int initY = 1;
    int initX = 1;
    
    setWindowsSize(WIN_H,WIN_W);
    
    drawRect(1,1,30,30,16*15);
    drawRect(34,1,15,30,16*15);
    drawRect(17,34,14,21,16*15);
    drawRect(34,34,15,21,16*15);
    
    dibujarYX(inputPos,2);
    cout << "CMD:";
    
//    drawRect(1,1,30,30,16*15);
    
//    dibujarYX(1,1);
//    cout << "Dungeon Crawler";
//    dibujarYX(2,1);
//    for (int i = 0; i<78; i++)
//        cout << '_';
//    for (int i = 3; i<inputPos+3; i++)
//        dibujarYX(i,widthLeft+1,'|');
//
//    dibujarYX(inputPos-3,widthLeft+3);  cout << "Comandos:";
//    dibujarYX(inputPos-2,widthLeft+3);  cout << " mover";
//    dibujarYX(inputPos-1,widthLeft+3);  cout << " usar";
//    dibujarYX(inputPos,widthLeft+3);    cout << " exit";
//
//    dibujarYX(inputPos-3,widthLeft+17); cout << "Direcciones:";
//    dibujarYX(inputPos-2,widthLeft+17); cout << " derecha   (d)";
//    dibujarYX(inputPos-1,widthLeft+17); cout << " arriba    (w)";
//    dibujarYX(inputPos,widthLeft+17);   cout << " izquierda (a)";
//    dibujarYX(inputPos+1,widthLeft+17); cout << " abajo     (s)";
}





#endif	/* DIBUJADOR_H */

