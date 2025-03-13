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
  L=NULL;
}

bool isEmptyList (tList L) {
    return L == NULL;
}

tPosL first(tList L) {
  tPosL P;
   P=NULL;
  *P=L;

  return P;
}

tPosL last(tList L) {

    tPosL Q=NULL;
    Q=L.next;

  while(Q != NULL){
      Q = Q->next;
    }
    return Q;
}

tPosL previous(tPosL p, tList L) {
  if (p == NULL||p==first(L)) {
      return NULL;
  }
  else{
    tPosL Q=NULL;
    *Q=L;
    while (Q->next!=p){
      Q=Q->next;
    }
    return Q;
  }
}

tPosL next(tPosL p, tList L) { //Si la posición introducida es la última o nula devuelve LNULL, si no devuelve la siguiente posición
  if (p == NULL) {
    return NULL;
  }
  else {
      return p->next;
  }
}

void updateitem( tItemL d, tPosL p, tList* L) {
  if (p!=NULL) {//Condiciones para que se actualice el elemento
    p->data = d;
  }
}

bool insertItem (tItemL d, tPosL p, tList* L){
  tList* K=L;

 if (p!=NULL){
    if (p==first(*L)){
      tPosL Q;
      Q=NULL;
      Q=malloc(sizeof(tList));
      Q->data=d;
      Q->next=L;
      return true;
    }
    tPosL R, Y;
    R=NULL;
    Y=malloc(sizeof(tList));
    R=previous(p,*L);
    Y->next=p;
    Y->data=d;
    R->next=Y;
    return true;
 }
  else if (p == NULL){
   tPosL T;
   T=NULL;
   T=malloc(sizeof(struct tList));
   T=last(*L);
   T->data=d;
   T->next=NULL;
   return true;
 }
  else return false;
}

void deleteatposition(tPosL p, tList* L){
  tPosL q=NULL;
  q=previous(p,*L);
  q->next=p->next;
  free(p);
}

tItemL getItem (tPosL p, tList L){
  return p->data;
}

tPosL finditem(tConsoleId a, tList L){
  while(L->data.consoleId!=a){
    L=L->next;



}

