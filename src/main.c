/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:40:51 by andranik          #+#    #+#             */
/*   Updated: 2024/08/01 19:35:23 by aadyan           ###   ########.fr       */
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
		exit(1);
	}
	a = NULL;
	b = NULL;

	if (!pushing_elemenst(&a, argv, argc))
	{
		printf("Error!\n");
		exit(1);
	}
	print_stacks(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
