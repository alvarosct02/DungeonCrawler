#include <cstdio>
#include <cstdio>
#include "Avatar.h"
//#include <string>
//using namespace std;

Avatar::Avatar(void){
    nombre = "Guanira";
    posX = 0;
    posY = 0;
    maxVida = 100;
}
Avatar::Avatar(string name,int y,int x,int health){
    nombre = name;
    posX = x;
    posY = y;
    maxVida = health;
}