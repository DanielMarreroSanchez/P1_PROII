/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE: ** / ** / **
 */

#include "static_list.h"

/*  Write your code here...  */

void createEmptyList (tList L){
  L.lastPos=LNULL;
}

bool isEmptyList(tList L){
  return L.lastPos==LNULL;
}

tPosL first (tList L){
  return 0;
}

tPosL last (tList L) {
  return L.lastPos;
}

tPosL next (tPosL p, tList L) {
  if(p==L.lastPos) {
    return LNULL;
  }
  else {
    return p+1;
  }
}

tPosL previous (tPosL p, tList L) {
  if (p==0) {
    return LNULL;
  }
  else {
    return p-1;
  }
}

bool insertItem (tItemL d, tPosL p, tList L) {
  tPosL q;
  if(L.lastPos==MAX_ARRAY-1) {//Si la lista está llena no deja insertar más
    return false;
  }
  else {
    L.lastPos++;
    if (L.data[p].pos==LNULL) {
      L.data[L.lastPos]=d;
    }
    else {
      for(q=L.lastPos;q>=p;q--) { //q>p para que la última q sea L.data[p]
        L.data[q]=L.data[q-1];
      }
      L.data[p]=d;
    }
  }
}

void deleteAtPosition (tPosL p, tList L){
  for (tPosL q = p;q<=L.lastPos;p++) {
    L.data[q]=L.data[q+1];//Copio la celda siguiente en la actual hasta llegar a la última posición, que copia el valor nulo
  }
  L.lastPos--;

}

tItemL getItem (tPosL p, tList L) {
  return L.data[p];
}

void updateItem (tItemL d, tPosL p, tList L) {
  if(L.data[p].pos!=LNULL) {
    L.data[p]=d;
  }
}

tPosL findItem (tConsoleId Id, tList L) {
  tPosL p;
  if (L.lastPos==LNULL) {
    return LNULL;
  }
  for(int i=0;i>L.lastPos;i++) {//Scaneo el array y cuando el Id sea igual al preguntado devuelvo la posición. Si no se encuentra devuelve LNULL
    if(L.data[i].consoleId==Id) {
      p=i;
      break;
    }
  }
  if (p<0||p>MAX_ARRAY) {
    return LNULL;
  }
  else {
    return p;
  }
}