#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "elem.h"

typedef struct Nodo {
    Elem dato;
    struct Nodo *sig; //un apuntador
} *Lista; //Lista es un apuntador que  apunta a nodos que apuntan a otros nodos

///////////////////////////////

/*
Lista cons(Elem,Lista);
Lista vacia(void);
Lista esvacia(Lista);
Elem cabeza(Lista);
Lista resto(Lista);
void ImpElems(Lista);
int NumElems(Lista);
Lista PegaListas(Lista, Lista );
Lista InvierteLista(Lista );
*/
///////////////////////////////

Lista cons (Elem e, Lista l){ //funciones tipo lista, esta es general y hace toda la chamba de los apuntadores
    Lista t=(Lista) malloc(sizeof(struct Nodo));
    //size of dice cuanta memoria ocupa un nodo
    //malloc reserva espacio que le dice sizeof
    //(Lista) es un CAST que apunta al eepacio reservado por malloc

    t->dato=e; /*
    t.dato apunta a la dirección de 'e'
    Guarda en el
    campo 'dato' el nodo al que apunta 't'
    el contenido de la variable 'e'
    */
    t->sig=l; //t.sig apunta a la direccion de l (l es lista)

    //dato y sig son campos de mi variable t

    return t;

}




Lista vacia() {
    return NULL; //Regreso una lista que apunta a NULL
}

int esvacia(Lista l){
    return l==NULL;  //truco para evitar poner el if

}

Elem cabeza(Lista l){  //regreso un elem
    return l->dato;
}

Lista resto(Lista l){  //regreso una lista
    return l->sig;
}

void ImpElems(Lista l){
    if(!esvacia(l)){ //Solo imprime
        ImpElem(cabeza(l)); //esta viene de elem.h
        ImpElems(resto(l)); //la llamo recursivamente
    }

}
int NumElems(Lista l){
    if(esvacia(l)){
        return 0;
    }else {
        return 1+NumElems(resto(l)); //llamo recursivamente para obtener el numero de elementos del resto
    }

}
Lista PegaListas(Lista l1, Lista l2){
    if(esvacia(l1)){
        return l2; //caso trivial o base
    }else {
        return cons( cabeza(l1) , PegaListas(resto(l1),l2) ); //pegamos recursivamente
    }
}

Lista InvierteLista(Lista l){
    if(esvacia(l)){
        return l; //caso trivial o base, como es vacia, no hay nada que invertir
    }else{
        return PegaListas(   InvierteLista ( resto(l) ) , cons( cabeza(l),vacia() )     ); //como cabeza(l) no es una lista, hay que volverla lista
        //la cabeza de l la vuelve lista y la pega en la parte de atras del resto de l, esto lo hace recursivamente
    }
}

Lista InsOrd(Elem e, Lista s){
    if(esvacia(s)){
        return cons(e,s); //caso trivial o base, como s es vacia, está ordenada
    }else {

        if( EsMenor( e , cabeza (s) )  ){ //s tiene la invariante de estar ordenada al entrar aqui
            return cons(e,s); //solo pego a e
        }else{
            //e debe ver en que lugar de s puede encajar de acuerdo a su valor
            return cons( cabeza(s) , InsOrd(e,resto(s)) );
        }
    }
}

Lista OrdListaAsc(Lista s){
    if(esvacia(s)){
        return s; //caso trivial, no hay nada que ordenar
    }else {
        return InsOrd( cabeza(s) ,  OrdListaAsc( resto(s) )  ); //inserto cabeza en el resto que debe estar ordenado, recursividad
    }
}




#endif // LISTA_H_INCLUDED
