/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#include <stdbool.h>
#include "types.h"
#define LNULL -1
#define MAX_ARRAY 25
/*  Write your code here...  */
typedef int tPosL;

typedef struct {
  tItemL data[MAX_ARRAY];
  tPosL lastPos;
} tList;

void createEmptyList (tList* L);
bool isEmptyList (tList L);
tPosL first (tList L);
tPosL last (tList L);
tPosL next (tPosL p, tList L);
tPosL previous (tPosL p, tList L);
bool insertItem (tItemL d, tPosL p, tList* L);
void deleteAtPosition (tPosL p, tList* L);
tItemL getItem (tPosL p, tList L);
void updateItem (tItemL d, tPosL p, tList* L);
tPosL findItem (tConsoleId, tList L);


#endif
