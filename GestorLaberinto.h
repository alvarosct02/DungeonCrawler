/* 
 * File:   GestorLaberinto.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 11:17 PM
 */

#ifndef GESTORLABERINTO_H
#define	GESTORLABERINTO_H

#include "Laberinto.h"
#include "pugiconfig.hpp"
//#include "pugixml.cpp"
#include "pugixml.hpp"
#include <fstream>
#include <iostream>
#define MAX 200
using namespace std;
using namespace pugi;

class GestorLaberinto{
private:
    string aux;
    ifstream archivo;
    void leerXML(char*cad, Celda*** &matrix, int &row, int&col);
public:
    Laberinto* crear(void);
    GestorLaberinto(void);
    virtual ~GestorLaberinto(void);
};

GestorLaberinto::~GestorLaberinto() {   
    cout << "   Gestor Destruido\n";
} 
GestorLaberinto::GestorLaberinto() {  
//    gestorXML.leerMapas("mapas.txt");
//    archivo.open("labFile.txt", ios::in);
//    if (!archivo){
//        cerr << "File could not be opened" << endl;
//        exit(1);
//    }
    archivo.open("mapas.txt");
    if (!archivo){
        cerr << "Error al cargar mapas.txt " << endl;
        exit(1);
    }
//    archivo >> aux;
}

void GestorLaberinto::leerXML(char*cad, Celda*** &matrix, int &row, int&col){
    xml_document doc;
    if (!doc.load_file(cad))
    {
            cerr << "Error al cargar el documento XML "<< cad << endl;
            exit(1);
    }
    // Creamos un objeto nodo
    xml_node raiz;
    // Le asignamos el nodo principal comprobando que sea correcto
    if (!(raiz = doc.child("map")))
    {
            cerr << "El documento no es un mapa valido." <<endl;
            exit(1);
    }
    
//    cout << "Nombre: " << raiz.child("tileset").attribute("name").as_string() << endl;
    row = raiz.attribute("height").as_int();
    col = raiz.attribute("width").as_int();
    
    cout << "Dimensiones: " << row << "x" << col << endl;
    
    int count = 0 ;
    xml_node aux;
    for (xml_node tile = raiz.child("layer").child("data").child("tile"); tile; tile = tile.next_sibling("tile"))
    {
        count ++;
        int gid =  tile.attribute("gid").as_int();
        gid -= 1;
        char buff[5];
        itoa(gid,buff,10);
        
//        cout << buff;
        aux = raiz.child("tileset").find_child_by_attribute("tile","id",buff);
        if (aux == NULL){
            int a = 0;
        }
        string car = aux.child("properties").find_child_by_attribute("property","name","tipo").attribute("value").value();
        cout << car;
        if (count % col == 0)
            cout << endl;
    }
    cout << count << endl;
    
    
}

Laberinto *GestorLaberinto::crear(){  
    if (archivo.eof()) return NULL;   
    
    
    
//    string line;
//    
    int row = 0;
    int col = 0;
    
    char linea[500];
    Celda***matrix;
    archivo.getline(linea,500);
    leerXML(linea,matrix,row,col);
    
//    while(!archivo.eof()){
//        matrix[row] = new char[MAX];
//        getline(archivo,line);
//        if (line.length() == 0) break;
//        for (col=0; col<(line.length()); col++){
//            char tipo = line[col];
//            matrix[row][col] = tipo;
//        }
//        row++;
//    }       
    Laberinto *lab = new Laberinto(matrix,row,col);
    return lab;    
    
            
}

#endif	/* GESTORLABERINTO_H */

