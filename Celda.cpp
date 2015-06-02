#include "Celda.h"

Celda::Celda(){
    
}
Celda::Celda(int t) {
    tipo = t;
}

void Celda::SetTipo(int tipo) {
    this->tipo = tipo;
}

int Celda::GetTipo() const {
    return tipo;
}
