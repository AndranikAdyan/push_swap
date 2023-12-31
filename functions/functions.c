#include <stdio.h>
#include <stdlib.h>

typedef struct t_stack
{
	int				data;
	struct t_stack	*next; 
} stack;

void push(stack **myStack, int data)
{
	stack	*newNode;
	
	newNode = malloc(sizeof(stack));
	if(!newNode)
		exit(12);

	newNode->data = data;
	if (myStack && *myStack)
	{
		newNode->next = *myStack;
		*myStack = newNode;
	}
	else
	{
		newNode->next = NULL;
		*myStack = newNode;
	}
}

void printStacks(stack *a, stack *b)
{
	printf("\n");
	while (a || b)
	{
		if(a)
		{
			printf("%d    ", a->data);
			a = a->next;
		}
		else
			printf("     ");
		if(b)
		{
			printf("%d", b->data);
			b = b->next;
		}
		printf("\n");
	}
	printf("_    _\na    b\n");
}

void freeStack(stack **myStack)
{
	stack	*tmp;

	while (*myStack)
	{
		tmp = (*myStack)->next;
		free(*myStack);
		(*myStack) = tmp;
	}
}

void pop(stack **myStack)
{
	if(*myStack && (*myStack)->next){
		stack	*tmp;
		tmp = (*myStack)->next;
		free(*myStack);
		(*myStack) = tmp;
	}
	else if(*myStack){
		free(*myStack);
		*myStack = NULL;
	}
	else
		printf("\nStack is empty\n");

}


/*
	sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one or no elements.
	sb (swap b): Swap the first 2 elements at the top of stack b.
		---Do nothing if there is only one or no elements.
	ss : sa and sb at the same time.
	pa (push a): Take the first element at the top of b and
				 put it at the top of a.
		---Do nothing if b is empty.
	pb (push b): Take the first element at the top of a and
				 put it at the top of b.
		---Do nothing if a is empty.
	ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.
	rb (rotate b): Shift up all elements of stack b by 1.
		---The first element becomes the last one.
	rr : ra and rb at the same time.
	rra (reverse rotate a): Shift down all elements of stack a by 1.
		---The last element becomes the first one.
	rrb (reverse rotate b): Shift down all elements of stack b by 1.
		---The last element becomes the first one.
	rrr : rra and rrb at the same time.
*/

void sa(stack **a)
{
	if (*a && (*a)->next)
	{
		int		tmp;
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		printf("sa\n");
	}
}

void sb(stack **b)
{
	if (*b && (*b)->next)
	{
		int		tmp;
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
		printf("sb\n");
	}
}

void ss(stack **a, stack **b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

void pa(stack **a, stack **b)
{
	if (*b)
	{
		int		data;
		data = (*b)->data;
		pop(b);
		push(a, data);
		printf("pa");
	}
}

void pb(stack **a, stack **b)
{
	if (*a)
	{
		int		data;
		data = (*a)->data;
		pop(a);
		push(b, data);
		printf("pb");
	}
}

void ra(stack **a)
{
	int		data_tmp;
	stack	*tmp;

	if(*a)
		tmp = *a;
	else
		return;

	while (tmp && tmp->next)
	{
		data_tmp = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = data_tmp;
		tmp = tmp->next;
	}
	printf("ra\n");
}

void rb(stack **b)
{
	int		data_tmp;
	stack	*tmp;

	if(*b)
		tmp = *b;
	else
		return;

	while (tmp && tmp->next)
	{
		data_tmp = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = data_tmp;
		tmp = tmp->next;
	}
	printf("rb\n");
}

void rr(stack **a, stack **b)
{
	ra(a);
	rb(b);
}

void rra(stack **a)
{
	stack	*first;
	stack *tmp;
	int data_tmp;
	if (*a)
	{
		first = *a;
		tmp = *a;
	}
	else
		return;

	tmp = tmp->next;
	while (tmp)
	{
		data_tmp = first->data;
		first->data = tmp->data;
		tmp->data = data_tmp;
		tmp = tmp->next;
	}
	printf("rra\n");
}

void rrb(stack **b)
{
	stack	*first;
	stack *tmp;
	int data_tmp;
	if (*b)
	{
		first = *b;
		tmp = *b;
	}
	else
		return;

	tmp = tmp->next;
	while (tmp)
	{
		data_tmp = first->data;
		first->data = tmp->data;
		tmp->data = data_tmp;
		tmp = tmp->next;
	}
	printf("rrb");
}

void rrr(stack **a, stack **b)
{
	rra(a);
	rrb(b);
}

int main()
{
	stack *a;
	a = NULL;
	stack *b;
	b = NULL;

	push(&b, 4);
	push(&b, 3);
	push(&b, 2);
	push(&b, 1);

	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	printStacks(a, b);

	rrb(&b);

	printStacks(a, b);

	freeStack(&a);
	freeStack(&b);
	
	return 0;
}
