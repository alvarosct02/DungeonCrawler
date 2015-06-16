/* 
 * File:   GestorAvatar.h
 * Author: AlvaroPC
 *
 * Created on June 15, 2015, 5:55 AM
 */

#ifndef GESTORAVATAR_H
#define	GESTORAVATAR_H

#include <iostream>
#include <fstream>
#include <conio.h>

#include "Dibujador.h"
using namespace std;

class GestorImagenes {
public:
    GestorImagenes();
//    GestorAvatar(const GestorAvatar& orig);
    virtual ~GestorImagenes();
    int escogerAvatar(void);    
    int escogerImagenEntidad(void);
    void dibujarXY(int,int,char,WORD);
    void cargarAssets_Entidad(void);
    void cargarAssets(int, int*, int***);
private:
    ifstream archivo;
    int entidadArr[8][16][16];
    int sizeEntidadArr[8][2];
    int armaArr[20][8][8];
    int sizeArmaArr[2];
    int countEntidad;
    int countArma;
    void mostrarAvatar(int,int,int);
};

void GestorImagenes::mostrarAvatar(int id,int y, int x){    
    for (int j = 0 ; j<15; j++)
        for (int i=0; i< 15; i++)
            dibujarXY(j+y,i+x,' ',0);
    
    for (int j = 0 ; j<sizeEntidadArr[id][0]; j++){
        for (int i=0; i< sizeEntidadArr[id][1]; i++){           
            dibujarXY(j+y,i+x,' ',16*entidadArr[id][j][i]);
            //            personajeArr[count][j][i] = val;
        }
    }
}

void GestorImagenes::dibujarXY(int Y, int X, char cadena = 0,WORD color = 7){	
    HANDLE OutputH;	
    COORD position = {X, Y};				
    
    OutputH = GetStdHandle(STD_OUTPUT_HANDLE);	
    
    SetConsoleTextAttribute(OutputH,color);		

    SetConsoleCursorPosition(OutputH, position);	
    if (cadena) cout << cadena; 		
}


int GestorImagenes::escogerImagenEntidad(void){
    
}

int GestorImagenes::escogerAvatar(void){
    cout << "Bienvenido!\n";
    cout << "Desplazate usando las flechas del teclado\n";
    int c;
    int id = 0;
    bool flag = false;
    mostrarAvatar(id,5,5);
    while(true){
        c = getch();
        if (c != 224) break;   
        
        c = getch();
        switch(c) {
            case 77: id = (id+1)%countEntidad; break;
            case 75: id = (countEntidad+id-1)%countEntidad; break;
            default: flag = true; break;
        }
        if (flag) break;
        mostrarAvatar(id,5,5);
//        dibujador.dibujarLaberinto(avatar,laberintoActual);
    }
    return id;
//    
//    dibujarXY(20,0);
//    cout << endl;
}

void GestorImagenes::cargarAssets_Entidad(void){
    ifstream archivo;    
    archivo.open("personajes.txt", ios::in);
    if (!archivo){
        cerr << "File could not be opened" << endl;
        exit(1);
    }    
    
    countEntidad = 0;
    int row = 0;
    int col = 0;
    while(!archivo.eof()){
        archivo >> row >> col;
//        for ()
        for (int j = 0 ; j<row; j++){
            for (int i=0; i< col; i++){
                int val;
                archivo >> val;
                entidadArr[countEntidad][j][i] = val;
            }
        }
        sizeEntidadArr[countEntidad][0] = row;
        sizeEntidadArr[countEntidad][1] = col;
        
        countEntidad ++;
    }      
}


void GestorImagenes::cargarAssets(int count, int*sizeArr, int***imgArr){
    ifstream archivo;    
    archivo.open("armas.txt", ios::in);
    if (!archivo){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    
    int row = 0;
    int col = 0;
    count = 0;
    
    archivo >> row >> col;    
    sizeArr[0] = row;
    sizeArr[1] = col;
    
    while(!archivo.eof()){
        for (int j = 0 ; j<row; j++){
            for (int i=0; i< col; i++){
                int val;
                archivo >> val;
                imgArr[count][j][i] = val;
            }
        }        
        count ++;
    }      
}

GestorImagenes::GestorImagenes() {
    archivo.open("personajes.txt", ios::in);
    if (!archivo){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    
    countEntidad = 0;
    int row = 0;
    int col = 0;
    while(!archivo.eof()){
        archivo >> row >> col;
//        for ()
        for (int j = 0 ; j<row; j++){
            for (int i=0; i< col; i++){
                int val;
                archivo >> val;
                entidadArr[countEntidad][j][i] = val;
            }
        }
        
        sizeEntidadArr[countEntidad][0] = row;
        sizeEntidadArr[countEntidad][1] = col;
        
        countEntidad ++;
    }       
    
//    int id = count -1;
//    for (int j = 0 ; j<sizeArr[id][0]; j++){
//        for (int i=0; i< sizeArr[id][1]; i++){
//            
//            dibujarXY(j,i,' ',16*personajeArr[id][j][i]);
//            //            personajeArr[count][j][i] = val;
//        }
//    }
//    dibujarXY(15,0);
//    cout << "Hay " << count << endl;
    
//    Laberinto *lab = new Laberinto(matrix,row,col);
//    return lab; 
}



//GestorAvatar::GestorAvatar(const GestorAvatar& orig) {
//}

GestorImagenes::~GestorImagenes() {
    cout << "Personaje Seleccionado";
}


#endif	/* GESTORAVATAR_H */

