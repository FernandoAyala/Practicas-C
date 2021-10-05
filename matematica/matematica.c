#include "matematica.h"

/*****Ejercicio 1****/
double factorial ( int n )
{
    int fact = 1;

    if( n <= 0 )
        return 1;
    while( n > 1 )
    {
        fact*=n;
        n--;
    }
    return fact;
}
/*********Ejercicio 2******************/
double combinatorio ( int n, int m )
{
    double factN = factorial(n);
    double factM = factorial(m);
    double factMN = factorial(m - n);
    return factM/(factN * factMN);
}
/********Ejercicico 20*******************/

int multiRusa(int n1, int n2)
{
    int suma =0;
    while( n1 >= 1)
    {
        if(n1%2 != 0)
            suma+=n2;
        n2 = n2*2;
        n1 = n1/2;
    }
    return suma;
}

/******* Ejercicio 8 ***************/
int multiSuc (int n1, int n2)
{
    int multi=0, i;

    for (i =0 ; i<n2 ; i++)
    {
        multi+=n1;
    }
    return multi;
}


/******** Ejercicio 9 ******/
int divconRestoyCociente(int n1, int n2)
{
    int cociente = 0, resto =0;
    if(n2!=0)
    {
        cociente = n1/n2;
        resto = n1%n2;
        printf("El cociente de la division es %d\n", cociente);
        printf("El resto de la division es %d\n", resto);
    }
    else{
        printf("No se puede dividir 0");
    }

    return 1;
}
/******** Ejercicio 7******/
int perfdefabund (int n1)
{
    int suma =0, i,val;
    for(i=1; i<n1; i++)
    {
        if(n1%i == 0)
        {
            suma+=i;
        }
    }
    return val=((suma == n1) ? 1 : ((suma > n1) ? 2 : 3));
}

/***** Ejercicio 12***/
int sumaNumPares (int n1)
{
    int suma =0;
    for(int i=0; i<n1; i++)
    {
        if(i%2==0)
        {
            suma+=i;
        }
    }
    return suma;
}
