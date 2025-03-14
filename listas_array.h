#ifndef LISTAS_ARRAY_H
#define LISTAS_ARRAY_H
#include <stdbool.h>
                                    /* DEFINICIONES DEL TIPO */

#define MAX 100
#define LNULL -1

typedef int tItemL;
typedef int tPosL;
typedef struct {

    tItemL data[MAX];
    tPosL lastPos;

} tList;

                                    /* PROTOTIPOS DE OPERACIONES */

void createEmptyList(tList* L);
bool insertItem(tItemL d, tPosL p, tList* L);
void UpdatedItem(tItemL d, tPosL p, tList* L);
tPosL first(tList L);
tPosL last(tList L);
tPosL Previous(tPosL p, tList L);
tPosL Next(tPosL p, tList L);
tItemL GetItem(tPosL p, tList L);
bool isEmptyList(tList L);
tPosL FindItem(tItemL d, tList L);
tList DeletePosition(tPosL p, tList L);
void DeleteList(tList* L);
#endif //LISTAS_ARRAY_H