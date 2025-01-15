/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:40:51 by andranik          #+#    #+#             */
/*   Updated: 2025/01/15 21:32:01 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_all(argv, argc))
	{
		printf("Error!\n");
		return (0);
	}
	a = NULL;
	b = NULL;

	if (!pushing_elemenst(&a, argv, argc))
	{
		printf("Error!\n");
		return (0);
	}
	if (is_sorted(a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	sort_under_12(a, b);
	print_stacks(a, b);

	free_stack(&a);
	free_stack(&b);
	return (0);
}
