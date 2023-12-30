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

// void pop(stack **myStack)
// {
// 	if(*myStack && (*myStack)->next){
// 		stack	*tmp;
// 		tmp = (*myStack)->next;
// 		free(*myStack);
// 		(*myStack) = tmp;
// 	}
// 	else if(*myStack)
// 		free(*myStack);
// 	else
// 		printf("Stack is empty");
// }

int main()
{
	stack	*a;
	a = NULL;
	stack	*b;
	b = NULL;

	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&a, 4);
	
	push(&b, 5);
	push(&b, 6);
	push(&b, 7);
	push(&b, 8);
	printStacks(a, b);

	freeStack(&a);
	freeStack(&b);

	return 0;
}
