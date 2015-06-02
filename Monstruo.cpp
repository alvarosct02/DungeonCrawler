#include <cstdio>
#include <cstdio>
#include "Monstruo.h"
#include "Entidad.h"

//#include <string>
//using namespace std;

Monstruo::Monstruo(void){
    nombre = "NoName";
    posX = 0;
    posY = 0;
    maxVida = 100;
    nivel = 1;
}
Monstruo::Monstruo(string name ,int x,int y,int health,int lvl){
    nombre = name;
    posX = x;
    posY = y;
    maxVida = health;
    nivel = lvl;
}
