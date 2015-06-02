
#include "Laberinto.h"

Laberinto::Laberinto() {
    isNull = true;
    
}

void Laberinto::setSize(int m,int n) {
    isNull = false;
    M = m;
    N = n;
}


