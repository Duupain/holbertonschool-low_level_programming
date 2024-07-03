#include "main.h"
/**
*isprimenumberv2 - fonction qui verifie si le nombre esr premier
*@n: nombre
*@d: diviseur
*Return: 1 si n est premier, sinon 0
*/
int isprimenumberv2(int n, int d)
{
/**si le diviseur depasse la racine carree de n, n est premier*/
if (d * d > n)
{
return (1);
}
/**Si n est divisible par d, n n'est pas premier*/
if (n % d == 0)
{
return (0);
}
/**Appel recursif avec le diviseur incremente*/
return (isprimenumberv2(n, d + 1));
}
/**
*is_prime_number - Fonction principale pour verifier si un nombre est premier
*@n: nombre
*Return: 1 si n est premier, sinon 0
*/
int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}
return (isprimenumberv2(n, 2));
}
