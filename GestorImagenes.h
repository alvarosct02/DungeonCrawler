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

using namespace std;

class GestorImagenes {
public:
    GestorImagenes();
//    GestorAvatar(const GestorAvatar& orig);
    virtual ~GestorImagenes();
    void cargarAssets(string,int&, int*&, int***&);
    int getCountArma() const;
    int getCountEntidad() const;
    int getEntidad_Value(int,int,int);    
    int getEntidad_NumCol(void); 
    int getEntidad_NumRow(void);
private:
    ifstream archivo;
    int ***entidadArr;
    int *sizeEntidadArr;
    int ***armaArr;
    int *sizeArmaArr;
    int countEntidad;
    int countArma;
};


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

int GestorImagenes::getEntidad_Value(int id, int row, int col){
    return entidadArr[id][row][col];
}

int GestorImagenes::getEntidad_NumRow(void){
    return sizeEntidadArr[0];
}

int GestorImagenes::getEntidad_NumCol(void){
    return sizeEntidadArr[1];
}

GestorImagenes::GestorImagenes() {
    string name = "personajes.txt";
    cargarAssets(name,countEntidad,sizeEntidadArr,entidadArr);    
}

GestorImagenes::~GestorImagenes() {    
    for (int k = 0 ; k<countEntidad; k++){
        for (int j = 0 ; j< sizeEntidadArr[0]; j++)
            delete [] entidadArr[k][j];         
        delete [] entidadArr[k];    
    }
    delete [] entidadArr;
}


#endif	/* GESTORAVATAR_H */

