#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

typedef struct t_stack
{
	int				data;
	struct t_stack	*next; 
} stack;

void push(stack **myStack, int data);
void pop(stack **myStack);
void freeStack(stack **myStack);
void printStacks(stack *a, stack *b);
int PushingElemenst(stack **a, char **av, int ac);

void sa(stack **a);
void sb(stack **b);
void ss(stack **a, stack **b);
void pa(stack **a, stack **b);
void pb(stack **a, stack **b);
void ra(stack **a);
void rb(stack **b);
void rr(stack **a, stack **b);
void rra(stack **a);
void rrb(stack **b);
void rrr(stack **a, stack **b);

int ft_atoi(char *num);
long int ft_atol(char *num);

char *ft_substr(char const *s, unsigned int start, size_t len);

char **ft_split(char *str, char sign);
void freeSplit(char **arr);

int checkAll(char **av, int ac);

int findDublicates(stack **a, int data);

#endif