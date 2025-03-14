/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: 14 / 03 / 2025
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#define LNULL NULL

/*  Write your code here...  */

typedef struct tNode* tPosL;
typedef struct tNode {
    tItemL data;
    tPosL next;
} tNode;

typedef tPosL tList;

void createEmptyList (tList* L);
bool isEmptyList (tList L);
tPosL first (tList L);
tPosL last (tList L);
tPosL next (tPosL p, tList L);
tPosL previous (tPosL p, tList L);
bool checkPointer(tPosL p, tList L);
bool insertItem (tItemL d, tPosL p, tList* L);
tItemL getItem (tPosL p, tList L);
void updateItem (tItemL d, tPosL p, tList* L);
tPosL findItem (tConsoleId, tList L);
void deleteAtPosition(tPosL p, tList* L);
#endif
