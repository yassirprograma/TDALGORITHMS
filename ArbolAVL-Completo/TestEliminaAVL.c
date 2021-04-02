#include<stdio.h>
#include<stdlib.h>
#include"Elem\Elem.h"
#include"ArBin\ArBin.h"
#include"ArBB\ArBB.h"
#include"AVL.h"

int main(){
   ArBB a=vacioB();

   Elem e;

   while(e)
      a=InsAVL(e=scanElem(),a); //LEO LOS ELEMENTOS PARA MI ARBOL

   puts("-----------");
   ImpElem(ElemMasDerechoB(a));

   puts("-----------");
   ImpElem(ElemMasIzquierdoB(a));


   while(!esvacioB(a)){
      puts("Elemento a eliminar?");
      a=EliminaAVL(e=scanElem(),a);
      puts("-----------");
      ImpNivelPorNivelAB(a);
   }

   return 0;
}
