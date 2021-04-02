typedef int Elem;

void fImpElem(FILE *salida, Elem e){ fprintf(salida,"%d\n",e);} //IMPRIME EN ALGÚN ARCHIVO
void ImpElem(Elem e){ fImpElem(stdout,e);} //IMPRIME EN EL ARCHIVO STDOUT QUE ES LO QUE VEMOS EN TERMINAL

int EsMenor(Elem e1, Elem e2){return e1<e2;} //IDENTIFICA CUÁL ENTERO ES MENOR
int EsIgual(Elem e1, Elem e2){return e1==e2;}

Elem scanElem(){  //NOMAS ES PARA LUCIRSE
    Elem e;
    scanf("%d",&e);
    return e;
}


