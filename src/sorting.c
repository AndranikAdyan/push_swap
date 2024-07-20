/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:31 by aadyan            #+#    #+#             */
/*   Updated: 2024/07/20 20:47:58 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*fill_zero(int *arr, int n)
{
	int		i;

	i = 0;
	while (i < n)
		arr[i] = 0;
	i = 0;
	while (i < n)
		printf("%d ", arr[i]);
	return (arr);
}

void	counting_sort(int *arr, int n)
{
	int	min;
	int	max;
	int	i;
	int	els_count;
	int	*values_count;

	min = get_min(arr, n);
	max = get_max(arr, n);
	els_count = (max - min + 1);
	*values_count = malloc(els_count * sizeof(char));
	valuesCount = fill_zero(valuesCount, els_count);
	i = 0;
	while (i < n)
		valuesCount[arr[i] - min]++;
	i = 0;
	while (i < n)
		printf("%d ", valuesCount[i]);
}
