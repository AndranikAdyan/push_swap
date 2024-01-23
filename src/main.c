#include <push_swap.h>

int main(int argc, char **argv)
{
	if(!checkAll(argv, argc))
	{
		printf("Error!\n");
		exit(1);
	}
	

	stack *a;
	a = NULL;
	stack *b;
	b = NULL;

	if(!PushingElemenst(&a, argv, argc))
	{
		printf("Error!\n");
		exit(1);
	}

	printStacks(a, b);

	freeStack(&a);
	freeStack(&b);

	return 0;
}