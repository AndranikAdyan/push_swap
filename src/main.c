/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:40:51 by andranik          #+#    #+#             */
/*   Updated: 2025/03/19 19:14:36 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!(check_all(argv, argc) && pushing_elemenst(&a, argv, argc)))
	{
		if (a)
			free_stack(&a);
		printf("Error!\n");
		return (0);
	}
	if (is_sorted(a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
