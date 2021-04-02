// Incluir en el main a "ArBin.h"

typedef ArBin ArBB;

ArBB InsOrdB(Elem e, ArBB a){
   if(esvacioB(a))
       return consB(e,vacioB(),vacioB());
   else if(EsMenor(e,raiz(a)))
            return consB(raiz(a),InsOrdB(e,izquierdoB(a)),derechoB(a));
        else
            return consB(raiz(a),izquierdoB(a),InsOrdB(e,derechoB(a)));
}

// EstaEn(e,a)==Cierto


//////////////////////////////////////////////////////////////nueva función 03/12/2020
ArBB Elimina(Elem e, ArBB a){
if(EsIgual(e,raiz(a))) //si el que quiero eleminar es la raiz
   if(EsHoja(a))  //caso 1: si la raíz no tiene hijos entonces , eliminar la raíz nos deja sin nada
     return vacioB();
   else if(esvacioB(derechoB(a))) //  caso 2: si no tengo nada en el derecho,
         return izquierdoB(a);      //al elminar la raíz, el arbol ahora solo será el izquierdo

        else if(esvacioB(izquierdoB(a)))  //Caso 3: Si no tengo nada en el izquierdo,
               return derechoB(a);         //al eliminar la raíz, el arbol ahora solo será el derecho
             else
             /* caso 4 cundo tengo ambos hijoz, para que se conserve el orden del arbol de búsqueda debo subir como raíz
                al nodo hoja más a la derecha del subarbol izquierdo, pues ese nodo hoja era el inmediato menor
                de la raíz que eliminé.
                Pero el hecho de subir esa hoja como nueva raíz, implica que elimine esa hoja se su antiguo lugar, por eso mando
                a eliminar ese elemento del subarbol izquierdo en donde estaba.
            */
               return consB(ElemMasDerechoB(  izquierdoB(a)) ,   Elimina(  ElemMasDerechoB(izquierdoB(a)) , izquierdoB(a)  )  ,  derechoB(a)  );
else if(EsMenor(e,raiz(a)))
        /*esto simplemente le indica que si el elemento a eliminar es menor que la raíz, debe seguir
            el camino izquierdp.
            (siguiendo el principio que entre más a la izquierda esté un elemento en un arbol, menor es).
        */
       return consB(raiz(a), Elimina(e,izquierdoB(a)),  derechoB(a));
     else
     /*esto simplemente le indica que si el elemento a eliminar es mayor que la raíz, debe seguir
            el camino derecho.
            (siguiendo el principio que entre más a la derecha esté un elemento en un arbol, mayor es).
        */

       return consB(raiz(a),izquierdoB(a),Elimina(e,derechoB(a)));
}
//////////////////////////////////////////////////////////////

