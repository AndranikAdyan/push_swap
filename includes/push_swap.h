/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:04:05 by andranik          #+#    #+#             */
/*   Updated: 2024/07/24 20:51:06 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void		push(t_stack **stack, int data);
void		pop(t_stack **stack);
void		free_stack(t_stack **stack);
void		print_stacks(t_stack *a, t_stack *b);
int			pushing_elemenst(t_stack **a, char **av, int ac);

int			sa(t_stack **a);
int			sb(t_stack **b);
int			ss(t_stack **a, t_stack **b);
int			pa(t_stack **a, t_stack **b);
int			pb(t_stack **a, t_stack **b);
int			ra(t_stack **a);
int			rb(t_stack **b);
int			rr(t_stack **a, t_stack **b);
int			rra(t_stack **a);
int			rrb(t_stack **b);
int			rrr(t_stack **a, t_stack **b);

int			ft_atoi(char *num);
long int	ft_atol(char *num);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		**ft_split(char *str, char sign);
void		free_split(char **arr);

int			check_all(char **av, int ac);

int			find_dublicates(t_stack **a, int data);

int			get_min(int *arr, int n);
int			get_max(int *arr, int n);

int			*counting_sort(int *arr, int n, int min, int max);

#endif