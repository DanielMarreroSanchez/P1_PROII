/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <stdbool.h>
#include <stdlib.h>
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
