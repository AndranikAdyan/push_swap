#include <push_swap.h>

static int wordsCount(char *str, char sign)
{
	int		i = 0;
	int		count = 0;
	while (str[i])
	{
		while (str[i] == sign)
			++i;
		if (str[i] && str[i] != sign)
			++count;
		while (str[i] && str[i] != sign)
			++i;
	}
	return count;
}

static char **fillStr(char *str, char sign)
{
	int		start;
	int		index = 0;
	char	**arr;
	int		i;

	int		count;
	count = wordsCount(str, sign);
	arr = malloc((count + 1) * sizeof(char*));

	i = 0;
	while (str[i])
	{

		while (str[i] == sign)
			++i;
		start = i;

		while (str[i] && str[i] != sign)
			++i;
		arr[index] = ft_substr(str, start, i - start);

		if (arr[index] && !arr[index][0])
			free(arr[index]);
		index++;
	}
	arr[count] = '\0';
	return arr;
}

char **ft_split(char *str, char sign)
{
	char	**arr;
	arr = fillStr(str, sign);
	
	return arr;
}	

void freeSplit(char **arr)
{
	int		i;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	
	free(arr);
	arr = NULL;
}

// void freeSplit(char **arr)
// {
// 	int i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}

// 	free(arr);  // Эта строка осталась без изменений
// }
