#include<stdio.h>
#include<stdlib.h>
#include"Elem\Elem.h" //TRABAJAMOS CON ELEMENTOS ENTEROS, FUNCIONES DE COMPARACI�N, E IMPRESI�N
#include"ArBin\ArBin.h" //ARBOL BINARIO
#include"ArBB\ArBB.h" //ARBOL DE B�SQUEDA BINARIA
#include"AVL.h" //FUNCIONES AVL

int main(){

    AVL a=vacioB(); //declaramos un avl vac�o
    int i=1,n;

    while(i){ //insertamos elementos mientras querramos, PERO AHORA S�, BALANCEANDO, E IMPRIMIENDO QU� CASO SUCEDI�
        scanf("%d",&n);
        a=InsAVL(n,a);

        printf("1 para continuar, 0 para salir.");
        scanf("%d",&i);
    }



    return 0;
}
