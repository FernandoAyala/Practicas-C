#include <stdio.h>
#include <stdlib.h>
#include"matematica.h"
int main()
{
    int n,sumP,/* c1, c2,*/ multi, multiSv/*, division*/;
//    float resultadoC;
//    printf("Ingrese un numero para factorizar: \t");
//    scanf("%d",&n);
//    printf("\n El calculo de factorizar el numero : %d es %.2f",n,factorial(n));
//    printf("\n Ingrese numeros para realizaar una combinatoria");
//    printf("\n Primer numero:");
//    scanf("%d", &c1);
//    printf("\n Segundo numero:");
//    scanf("%d",&c2);
//    if( c1>=c2 && c2>= 0 )
//    {
//        resultadoC = combinatorio(c2,c1);
//        printf("\n La combinatoria da como resultado: %.2f", resultadoC);
//    }
//    else
//        printf("\n Los valores ingresados no son los correctos\n");

    multi = multiRusa(20,8);
    printf("\nLa multi Rusa es: %d\n",multi);
    multiSv = multiSuc(5,4);
    printf("\nLa multi Sucesiva es: %d\n",multiSv);
//    division = divconRestoyCociente(10,3);
//    printf ("%d",division);
    n = perfdefabund(12);
    if(n == 1)
    {
        printf("\nPerfecto");
    }
    else if(n == 2)
    {
        printf("\nAbundante");
    }
    else
    {
        printf("\nDeficiente");
    }
    sumP= sumaNumPares(8);
    printf("\n%d", sumP);
    return 0;
}
