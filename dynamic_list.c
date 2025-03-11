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
    tPosL p;
    tList* Q=L.next;
    for(Q; Q->next != NULL; Q = L.next->next, p++ );
    return p;
}

tPosL previous(tPosL p, tList L) {
    tPosL q;

    if(p==L.pos){
        return LNULL;

    }else {
        return L.prev->pos;
    }
}

tPosL next(tPosL p, tList L) {
  tList Q;
  for(Q=L ; Q.pos != LNULL; Q.next = Q.next->next);
  return Q.next->pos;
}

void updateitem( tItemL d, tPosL p, tList* L) {

    for(p=L.pos; p != LNULL; p = L.next->pos);
    L->data = d;

}




void copyList(tList L, tList * M) {
    tPosL p, q, r;
    bool ret= true;

    createEmptyList(M);
    if (isEmptyList(L)) {
        p=L;
        while((p!=NULL) && createEmptyList(&r) {
            r->data = p->data;
            r->next = NULL;
            if(p==L) {
                *M=r;
                 q=r;

            }else {
                q->next=r;
                q=r;
            }
            p = p->next;
        }
        if(p!=NULL) {
            deleteList(M);
            det=false;
    }
return ret;

    }