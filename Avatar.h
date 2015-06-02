/* 
 * File:   Avatar.h
 * Author: AlvaroPC
 *
 * Created on June 1, 2015, 10:13 PM
 */

#ifndef AVATAR_H
#define	AVATAR_H

#include "Entidad.h"

class Avatar: public Entidad{
    
    public:
        Avatar(void);
        Avatar(string,int,int,int);
};

#endif	/* AVATAR_H */

