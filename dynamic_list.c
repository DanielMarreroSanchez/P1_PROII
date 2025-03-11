/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

/*  Write your code here...  */

void createEmptyList (tList* L){
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

    for(Q; Q->next != NULL; Q = Q->next, p++ );
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
  if (p!=LNULL||p<=last(*L)||p>=first(*L)) {}
    tList* K=L;
    tPosL q;
    for(q=0; q < p; q++,K=K->next );
    K->data = d;

}




bool insertItem (tItemL d, tPosL p, tList* L){

}