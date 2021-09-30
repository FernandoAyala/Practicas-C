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
