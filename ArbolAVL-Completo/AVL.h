typedef ArBB AVL; //NUESTRO AVL ES UN ARBOL DE B�SQUEDA BINARIA

int absoluto(int n){ //�NICAMENTE DA EL VALOR ABSOLUTO DE ALG�N N�MERO ENTERO
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
        SI ES VAC�O ENTONCES ES AVL

        SI EL FACTOR DE BALANCEO ABSOLUTO DE MI ARBOL ES MENOR O IGUAL QUE UNO
         Y TAMBI�N SUS SUBARBOLES IZQUIERDO Y DERECHO SON AVL, ENTONCES MI ARBOL ES AVL

    */
     return (esvacioB(a) || ((absoluto(FactBal(a))<=1)&&
                            (EsAVL(izquierdoB(a)))&&(EsAVL(derechoB(a)))));
}

AVL rotaDer(ArBB a){
    /*
        LA RA�Z AHORA SER� LA RA�Z DE MI IZQUIERDO INICIAL
        EL IZQUIERDO SER� EL IZQUIERDO DE MI IZQUIERDO INICIAL
        LA RA�Z DE MI DERECHO SER� LA QUE ERA MI RA�Z INICIAL
        EL IZQUIERDO DEL DERECHO SER� EL QUE ERA MI DERECHO DEL IZQUIERDO INICIAL
        Y EL DERECHO DEL DERECHO SER� EL QUE ERA MI DERECHO INICIAL
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
//los casos son seg�n mi cuaderno
    if( absoluto(FactBal(a))>1 ){
    //2.1
        if(  EsAVL( izquierdoB(a) ) && EsAVL( derechoB(a) )   ){
        //2.1.1 cuando solo est� desbalanceada la ra�z
            if(FactBal(a)>1){
            //2.1.1.1 Est� cargado hacia la izquierda
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
            //2.1.1.2 Est� cargado hacia la derecha

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
        /*2.1.2 No solo la ra�z est� desbalanceada,
        sino tambi�n su izquierdo o su derecho< */
        //  ! ( EsAVL( izquierdoB(a) ) && EsAVL( derechoB(a) ) )

            if(!EsAVL(izquierdoB(a))){ //es decir, el derecho est� balanceado
            //2.1.2.1 seg�n mi cuaderno,
            //dejo en paz a la ra�z y al derecho y ataco al izquierdo
                 puts("2.1.2.1\n");
                return a=consB( raiz(a) , HazAVL(izquierdoB(a)) , derechoB(a) );
            }else {
            //2.1.2.2  !EsAVL(derechoB(a)) es decir, el izquierdo est� balanceado
            //dejo en paz a la ra�z y al izquierdo y ataco al derecho
                puts("2.1.2.2\n");
                return a=consB( raiz(a) , izquierdoB(a) , HazAVL(derechoB(a)) );
            }


        }

    }else {
    //2.2 abs (factbal(a))<=1
    //Cuando la ra�z tiene factbal adecuado,
    //pero el izquierdo o derecho podr�an estar desbalanceados

        if(!EsAVL(izquierdoB(a))){ //es decir, el derecho s� est� balanceado
        //2.2.1
        //dejo en paz a la ra�z y al derecho y ataco al izquierdo
        puts("2.2.1\n");
                 return a=consB( raiz(a) , HazAVL(izquierdoB(a)) , derechoB(a) );
        }else {
        //2.2.2  !EsAVL(derechoB(a))
        //es decir, el izquierdo est� balanceado
        //dejo en paz a la ra�z y al izquierdo y ataco al derecho
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
        /*si sigue balanceado despu�s de insertarlo,
        then, no hay problema*/
        puts("No se desbalanceo \n");
        return a;
   }else {
       /*
        Si al insertar, perdi� balanceo, entonces busco
        qu� caso sucede de los seis
       */
       puts("Se desbalanceo \n");
       a=HazAVL(a);
       return a;
   }


}

////////////////////////////////////////NUEVA FUNCI�N 03/12/2020
AVL EliminaAVL(Elem e, AVL a){ //SIMPLEMENTE ELIMINO Y LUEGO REBALANCEO
      a=Elimina(e,a);
      if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}







