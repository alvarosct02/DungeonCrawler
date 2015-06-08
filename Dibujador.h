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
#define B_BLANCO 240

class Dibujador {
private:
    int A;
    int B;
public:
    static int ancho1;
    static int inputPos;
    Dibujador();
    void setSize(int,int);
    void dibujarLaberinto(Avatar*,Laberinto*);
    void dibujarCeldas(Avatar*,Laberinto*);
    void dibujarXY(int,int,char,WORD);
    void dibujarFondo(void);
    
    void borrarLinea(int, int, int);
};

int Dibujador::ancho1 = 30;
int Dibujador::inputPos = 0;

Dibujador::Dibujador() {
//    cout << "Dibujador Vacio\n";
    
//    ancho1 = 30;
    A = 0;
    B = 0;
}

void Dibujador::setSize(int b, int a) {
    A = a;
    B = b;    
    inputPos = 7 + 2*(B+1);        
    ancho1 = max(ancho1,2 + 2*(A+1));    
    dibujarFondo();
    
}

void Dibujador::dibujarXY(int Y, int X, char cadena = 0,WORD color = 7){	
    HANDLE OutputH;										// This will be used for our handle to the output (basically, holds permission to change the output settings)
    COORD position = {X, Y};							// Create a COORD and set it's x and y to the X and Y passed in.
    
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);	
    
    SetConsoleTextAttribute(OutputH,color);		
    // Set the text attribute to what ever color that was passed in.														// The function SetConsoleTextAttribute() takes (the handle to the output, and the color);
    SetConsoleCursorPosition(OutputH, position);		// Set the cursor position to the desire position passed in
    if (cadena) cout << cadena; 					// Now print out what we wanted to at the position that was passed in
}

void Dibujador::dibujarCeldas(Avatar *hero, Laberinto *map) {
    int posX = hero->getPosX();
    int posY = hero->getPosY();  
    
    int initX = 1;
    int initY = 4;
//    for (int k = 0 ; k<16 ;k++)
//        dibujarXY(0,k,'#',k);
    for (int j = posY-B-1, j2 = initY; j2<=initY+2*B+2; j++, j2++){
        for (int i = posX-A-1, i2 = initX; i2<=initX + 2*A+2; i++, i2++){
            if (j2==initY || j2 == initY+2*B+2 || i2==initX || i2 == initX+2*A+2)
                dibujarXY(j2,i2,' ',B_BLANCO);   
            else {
                if (i<0 || j<0 || i >= map->getN() || j >= map->getM())
                    dibujarXY(j2,i2,'F',0);        
                else 
                    dibujarXY(j2,i2,map->getCelda(j,i),12);
            }
        }
        
    }
    dibujarXY(initY+B+1,initX+A+1,'A',15);
    dibujarXY(inputPos-1,1);
    cout << "Ingrese comando:";
    dibujarXY(inputPos,1);
}

void Dibujador::dibujarLaberinto(Avatar *hero, Laberinto *map) {    
    dibujarCeldas(hero,map);
}


void Dibujador::dibujarFondo() {
    dibujarXY(1,1);
    cout << "Dungeon Crawler";
    dibujarXY(2,1);
    for (int i = 0; i<78; i++)
        cout << '_';
    for (int i = 3; i<inputPos+3; i++)
        dibujarXY(i,ancho1+1,'|');
    
    dibujarXY(inputPos-3,ancho1+3);  cout << "Comandos:";
    dibujarXY(inputPos-2,ancho1+3);  cout << " mover";
    dibujarXY(inputPos-1,ancho1+3);  cout << " usar";
    dibujarXY(inputPos,ancho1+3);    cout << " exit";
    
    dibujarXY(inputPos-3,ancho1+17); cout << "Direcciones:";
    dibujarXY(inputPos-2,ancho1+17); cout << " derecha   (d)";
    dibujarXY(inputPos-1,ancho1+17); cout << " arriba    (w)";
    dibujarXY(inputPos,ancho1+17);   cout << " izquierda (a)";
    dibujarXY(inputPos+1,ancho1+17); cout << " abajo     (s)";
    
    
}

void Dibujador::borrarLinea(int y, int x, int dist) {
    dibujarXY(y,x,'/',0);
    for (int i= 0; i<dist-1; i++)
        cout << '/';
    dibujarXY(y,x);
//    dibujarCeldas(hero,map);
}




#endif	/* DIBUJADOR_H */

