#include "matematica.h"

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
/***************************/
double combinatorio ( int n, int m )
{
    double factN = factorial(n);
    double factM = factorial(m);
    double factMN = factorial(m - n);
    return factM/(factN * factMN);
}
/***************************/
