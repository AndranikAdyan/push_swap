/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:56:43 by andranik          #+#    #+#             */
/*   Updated: 2024/02/10 12:04:19 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(12);
	new_node->data = data;
	if (stack && *stack)
	{
		new_node->next = *stack;
		*stack = new_node;
	}
	else
	{
		new_node->next = NULL;
		*stack = new_node;
	}
}

void	printt_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("%d    ", a->data);
			a = a->next;
		}
		else
			printf("     ");
		if (b)
		{
			printf("%d", b->data);
			b = b->next;
		}
		printf("\n");
	}
	printf("_		_\na		b\n");
}

void	freet_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}

void	pop(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
	else if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
	else
		printf("\nt_stack is empty\n");
}

int	pushing_elemenst(t_stack **a, char **av, int ac)
{
	char	**arr;
	int		i;
	int		index;

	index = 1;
	while (index < ac)
	{
		i = 0;
		arr = ft_split(av[index], ' ');
		while (arr[i])
		{
			if (find_dublicates(a, atoi(arr[i])))
			{
				free_split(arr);
				return (0);
			}
			push(a, atoi(arr[i++]));
		}
		free_split(arr);
		++index;
	}
	return (1);
}
