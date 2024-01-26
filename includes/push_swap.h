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

int sa(stack **a);
int sb(stack **b);
int ss(stack **a, stack **b);
int pa(stack **a, stack **b);
int pb(stack **a, stack **b);
int ra(stack **a);
int rb(stack **b);
int rr(stack **a, stack **b);
int rra(stack **a);
int rrb(stack **b);
int rrr(stack **a, stack **b);

int ft_atoi(char *num);
long int ft_atol(char *num);

char *ft_substr(char const *s, unsigned int start, size_t len);

char **ft_split(char *str, char sign);
void freeSplit(char **arr);

int checkAll(char **av, int ac);

int findDublicates(stack **a, int data);

#endif