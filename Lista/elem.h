#ifndef ELEM_H_INCLUDED
#define ELEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef int Elem; //nuestros elementos seran enteros
/*
void ImpElem(Elem);
void EsMenor(Elem,Elem);
*/

/*
typedef int Elem; //nuestros elementos seran enteros
*/


///////////// prototipo de funciones
//void ImpElem(Elem);
//void EsMenor(Elem,Elem);
////////////////////

void ImpElem (Elem e){  //solo imprime algun elemento
    printf("%d\n",e);
}

int EsMenor(Elem e1,Elem e2){
    return e1<e2;
}


#endif // ELEM_H_INCLUDED
