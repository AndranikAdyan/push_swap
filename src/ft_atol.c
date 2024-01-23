#include <push_swap.h>

long int ft_atol(char *num)
{
	long int res = 0;
	int i = 0;
	while(num[i])
		res = res * 10 + num[i++] - '0'; 

	return res;
}