/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:44:34 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/24 19:44:35 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!(check_all(argv, argc) && pushing_elemenst(&a, argv, argc)))
	{
		if (a)
			free_stack(&a);
		write(2, "Error!\n", 7);
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
