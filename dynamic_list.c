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
  L->next = malloc (sizeof(tList));
  L->prev = malloc (sizeof(tList));
  L->next = NULL;
  L->prev=NULL;
}

bool isEmptyList (tList L) {
    return L.prev == NULL;
}

tPosL first(tList L) {
  if (isEmptyList(L)== true) {
    return LNULL;
  }
  return 0;
}

tPosL last(tList L) {
    tPosL p=0;
    tList* Q=L.next;

    if (isEmptyList(L)== true) {
        return LNULL;
    }

    while(Q != NULL){
      Q = Q->next;
      p++;
    }
    return p;
}

tPosL previous(tPosL p, tList L) {
  if (p == LNULL||p==first(L)) {
      return LNULL;
  }
  else{
      return p-1;
    }
}

tPosL next(tPosL p, tList L) {
  if (p == LNULL||p>=last(L)) {
    return LNULL;
  }
  else {
      return p+1;
  }
}

void updateitem( tItemL d, tPosL p, tList* L) {
  if (p!=LNULL||p<=last(*L)||p>=first(*L)) {//Condiciones para que se actualice el elemento
    tList* K=L;
    tPosL q;
    for(q=0; q < p; q++,K=K->next );//K apunta a la posición p de la lista
    K->data = d;
  }

}


bool insertItem (tItemL d, tPosL p, tList* L){
  tList* K=L;

  if (p<first(*L)&&p!=LNULL){
    L->prev->prev = malloc (sizeof(tList));
    L->prev->next = malloc (sizeof(tList));
    L->prev->prev = NULL;
    L->prev->data = d;
    L->prev->next = L;
    L = L->prev;//Apunto L hacia la nueva primera posición de la lista
    return true;
  }
  else if (p>=first(*L)){
    tList n;//Creo una nueva casilla
    tPosL q=first(*L);
  	while(q<p){//K apunta a la posición p de la lista
          K = K->next;
          q++;
    }
   	n.next = malloc(sizeof(tItemL));//Adjudico direcciones de memoria para los punteros en la nueva casilla
    n.prev = malloc(sizeof(tItemL));
    n.next = NULL;
    n.prev = NULL;
    n.data = d;//Insertamos el elmento en la nueva casilla
    n.next = K;//Quiero que el siguiente elemento a la nueva casilla sea la posición seleccionada
    n.prev = K->prev;//Quiero que el anterior elemento a la nueva casilla sea la posición anterior a la seleccionada
    K->prev->next = &n;//Apunto el puntero de "siguiente" de la anterior de la posición seleccionada a la nueva casilla
    K->prev = &n;//Apunto el puntero de "anterior" de la  posición seleccionada a la nueva casilla, así queda entre las dos
    return true;
  }
  else if (p == LNULL){
    tList n;//Creo una nueva casilla
    tPosL q;
  	while(K->next!=NULL){K = K->next;}//K apunta al último elemento
   	n.next = malloc(sizeof(tItemL));//Adjudico direcciones de memoria para los punteros en la nueva casilla
    n.prev = malloc(sizeof(tItemL));
    n.next = NULL;
    n.prev = NULL;
    n.data = d;//Insertamos el elmento en la nueva casilla
    n.prev = K;//Quiero que la última posición sea el anterior elemento a la nueva casilla
    K->next = &n;//Apunto el puntero de "siguiente" de la posición seleccionada a la nueva casilla
    return true;
  }
  else return false;


}