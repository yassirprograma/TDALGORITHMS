typedef ArBB AVL; //NUESTRO AVL ES UN ARBOL DE BÚSQUEDA BINARIA

int absoluto(int n){ //ÚNICAMENTE DA EL VALOR ABSOLUTO DE ALGÚN NÚMERO ENTERO
    if(n>=0)
        return n;
    else
        return -n;
}

int FactBal(ArBB a){ /*EL FACTOR DE BALANCEO PARA UN ARBOL O SUBARBOL ,
    DEVUELVE LA RESTA DE LA ALTURA DE SU IZQUIERDO MENOS SU DERECHO*/
    return altura(izquierdoB(a))-altura(derechoB(a));
}

int EsAVL(ArBB a){ /*
        SI ES VACÍO ENTONCES ES AVL

        SI EL FACTOR DE BALANCEO ABSOLUTO DE MI ARBOL ES MENOR O IGUAL QUE UNO
         Y TAMBIÉN SUS SUBARBOLES IZQUIERDO Y DERECHO SON AVL, ENTONCES MI ARBOL ES AVL

    */
     return (esvacioB(a) || ((absoluto(FactBal(a))<=1)&&
                            (EsAVL(izquierdoB(a)))&&(EsAVL(derechoB(a)))));
}

AVL rotaDer(ArBB a){
    /*
        LA RAÍZ AHORA SERÁ LA RAÍZ DE MI IZQUIERDO INICIAL
        EL IZQUIERDO SERÁ EL IZQUIERDO DE MI IZQUIERDO INICIAL
        LA RAÍZ DE MI DERECHO SERÁ LA QUE ERA MI RAÍZ INICIAL
        EL IZQUIERDO DEL DERECHO SERÁ EL QUE ERA MI DERECHO DEL IZQUIERDO INICIAL
        Y EL DERECHO DEL DERECHO SERÁ EL QUE ERA MI DERECHO INICIAL
    */
    return consB(raiz(izquierdoB(a)),
           izquierdoB(izquierdoB(a)),
           consB(raiz(a),derechoB(izquierdoB(a)),derechoB(a)));
}

AVL rotaIzq(ArBB a){
    /*
        ES EL ESPEJO DE rotaDer
    */
    return  consB(raiz(derechoB(a)),
           consB(raiz(a),izquierdoB(a),izquierdoB(derechoB(a))),
           derechoB(derechoB(a)));
}

AVL rotaDerIzq(ArBB a){
/*
    TOMA UN ARBOL O SUB-ARBOL Y GIRA SU IZQUIERDO   HACIA LA IZQUIERDA Y LUEGO GIRA EL ARBOL O SUBARBOL COMPLETO HACIA LA DERECHA
*/
    return rotaDer(  consB(  raiz(a)  ,  rotaIzq( izquierdoB(a) ) ,  derechoB(a)   )   );

}

AVL rotaIzqDer(ArBB a){
/*
    TOMA UN ARBOL O SUB-ARBOL Y GIRA SU DERECHO  HACIA LA DERECHA Y LUEGO GIRA EL ARBOL O SUBARBOL COMPLETO HACIA LA IZQUIERDA
*/

    return rotaIzq(    consB(   raiz(a)  ,  izquierdoB(a)  ,  rotaDer( derechoB(a) )    )     );
}

AVL HazAVL (AVL a){
puts("SE HA LLAMADO A HazAVL");
//los casos son según mi cuaderno
    if( absoluto(FactBal(a))>1 ){
    //2.1
        if(  EsAVL( izquierdoB(a) ) && EsAVL( derechoB(a) )   ){
        //2.1.1 cuando solo está desbalanceada la raíz
            if(FactBal(a)>1){
            //2.1.1.1 Está cargado hacia la izquierda
                if( FactBal( izquierdoB(a) ) >0 ){
                //2.1.1.1.1
                    puts("2.1.1.1.1\n");
                    return a=rotaDer(a);
                }else {
                //2.1.1.1.2
                //FactBal( izquierdoB((a)) ) <0
                    puts("2.1.1.1.2\n");
                    return a=rotaDerIzq(a);
                }

            }else {
            //FactBal(a)<=1
            //2.1.1.2 Está cargado hacia la derecha

                if( FactBal( derechoB(a)) <0 ){
                    //2.1.1.2.1
                    puts("2.1.1.2.1\n");
                    return a=rotaIzq(a);
                }else {
                ////2.1.1.2.2
                //FactBal( derechoB((a)) ) >0
                    puts("2.1.1.2.2\n");
                    return a=rotaIzqDer(a);
                }
            }

        }else {
        /*2.1.2 No solo la raíz está desbalanceada,
        sino también su izquierdo o su derecho< */
        //  ! ( EsAVL( izquierdoB(a) ) && EsAVL( derechoB(a) ) )

            if(!EsAVL(izquierdoB(a))){ //es decir, el derecho está balanceado
            //2.1.2.1 según mi cuaderno,
            //dejo en paz a la raíz y al derecho y ataco al izquierdo
                 puts("2.1.2.1\n");
                return a=consB( raiz(a) , HazAVL(izquierdoB(a)) , derechoB(a) );
            }else {
            //2.1.2.2  !EsAVL(derechoB(a)) es decir, el izquierdo está balanceado
            //dejo en paz a la raíz y al izquierdo y ataco al derecho
                puts("2.1.2.2\n");
                return a=consB( raiz(a) , izquierdoB(a) , HazAVL(derechoB(a)) );
            }


        }

    }else {
    //2.2 abs (factbal(a))<=1
    //Cuando la raíz tiene factbal adecuado,
    //pero el izquierdo o derecho podrían estar desbalanceados

        if(!EsAVL(izquierdoB(a))){ //es decir, el derecho sí está balanceado
        //2.2.1
        //dejo en paz a la raíz y al derecho y ataco al izquierdo
        puts("2.2.1\n");
                 return a=consB( raiz(a) , HazAVL(izquierdoB(a)) , derechoB(a) );
        }else {
        //2.2.2  !EsAVL(derechoB(a))
        //es decir, el izquierdo está balanceado
        //dejo en paz a la raíz y al izquierdo y ataco al derecho
        puts("2.2.2\n");
             return a=consB( raiz(a) , izquierdoB(a) , HazAVL(derechoB(a)) );
        }


    }
}


AVL InsAVL(Elem e, AVL a){
  /* Va a insertar el elemento e en el AVL a (InsOrd(e,a)), y
   preserva la cualidad de AVL en el arbol resultado
   */
   a=InsOrdB(e,a); //insertamos un elemento

   if(EsAVL(a)){
        /*si sigue balanceado después de insertarlo,
        then, no hay problema*/
        puts("No se desbalanceo \n");
        return a;
   }else {
       /*
        Si al insertar, perdió balanceo, entonces busco
        qué caso sucede de los seis
       */
       puts("Se desbalanceo \n");
       a=HazAVL(a);
       return a;
   }


}

////////////////////////////////////////NUEVA FUNCIÓN 03/12/2020
AVL EliminaAVL(Elem e, AVL a){ //SIMPLEMENTE ELIMINO Y LUEGO REBALANCEO
      a=Elimina(e,a);
      if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}







