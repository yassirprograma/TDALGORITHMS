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


//////////////////////////////////////////////////////////////nueva funci�n 03/12/2020
ArBB Elimina(Elem e, ArBB a){
if(EsIgual(e,raiz(a))) //si el que quiero eleminar es la raiz
   if(EsHoja(a))  //caso 1: si la ra�z no tiene hijos entonces , eliminar la ra�z nos deja sin nada
     return vacioB();
   else if(esvacioB(derechoB(a))) //  caso 2: si no tengo nada en el derecho,
         return izquierdoB(a);      //al elminar la ra�z, el arbol ahora solo ser� el izquierdo

        else if(esvacioB(izquierdoB(a)))  //Caso 3: Si no tengo nada en el izquierdo,
               return derechoB(a);         //al eliminar la ra�z, el arbol ahora solo ser� el derecho
             else
             /* caso 4 cundo tengo ambos hijoz, para que se conserve el orden del arbol de b�squeda debo subir como ra�z
                al nodo hoja m�s a la derecha del subarbol izquierdo, pues ese nodo hoja era el inmediato menor
                de la ra�z que elimin�.
                Pero el hecho de subir esa hoja como nueva ra�z, implica que elimine esa hoja se su antiguo lugar, por eso mando
                a eliminar ese elemento del subarbol izquierdo en donde estaba.
            */
               return consB(ElemMasDerechoB(  izquierdoB(a)) ,   Elimina(  ElemMasDerechoB(izquierdoB(a)) , izquierdoB(a)  )  ,  derechoB(a)  );
else if(EsMenor(e,raiz(a)))
        /*esto simplemente le indica que si el elemento a eliminar es menor que la ra�z, debe seguir
            el camino izquierdp.
            (siguiendo el principio que entre m�s a la izquierda est� un elemento en un arbol, menor es).
        */
       return consB(raiz(a), Elimina(e,izquierdoB(a)),  derechoB(a));
     else
     /*esto simplemente le indica que si el elemento a eliminar es mayor que la ra�z, debe seguir
            el camino derecho.
            (siguiendo el principio que entre m�s a la derecha est� un elemento en un arbol, mayor es).
        */

       return consB(raiz(a),izquierdoB(a),Elimina(e,derechoB(a)));
}
//////////////////////////////////////////////////////////////

