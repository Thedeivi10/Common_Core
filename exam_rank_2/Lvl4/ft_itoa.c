/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <unistd.h>
#include <stdlib.h>

char *ft_itoa (int nbr)
{
	char *result;
	int n;
	n = nbr;
	int len = 0;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	result = malloc(sizeof(char)*(len + 1));
	if (!result)
		return NULL;
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		result[0] = '-';
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /=10;
	}
	return result;
}
