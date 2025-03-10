//
// Created by DMS on 19/02/2025.
//

#include "listas_punteros.h"

#include "listas_array.h"



tPosL first(tList L) {
    return L;
}

tPosL last(tList L) {
    tPosL p;
    for(p=L; p -> next != LNULL; p = p -> next);
    return p;
}

tPosL previous(tPosL p, tList L) {
    tPosL q;

    if(p==L){
        return LNULL;

    }else {
        for(q=L, q -> next != p; q = q -> next);
        return q;
    }
}

tPosL next(tPosL p, tList L) {
    return p -> next;
}

void updateitem( tItemL d, tPosL p, tList* L) {
    p->data = d;

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