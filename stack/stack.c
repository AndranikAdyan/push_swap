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