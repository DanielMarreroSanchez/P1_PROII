//
// Created by DMS on 19/02/2025.
//
#ifndef LISTAS_PUNTEROS_H
#define LISTAS_PUNTEROS_H
#include "listas_array.h"

#endif //LISTAS_PUNTEROS_H

#define MAX 100;
#define LNULL -1;


typedef int titemL;
typedef int tPosL;

typedef struct {
    titemL data[MAX];
    tPosL lastPos;
}tList;




tPosL first(tList L);

tPosL last(tList L);

tPosL next(tPosL p);

tPosL previous(tPosL p);

void updateitem(tItemL d, tPosL p, tList* L);

void copyList(tList L, tList* M);

tPosL finditem(tItemL d, tList L);