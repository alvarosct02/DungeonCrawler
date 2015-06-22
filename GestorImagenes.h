/* 
 * File:   GestorAvatar.h
 * Author: AlvaroPC
 *
 * Created on June 15, 2015, 5:55 AM
 */

#ifndef GESTORAVATAR_H
#define	GESTORAVATAR_H

#include <cstdlib>
#include <iostream>
#include <fstream>
//
//#include "Arma.h"

using namespace std;

class GestorImagenes {
public:
    GestorImagenes();
//    GestorAvatar(const GestorAvatar& orig);
    virtual ~GestorImagenes();
    void cargarAssets(string,int&, int*&, int***&);
    void cargarAssetsMultiples(string,int&, int*&, int****&);
    int getCountEntidad() const;
    int getEntidad_Value(int,int,int);    
    int getEntidad_NumCol(void); 
    int getEntidad_NumRow(void);    
    
    int getCountArma() const;
    int getArma_Value(int,int,int);    
    
    int getCountMonstruo() const;
    int getMonstruo_Value(int,int,int); 
//    int getArma_NumCol(void); 
//    int getArma_NumRow(void);
    
    int getPersonaje_Value(int,int,int,int,int);
    int getPared_Value(int,int,int,int);
    
    void imprimirArreglo(int**,int*);
    void imprimirAsset(int***,int*,int);
    void imprimirListaAssets(int****,int*,int);
private:
    ifstream archivo;
    
    int ***entidadArr;
    int ***armaArr;
    int ***monstruoArr;
    int ****personajeArr;
    int ****paredArr;
    
    int *sizeEntidadArr;
    int *sizeArmaArr;
    int *sizeMonstruoArr;
    int *sizePersonajeArr;
    int *sizeParedArr;
    
    int countEntidad;
    int countArma;
    int countMonstruo;
    int countPersonaje;
    int countPared;
};

GestorImagenes::GestorImagenes() {
    string name;
    name = "personajes.txt";
    cargarAssets(name,countEntidad,sizeEntidadArr,entidadArr);    
    name = "armas.txt";
    cargarAssets(name,countArma,sizeArmaArr,armaArr);     
    name = "monstruos.txt";
    cargarAssets(name,countMonstruo,sizeMonstruoArr,monstruoArr);  
    name = "lista-personajes.txt";
    cargarAssetsMultiples(name,countPersonaje,sizePersonajeArr,personajeArr);
    name = "paredes.txt";
    cargarAssetsMultiples(name,countPared,sizeParedArr,paredArr);
//    imprimirAsset(monstruoArr,sizeMonstruoArr,countMonstruo);
}

GestorImagenes::~GestorImagenes() {    
    for (int k = 0 ; k<countEntidad; k++){
        for (int j = 0 ; j< sizeEntidadArr[0]; j++)
            delete [] entidadArr[k][j];         
        delete [] entidadArr[k];    
    }
    delete [] entidadArr;
    delete [] sizeEntidadArr;
    
    for (int k = 0 ; k<countArma; k++){
        for (int j = 0 ; j< sizeArmaArr[0]; j++)
            delete [] armaArr[k][j];         
        delete [] armaArr[k];    
    }
    delete [] armaArr;
    delete [] sizeArmaArr;
    
    for (int k = 0 ; k<countMonstruo; k++){
        for (int j = 0 ; j< sizeMonstruoArr[0]; j++)
            delete [] monstruoArr[k][j];         
        delete [] monstruoArr[k];    
    }
    delete [] monstruoArr;
    delete [] sizeMonstruoArr;
}

void GestorImagenes::cargarAssetsMultiples(string fileName, int&count, int*&sizeArr, int****&imgArr){
    ifstream archivo(fileName.c_str());
    if (!archivo){
        cerr << "File could not be opened asd" << endl;
        exit(1);
    }
    char file[500];
    archivo.getline(file,500);
    int cant = atoi(file);
    imgArr = new int***[cant];
    for (int i=0; i<cant; i++){
        archivo.getline(file,500);
        cargarAssets(file,count,sizeArr,imgArr[i]);
    }   
}

void GestorImagenes::cargarAssets(string fileName,int &count, int*&sizeArr, int***& imgArr){
    ifstream archivo(fileName.c_str());
    if (!archivo){
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    
    int row,col;
    
    archivo >> count >> row >> col; 
    sizeArr = new int[2];
    sizeArr[0] = row;
    sizeArr[1] = col;
    
    int ***arr = new int** [count];
    int **rowArr = NULL;
    int *colArr = NULL;
    
    for (int k = 0; k < count; k++){
        rowArr  = new int*[row];        
        for (int j = 0; j < row; j++){
            colArr =  new int[col];  
            for (int i=0; i< col; i++){
                int val;
                archivo >> val;
                colArr[i] = val;
            }
            rowArr[j] =colArr;
        } 
        arr[k] = rowArr;
    }    
    imgArr = arr;
}

int GestorImagenes::getCountArma() const {
    return countArma;
}

int GestorImagenes::getCountEntidad() const {
    return countEntidad;
}

int GestorImagenes::getCountMonstruo() const {
    return countMonstruo;
}

int GestorImagenes::getMonstruo_Value(int id, int row, int col){
    return monstruoArr[id][row][col];
}

int GestorImagenes::getEntidad_Value(int id, int row, int col){
    return entidadArr[id][row][col];
}

int GestorImagenes::getArma_Value(int id, int row, int col){
    return armaArr[id][row][col];
}

int GestorImagenes::getPersonaje_Value(int id, int anim, int dir, int row, int col){
    return personajeArr[id][dir*2+anim][row][col];
}

int GestorImagenes::getPared_Value(int id,int random, int row, int col){
    return paredArr[0][0][row][col];
}

int GestorImagenes::getEntidad_NumRow(void){
    return sizeEntidadArr[0];
}

int GestorImagenes::getEntidad_NumCol(void){
    return sizeEntidadArr[1];
}

void GestorImagenes::imprimirArreglo(int**arr,int*size){
    for (int i=0; i<size[0]; i++){
        for (int j=0; j<size[1]; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void GestorImagenes::imprimirAsset(int***asset,int*size,int cant){
    for (int i=0; i<cant; i++){
        imprimirArreglo(asset[i],size);
        cout << endl;
    }
    cout << endl;
}


#endif	/* GESTORAVATAR_H */

