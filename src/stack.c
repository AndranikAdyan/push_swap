#include <push_swap.h>

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
	printf("_		_\na		b\n");
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

int PushingElemenst(stack **a, char **av, int ac)
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
			if(findDublicates(a, atoi(arr[i]))){
				freeSplit(arr);
				return 0;
			}
			push(a, atoi(arr[i++]));
		}
		freeSplit(arr);
		++index;
	}
	return 1;
}