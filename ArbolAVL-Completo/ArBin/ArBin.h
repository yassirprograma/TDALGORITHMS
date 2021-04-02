typedef struct Nodo{
      Elem r;
      struct Nodo *i;
      struct Nodo *d;
} *ArBin;

ArBin vacioB(){return NULL;}

ArBin consB(Elem r, ArBin i, ArBin d){
     ArBin temp =(ArBin)malloc(sizeof(struct Nodo));
     temp->r=r;
     temp->i=i;
     temp->d=d;
     return temp;
}

int esvacioB(ArBin a){return a==NULL;}

Elem raiz(ArBin a){return a->r;}

ArBin izquierdoB(ArBin a){return a->i;}

ArBin derechoB(ArBin a){return a->d;}

int NumElemsB(ArBin a){
    if(esvacioB(a))
        return 0;
    else
        return 1+NumElemsB(izquierdoB(a))+NumElemsB(derechoB(a));
};

void PreOrder(ArBin a){
   if(!esvacioB(a)){
        ImpElem(raiz(a));
        PreOrder(izquierdoB(a));
        PreOrder(derechoB(a));
   }
};

void fInOrder(FILE *salida, ArBin a){
   if(!esvacioB(a)){
        fInOrder(salida,izquierdoB(a));
        fImpElem(salida,raiz(a));
        fInOrder(salida,derechoB(a));
   }
};

void InOrder(ArBin a){
   if(!esvacioB(a)){
        InOrder(izquierdoB(a));
        ImpElem(raiz(a));
        InOrder(derechoB(a));
   }
};

void PostOrder(ArBin a){
   if(!esvacioB(a)){
        PostOrder(izquierdoB(a));
        PostOrder(derechoB(a));
        ImpElem(raiz(a));
   }
};

int mayor(int n1, int n2){
    if(n1>=n2)
        return n1;
    else
        return n2;
    }

int altura(ArBin a){
    if(esvacioB(a))
         return 0;
    else
         return 1+mayor(altura(izquierdoB(a)),altura(derechoB(a)));
}

////////////nuevas 04/12

int EsHoja(ArBin a){ return ((esvacioB(izquierdoB(a)))&&(esvacioB(derechoB(a)))); }  //no tiene izquierdo ni derecho

int EsInterno(ArBin a){ return !EsHoja(a);} //si no es hoja entonces es interno

Elem ElemMasDerechoB(ArBin a){  //retorna el nodo más a la derecha de algún arbol o subarbol
     if(EsHoja(a)||esvacioB(derechoB(a)))  //cuando el nodo es hoja o no tiene camino hacia la derecha, regreso ese nodo
          return raiz(a);
     else
          return ElemMasDerechoB(derechoB(a)); //cuando tiene derecho, seguimos su camino hacia la derecha recursivamente
}

Elem ElemMasIzquierdoB(ArBin a){  //retorna el nodo más a la izquierda de algún arbol o subarbol
     if(EsHoja(a)||esvacioB(izquierdoB(a))) //cuando el nodo es hoja o no tiene camino hacia la izquierda, regreso ese nodo
          return raiz(a);
    else
          return ElemMasIzquierdoB(izquierdoB(a)); //cuando tiene derecho, seguimos ese camino hacia la derecha recursivamente
}

void ImpNivelAB(ArBin a, int nivel){
    if (esvacioB(a))
        return; //cuando mi arbin es vacio, no debo hacer nada, este es un base case
    if (nivel == 1)
        ImpElem(raiz(a));  //cuando mi nivel es 1, simplemente imprimo la raiz, //este es un base case
    else if (nivel > 1){
        ImpNivelAB(izquierdoB(a), nivel-1); //me voy a imprimir el subarbol izquierdo, reduciendo en 1 el nivel
        ImpNivelAB(derechoB(a), nivel-1); //me voy a imprimir el subarbol
    }

    //por cada nivel que quiera imprimir, empiezo de nuevo desde la raíz, hasta llegar recursivamente a los nodos del nivel que quiero
    //  (hasta llegar al base case)

}
void ImpNivelPorNivelAB(ArBin a){
    int h = altura(a),i; //debemos conocer la altura

    for (i=1; i<=h; i++){
        ImpNivelAB(a, i);  //por cada nivel mando a llamar a la función imprime nivel
        printf("\n");
    }
}

//////////////////////////////////////////////////////////////
/*
Espec ArBin
   vacioB: -> ArBin;
   consB: Elem, ArBin, ArBin -> ArBin;
   esvacioB: ArBin -> Bool;
   raiz: ArBin -> Elem;
   izquierdoB: ArBin -> ArBin;
   derechoB: ArBin -> ArBin;
  Axioma: Elem r, ArBin i, d;
     [ab1] esvacioB(vacioB())= Verdadero;
     [ab2] esvacioB(consB(r,i,d))= Falso;
     [ab3] raiz(vacioB()) = Error;
     [ab4] raiz(consB(r,i,d)) = r;
     [ab5] izquierdoB(vacioB()) = Error;
     [ab6] izquierdoB(consB(r,i,d)) = i;
     [ab7] derechoB(vacioB()) = Error;
     [ab8] derechoB(consB(r,i,d)) = d;
   Fin ArBin.
 */
