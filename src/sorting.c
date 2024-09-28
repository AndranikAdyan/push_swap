/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sorting.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aadyan <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/20 20:34:31 by aadyan			#+#	#+#			 */
/*   Updated: 2024/07/24 18:35:27 by aadyan		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <push_swap.h>

int	get_max(int *arr, int n)
{
	int	max;
	int	i;

	i = 1;
	max = arr[0];
	while (i < n)
	{
		if (arr[i] > max)
			max = arr[i];
		++i;
	}
	return (max);
}

int	get_min(int *arr, int n)
{
	int	min;
	int	i;

	i = 1;
	min = arr[0];
	while (i < n)
	{
		if (arr[i] < min)
			min = arr[i];
		++i;
	}
	return (min);
}

int	*get_counts(int *arr, int n)
{
	int	max;
	int	min;
	int	size;
	int	*counts;
	int	i;

	max = get_max(arr, n);
	min = get_min(arr, n);
	size = max - min + 1;
	counts = calloc(size, sizeof(int));
	i = 0;
	while (i < n)
	{
		counts[arr[i] - min]++;
		i++;
	}
	return (counts);
}

int	*counting_sort(int *arr, int n, int min, int max)
{
	int	*counts;
	int	*sorted_arr;
	int	el_count;
	int	index;
	int	size;

	size = max - min + 1;
	sorted_arr = malloc(sizeof(int) * n);
	counts = get_counts(arr, n);
	el_count = 0;
	index = 0;
	while (el_count < size)
	{
		while (counts[el_count] > 0)
		{
			sorted_arr[index++] = el_count + min;
			counts[el_count]--;
		}
		el_count++;
	}
	return (free(counts), sorted_arr);
}
