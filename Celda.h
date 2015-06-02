/* 
 * File:   Celda.h
 * Author: AlvaroPC
 *
 * Created on June 2, 2015, 12:17 AM
 */

#ifndef CELDA_H
#define	CELDA_H

class Celda{
private:
    int tipo;
public:
    Celda(void);
    Celda(int);
    void SetTipo(int tipo);
    int GetTipo() const;
};

#endif	/* CELDA_H */

