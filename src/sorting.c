#include <push_swap.h>

int		get_min(int *arr, int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
		if(min > arr[i])
			min = arr[i];
	return min;
}

int		get_max(int *arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if(max < arr[i])
			max = arr[i];
	return max;
}

int		*fill_zero(int *arr, int n)
{
	int i;
	i = 0;

	while (i < n)
		arr[i] = 0;
	
	i = 0;

	while (i < n)
		printf("%d ", arr[i]);

	return arr;
}

// int		*fill_arr(char **av, int ac)
// {
	
// }

void	countingSort(int *arr, int n)
{
	int min;
	int max;
	int i;
	int els_count;
	min = get_min(arr, n);
	max = get_max(arr, n);

	els_count = (max - min + 1);
	int *valuesCount = malloc(els_count * sizeof(char));

	valuesCount = fill_zero(valuesCount, els_count);

	i = 0;
	while (i < n)
		valuesCount[arr[i] - min]++;

	i = 0;
	while (i < n)
		printf("%d ", valuesCount[i]);
}
