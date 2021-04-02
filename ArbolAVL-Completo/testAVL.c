#include<stdio.h>
#include<stdlib.h>
#include"Elem\Elem.h" //TRABAJAMOS CON ELEMENTOS ENTEROS, FUNCIONES DE COMPARACIÓN, E IMPRESIÓN
#include"ArBin\ArBin.h" //ARBOL BINARIO
#include"ArBB\ArBB.h" //ARBOL DE BÚSQUEDA BINARIA
#include"AVL.h" //FUNCIONES AVL

int main(){

    AVL a=vacioB(); //declaramos un avl vacío
    int i=1,n;

    while(i){ //insertamos elementos mientras querramos
        scanf("%d",&n);
        a=InsOrdB(n,a);
        printf("1 para continuar, 0 para salir.");
        scanf("%d",&i);
    }

    /*LA INTENCIÓN DE ESTA PRUEBA ES GENERAR UN ARBOL AL QUE SE LE PUEDA HACER UNA DOBLE ROTACIÓN
    TOMAR UN ARBOL O SUB-ARBOL Y GIRA SU DERECHO  HACIA LA DERECHA Y LUEGO GIRA EL ARBOL O SUBARBOL COMPLETO HACIA LA IZQUIERDA
    */
    // CASO PARA LOGRARLO: 100, 50, 200, 25,75,150,300,125,175,400,110
    // copy and paste 100 1 50 1 200 1 25 1 75 1 150 1 300 1 125 1 175 1 400 1 110 0

    puts("\n");
    printf("FactBal RAIZ = %d.\n",FactBal(a)); //imprimimos el arbol desbalan
    printf("FactBal DEL DERECHO = %d.\n",FactBal(derechoB(a))); //imprimimos el arbol desbalan

    a=rotaIzqDer(a);
    printf("FactBal DE RAIZ DESPUES DE LA DOBLE = %d.\n",FactBal(a));
    printf("FactBal DEL DERECHO DESPUES DE LA DOBLE = %d.\n",FactBal(derechoB(a)));

    return 0;
}
