/* 
 * File:   main.cpp
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 9:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include "Avatar.h"
#include "Monstruo.h"
#include <list>
#include "GestorLaberinto.h"
using namespace std;

/*
 * 
 */

void writeColor(string cadena, int X, int Y, WORD color){	
    HANDLE OutputH;										// This will be used for our handle to the output (basically, holds permission to change the output settings)
    COORD position = {X, Y};							// Create a COORD and set it's x and y to the X and Y passed in.
    
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);			// Get an OUTPUT handle to our screen

    SetConsoleTextAttribute(OutputH, color);		// Set the text attribute to what ever color that was passed in.														// The function SetConsoleTextAttribute() takes (the handle to the output, and the color);
    SetConsoleCursorPosition(OutputH, position);		// Set the cursor position to the desire position passed in
    cout << cadena; 					// Now print out what we wanted to at the position that was passed in
}
int main(int argc, char** argv) {
    
    cout << "pingaaaaaaaaa" << endl << endl;
    Avatar alvaro("ASCT",4,5,100);
    cout << alvaro.getNombre() << endl;
    cout << alvaro.getPosX() << endl;
    cout << alvaro.getPosY() << endl;
    cout << alvaro.getMaxVida() << endl;
    
    Monstruo juanjo;
    cout << juanjo.getNombre() << endl;
    cout << juanjo.getPosX() << endl;
    cout << juanjo.getPosY() << endl;
    cout << juanjo.getMaxVida() << endl;
    
//    writeColor("Red",  0, 0, FOREGROUND_RED);		// Draw "Red" in the color RED.  Draw "White" in the color WHITE.  If we OR ("|") the colors together, it becomes white.
//    writeColor("White",0, 1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//    writeColor("Blue", 1, 0, FOREGROUND_BLUE);	// Draw "Blue" in the color BLUE.
//
//    writeColor("Red",  0, 4, BACKGROUND_RED);		// Draw "Red" with a background of RED.  Draw "White" with a background of WHITE.
//    writeColor("White",10, 5, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
//    writeColor("Blue", 20, 6, BACKGROUND_BLUE);	// Draw "Blue" with a background of BLUE.

    return 0;
}

