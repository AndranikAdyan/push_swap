/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:43:33 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/24 19:43:34 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data->index > a->next->data->index)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	print_msg(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	checker(&a, &b);
	print_msg(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
