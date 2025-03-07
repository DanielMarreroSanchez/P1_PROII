/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Iago Bescansa Alcoba LOGIN 1: iago.alcoba
 * AUTHOR 2: Daniel Marrero Sánchez LOGIN 2: daniel.marrero.sanchez
 * GROUP: 1.2
 * DATE:  / ** / **
 */

#include "static_list.h"
#include <string.h>
#include "stdlib.h"

/*  Write your code here...  */

void createEmptyList (tList* L){//Creamos lista con el último lugar ocupado fuera de la lista
  L->lastPos=LNULL;
}

bool isEmptyList(tList L){//Comprueba si la lista está vacía
  return L.lastPos==LNULL;
}

tPosL first (tList L){//Si la lista no está vacía devuelve la primera posición, si no devuelve nulo
  if (isEmptyList(L)==true) {
    return LNULL;
  }
  return 0;
}

tPosL last (tList L) {//Devuelve la posición del último elemento de la lista, puede ser nulo si está vacía
  return L.lastPos;
}

tPosL next (tPosL p, tList L) {//Devuelve la siguiente posición si existe, si no devuelve nulo
  if(p>=L.lastPos) {
    return LNULL;
  }
  else {
    return p+1;
  }
}

tPosL previous (tPosL p, tList L) {//Devuelve la anterior posición si existe, si no devuelve nulo
  if (p==0) {
    return LNULL;
  }
  else {
    return p-1;
  }
}

bool insertItem (tItemL d, tPosL p, tList* L) {//Inserta un elemento en la posición indicada, sin eliminar a ningún otro y sin dejar espacios con el resto de elementos de la lista
  tPosL q;
  if(L->lastPos==MAX_ARRAY-1) {//Si la lista está llena no deja insertar más
    return false;//No se insertó correctamente
  }
  else {
    L->lastPos++;
    if (p>=L->lastPos) {
      L->data[L->lastPos]=d;
      return true;//Se insertó correctamente
    }
    else {
      for(q=L->lastPos;q>=p;q--) { //q>p para que la última q sea L.data[p]
        L->data[q]=L->data[q-1];
      }
      L->data[p]=d;
      return true;//Se insertó correctamente
    }
  }
}

void deleteAtPosition (tPosL p, tList* L){//Elimina de la lista el elmento en la posición introducida sin dejar espacios
  for (tPosL q = p;q<=L->lastPos;q++) {
    L->data[q]=L->data[q+1];//Copio la celda siguiente en la actual hasta llegar a la última posición, que copia el valor nulo
  }
  L->lastPos--;

}

tItemL getItem (tPosL p, tList L) {//Devuelve el elmento en la posición indicada
  return L.data[p];
}

void updateItem (tItemL d, tPosL p, tList* L) {//Si p es una posición válida, actualiza el valor en la posición p
    L->data[p]=d;
}


tPosL findItem (tConsoleId d, tList L) {//Escanea el array para encontrar el primer elemento igual al introducido
  for (int i = 0; i <= L.lastPos; i++) {//Scaneo el array y cuando el Id sea igual al preguntado devuelvo la posición. Si no se encuentra devuelve LNULL
    if (strcmp(L.data[i].consoleId, d) == 0) {
      return i;
    }
  }
  return LNULL;
}