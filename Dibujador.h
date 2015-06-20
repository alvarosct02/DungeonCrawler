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
#define B_BLANCO 240
#define WIN_W 80
#define WIN_H 70
class Juego;

class Dibujador {
private:
    Juego *myParent;
    int A;
    int B;
public:
    static int ancho1;
    static int inputPos;
    Dibujador(Juego*);
    void setSize(int,int);
    void dibujarLaberinto(Avatar*,Laberinto*);
    void dibujarCeldas(Avatar*,Laberinto*);
    void dibujarZoom(Avatar *hero, Laberinto *map);
    void dibujarYX(int,int,char,WORD);
    void dibujarFondo(void);
    void setWindowsSize(int, int);
    void borrarLinea(int, int, int);
    
};

int Dibujador::ancho1 = 30;
int Dibujador::inputPos = 0;

Dibujador::Dibujador(Juego *parent) {
//    cout << "Dibujador Vacio\n";
    myParent = parent;
//    ancho1 = 30;
    A = 0;
    B = 0;
//    COLORREF cr;
//    cr = RGB(255,192,203);
//    PCONSOLE_SCREEN_BUFFER_INFO ci;
//    CONSOLE_SCREEN_BUFFER_INFO cir;
//    ci = &cir;
//    cout <<hex<< ci->ColorTable[2];
//    
//    GetConsoleScreenBufferInfo();
    
    
}

void Dibujador::setSize(int b, int a) {
    A = a;
    B = b;    
    inputPos = 7 + 2*(B+1);        
    ancho1 = max(ancho1,2 + 2*(A+1));    
    dibujarFondo();
    
}

void Dibujador::dibujarYX(int Y, int X, char cadena = 0,WORD color = 7){	
    HANDLE OutputH;	
    COORD position = {X, Y};				
    
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);	
    
    SetConsoleTextAttribute(OutputH,color);		

    SetConsoleCursorPosition(OutputH, position);	
    if (cadena) cout << cadena; 		
}

void Dibujador::dibujarZoom(Avatar *hero, Laberinto *map){
//    dibujarYX(4,ancho1+3,' ',B_BLANCO); este es el offset inicial
    int initX = ancho1+3;
    int initY = 4;
    
    int posX = hero->getPosX();
    int posY = hero->getPosY();  
    
    char tipo;
    int id;
    
    for (int i=-1; i<=1; i++){
        for (int j = -1; j<=1; j++){
            //asumiendo que el laberinto esta bien hecho
            //y el heroe nunca tiene adyacente una celda inexistente
            //(osea siempre hay al menos pared cerca)
            tipo =  map->getCelda(posX+j,posY+i);
            id = map->getCeldaID(posX+j,posY+i);
            
        }
    }
   
}

void Dibujador::dibujarCeldas(Avatar *hero, Laberinto *map) {
    int posX = hero->getPosX();
    int posY = hero->getPosY();  
    
    int initX = 1;
    int initY = 4;
    
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
    dibujarYX(inputPos-1,1);
    cout << "Ingrese comando:";
    dibujarYX(inputPos,1);
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
void Dibujador::dibujarFondo() {
    setWindowsSize(WIN_H,WIN_W);
    dibujarYX(1,1);
    cout << "Dungeon Crawler";
    dibujarYX(2,1);
    for (int i = 0; i<78; i++)
        cout << '_';
    for (int i = 3; i<inputPos+3; i++)
        dibujarYX(i,ancho1+1,'|');
    
    dibujarYX(inputPos-3,ancho1+3);  cout << "Comandos:";
    dibujarYX(inputPos-2,ancho1+3);  cout << " mover";
    dibujarYX(inputPos-1,ancho1+3);  cout << " usar";
    dibujarYX(inputPos,ancho1+3);    cout << " exit";
    
    dibujarYX(inputPos-3,ancho1+17); cout << "Direcciones:";
    dibujarYX(inputPos-2,ancho1+17); cout << " derecha   (d)";
    dibujarYX(inputPos-1,ancho1+17); cout << " arriba    (w)";
    dibujarYX(inputPos,ancho1+17);   cout << " izquierda (a)";
    dibujarYX(inputPos+1,ancho1+17); cout << " abajo     (s)";
    
    
}

void Dibujador::borrarLinea(int y, int x, int dist) {
    dibujarYX(y,x,'/',0);
    for (int i= 0; i<dist-1; i++)
        cout << '/';
    dibujarYX(y,x);
//    dibujarCeldas(hero,map);
}




#endif	/* DIBUJADOR_H */

