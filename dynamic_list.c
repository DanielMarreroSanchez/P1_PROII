/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: **********
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: **********
 * GROUP: 1.2
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

/*  Write your code here...  */

void createEmptyList (tList* L){
  L=LNULL;
}

bool isEmptyList (tList L) {
    return L == LNULL;
}

tPosL first(tList L) {
  tPosL P;
   P=LNULL;
  P=L;

  return P;
}

tPosL last(tList L) {

    tPosL Q=LNULL;
    Q=L->next;

  while(Q != LNULL){
      Q = Q->next;
    }
    return Q;
}

tPosL previous(tPosL p, tList L) {
  if (p == LNULL||p==first(L)) {
      return LNULL;
  }
  else{
    tPosL Q=LNULL;
    Q=L;
    while (Q->next!=p){
      Q=Q->next;
    }
    return Q;
  }
}

tPosL next(tPosL p, tList L) { //Si la posición introducida es la última o nula devuelve LNULL, si no devuelve la siguiente posición
  if (p == LNULL) {
    return LNULL;
  }
  else {
      return p->next;
  }
}

void updateitem( tItemL d, tPosL p, tList* L) {
  if (p!=LNULL) {//Condiciones para que se actualice el elemento
    p->data = d;
  }
}

bool insertItem (tItemL d, tPosL p, tList* L){
  tList* K=L;

 if (p!=LNULL){
    if (p==first(*L)){
      tPosL Q;
      Q=LNULL;
      Q=malloc(sizeof(tList));
      Q->data=d;
      Q->next=*L;
      return true;
    }
    tPosL R, Y;
    R=LNULL;
    Y=malloc(sizeof(tList));
    R=previous(p,*L);
    Y->next=p;
    Y->data=d;
    R->next=Y;
    return true;
 }
  else if (p == LNULL){
   tPosL T;
   T=LNULL;
   T=malloc(sizeof(struct tNode));
   T=last(*L);
   T->data=d;
   T->next=LNULL;
   return true;
 }
  else return false;
}

void deleteAtPosition(tPosL p, tList* L){
  tPosL q=LNULL;
  q=previous(p,*L);
  q->next=p->next;
  free(p);
}

tItemL getItem (tPosL p, tList L){
  return p->data;
}

tPosL finditem(tConsoleId a, tList L){
  tList Q=L;
  while(Q->data.consoleId!=a){
    Q=Q->next;
  }
  return Q;
}

