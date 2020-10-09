#include <stdio.h>
#include <stdlib.h>
#include "elem.h" //como estan en la misma carpeta que este prograama, las incluimos así, pero hay que tener en cuenta la ubicacion
#include "lista.h"

int main()
{   //ya jala


    Lista milista=vacia(); //declaramos lista vacia
    int cantidad=0,nuevoe=0;

    puts("Cantidad de elementos de mi lista:");
    scanf("%d",&cantidad);

    for(int i=1;i<=cantidad;i++){
        puts("nuevacabeza:");
        scanf("%d",&nuevoe);

        milista=cons(nuevoe,milista);
    }

    /* Prueba de las funcioes de lista.h*/

    //cantidad de elementos:
    printf("\nCantidad de elementos: %d \n", NumElems(milista));

    //lista normal lifo
    puts("\nLista, el ultimo que entra es el primero que sale:");
    ImpElems(milista);

    //invertimos lista
    milista=InvierteLista(milista);
    puts("\nLista invertida:");
    ImpElems(milista);

    //ordenamos lista
    milista=OrdListaAsc(milista);
    puts("\nLista ordenada asc:");
    ImpElems(milista);

    //insertamos un valor en orden
    puts("\n nuevo elemento:");
    fflush(stdin); //limpiamos buffer
    scanf("%d",&nuevoe);
    milista=InsOrd(nuevoe,milista);
    puts("elemento insertado");
    ImpElems(milista);









    return 0;
}
