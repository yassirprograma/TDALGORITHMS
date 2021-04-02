#include<stdio.h>
#include<stdlib.h>
#include"Elem\Elem.h" //TRABAJAMOS CON ELEMENTOS ENTEROS, FUNCIONES DE COMPARACIÓN, E IMPRESIÓN
#include"ArBin\ArBin.h" //ARBOL BINARIO
#include"ArBB\ArBB.h" //ARBOL DE BÚSQUEDA BINARIA
#include"AVL.h" //FUNCIONES AVL

int main(){

    AVL a=vacioB(); //declaramos un avl vacío
    int i=1,n;

    while(i){ //insertamos elementos mientras querramos, PERO AHORA SÍ, BALANCEANDO, E IMPRIMIENDO QUÉ CASO SUCEDIÓ
        scanf("%d",&n);
        a=InsAVL(n,a);

        printf("1 para continuar, 0 para salir.");
        scanf("%d",&i);
    }



    return 0;
}
