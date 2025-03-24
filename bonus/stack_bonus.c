/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:43:46 by aadyan            #+#    #+#             */
/*   Updated: 2025/03/24 19:43:47 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	get_index(t_stack *stack, int num)
{
	size_t	index;

	if (!stack)
		return (0);
	index = 0;
	while (stack)
	{
		if (num < stack->data->number)
		{
			stack->data->index++;
			if (index > stack->data->index)
				index = stack->data->index - 1;
		}
		else if (stack->data->index >= index)
			index = stack->data->index + 1;
		stack = stack->next;
	}
	return (index);
}

void	push(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit(12);
	new_node->data = (t_data *)malloc(sizeof(t_data));
	new_node->data->number = num;
	new_node->data->index = get_index(*stack, num);
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->data);
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
		free((*stack)->data);
		free(*stack);
		(*stack) = tmp;
	}
	else if (*stack)
	{
		free((*stack)->data);
		free(*stack);
	}
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
			if (find_dublicates(*a, atoi(arr[i])))
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
