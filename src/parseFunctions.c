#include <push_swap.h>

static int intRange(char *str)
{
	int		i;
	i = 0;
	while (str[i++])
		if(i > 11)
			return 0;

	if (atol(str) >= INT_MIN && atol(str) <= INT_MAX)
		return 1;
	return 0;
}

static int checkSign(char *str, int j)
{
	if ((str[j] < '0' || str[j] > '9') && str[j] != '+' \
		&& str[j] != '-'&& str[j] != ' ')
			return 0;

	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j - 1] && str[j - 1] != ' ')
			return 0;

		if (!str[j + 1])
			return 0;

		if (str[j + 1])
			if(str[j + 1] < '0' || str[j + 1] > '9')
				return 0;
	}
	return 1;
}

static int checkSymbols(char **av, int ac)
{
	int i = 1;
	while (i < ac)
	{
		int j = 0;
		while (av[i][j])
		{
			if (!checkSign(av[i], j))
				return 0;
			j++;
		}
	i++;
	}
	return 1;
}

static int checkNumberStart(char *str)
{
	if ((str[0] == '0' && str[1]) || \
		((str[0] == '+' || str[0] == '-') && \
		str[1] == '0'))
			return 0;
	return 1;
}

int findDublicates(stack **a, int data)
{
	stack	*tmp;
	tmp = *a;


	while(tmp)
	{
		if(data == tmp->data)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}


int checkAll(char **av, int ac)
{
	if (!checkSymbols(av, ac))
		return 0;
	int		i;
	int		index;
	index = 1;

	char **arr;
	while (index < ac)
	{
		if(!checkNumberStart(av[index]))
			return 0;

		i = 0;
		arr = ft_split(av[index], ' ');

		while (arr[i])
			if (!intRange(arr[i++]))
			{
				freeSplit(arr);
				return 0;
			}

		freeSplit(arr);
		++index;
	}

	return 1;
}