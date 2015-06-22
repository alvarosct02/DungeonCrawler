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
private:
    ifstream archivo;
    
    int ***entidadArr;
    int ***armaArr;
    int ***monstruoArr;
    int ****personajeArr;
    
    int *sizeEntidadArr;
    int *sizeArmaArr;
    int *sizeMonstruoArr;
    int *sizePersonajeArr;
    
    int countEntidad;
    int countArma;
    int countMonstruo;
    int countPersonaje;
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
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    char file[500];
    archivo.getline(file,500);
//    imgArr = new int***[atoi(file)];
    cout << atoi(file) << endl;
    while (archivo.getline(file,500)){
        cout << "el archivo que voy a leer es: " << file << endl;
//        cargarAssets(file,count,sizeArr,imgArr)
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

int GestorImagenes::getEntidad_NumRow(void){
    return sizeEntidadArr[0];
}

int GestorImagenes::getEntidad_NumCol(void){
    return sizeEntidadArr[1];
}



#endif	/* GESTORAVATAR_H */

