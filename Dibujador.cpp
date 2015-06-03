/* 
 * File:   Dibujador.cpp
 * Author: AlvaroPC
 * 
 * Created on June 2, 2015, 10:47 PM
 */


#include <windows.h>
#include "Dibujador.h"
#include <iostream>
using namespace std;

Dibujador::Dibujador() {
    Dibujador(5,5);
}

Dibujador::Dibujador(int a, int b) {
    A = a;
    B = b;
}

void Dibujador::dibujarXY(int Y, int X, string cadena){	
    HANDLE OutputH;										// This will be used for our handle to the output (basically, holds permission to change the output settings)
    COORD position = {X, Y};							// Create a COORD and set it's x and y to the X and Y passed in.
    
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);			// Get an OUTPUT handle to our screen
    WORD color = FOREGROUND_BLUE;
    SetConsoleTextAttribute(OutputH, color);		// Set the text attribute to what ever color that was passed in.														// The function SetConsoleTextAttribute() takes (the handle to the output, and the color);
    SetConsoleCursorPosition(OutputH, position);		// Set the cursor position to the desire position passed in
    cout << cadena; 					// Now print out what we wanted to at the position that was passed in
}

void Dibujador::dibujarCeldas(Avatar hero, Laberinto map) {
    
}

void Dibujador::dibujarLaberinto(Avatar hero, Laberinto map) {
    dibujarCeldas(hero,map);
}




