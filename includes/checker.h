/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:04:05 by andranik          #+#    #+#             */
/*   Updated: 2025/03/20 21:58:43 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_data
{
	int		number;
	size_t	index;
}	t_data;

typedef struct s_stack
{
	t_data			*data;
	struct s_stack	*next;
}	t_stack;

void		push(t_stack **stack, int data);
void		pop(t_stack **stack);
void		free_stack(t_stack **stack);
int			pushing_elemenst(t_stack **a, char **av, int ac);

void		swap_data(t_data *data1, t_data *data2);
int			sa(t_stack **a, int mess);
int			sb(t_stack **b, int mess);
int			ss(t_stack **a, t_stack **b, int mess);
int			pa(t_stack **a, t_stack **b, int mess);
int			pb(t_stack **a, t_stack **b, int mess);
int			ra(t_stack **a, int mess);
int			rb(t_stack **b, int mess);
int			rr(t_stack **a, t_stack **b, int mess);
int			rra(t_stack **a, int mess);
int			rrb(t_stack **b, int mess);
int			rrr(t_stack **a, t_stack **b, int mess);

long int	ft_atol(char *num);

void		free_split(char **arr);

int			check_all(char **av, int ac);

int			find_dublicates(t_stack *a, int data);

int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);

void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);

void		checker(t_stack **a, t_stack **b);

#endif
