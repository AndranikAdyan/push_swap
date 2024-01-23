#include <push_swap.h>

int ft_atoi(char *num)
{
	int res = 0;
	int i = 0;
	while(num[i])
		res = res * 10 + num[i++] - '0'; 
	
	return res;
}