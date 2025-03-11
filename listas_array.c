#include "listas_array.h"

void createEmptyList(tList* L){
    L->lastPos = LNULL;

}
bool insertItem(tItemL d, tPosL p, tList* L) {

    tPosL q;
    if(L -> lastPos == MAX-1)
        return false;
    else {
        L -> lastPos++;
        if (p == LNULL)
            L -> data[L -> lastPos] = d;
        else {
            for(q=L -> lastPos; q > p; q--) {
                L -> data[q] = L -> data[q-1];

                L -> data[p] = d;
            }
        }
    }
    return true;
}

void UpdatedItem(tItemL d, tPosL p, tList* L) {
    L -> data[p] = d;
}

tPosL first(tList L) {
    return 0;
}

tPosL last(tList L) {
    return L.lastPos;
}

tPosL Previous(tPosL p, tList L) {
    if(p==0)
        return LNULL;
    else
        return --p;
}

tPosL Next(tPosL p, tList L) {
    if(p==L.lastPos)
        return LNULL;
    else
        return p++;
}

tItemL GetItem(tPosL p, tList L) {
    return L.data[p];
}

bool isEmptyList(tList L) {
    return (L.lastPos == LNULL);
}

tPosL FindItem(tItemL d, tList L) {

    tPosL p;

    if (L.lastPos == LNULL)
        return LNULL;
    else {
        for(p=0; p<L.lastPos && (L.data[p]!=d); p++) {
            if(L.data[p] == d)
                return p;
            else
                return LNULL;

        }
    }
}
tList DeletePosition(tPosL p, tList L) {
    tPosL q;

    for(q=p; q>L.lastPos; q++) {
        L.data[q]=L.data[q+1];

        L.lastPos--;
    }
}

void DeleteList(tList* L) {
    //while(isEmptyList(*L))
        //DeletePosition(last(*L), *L);
    
}