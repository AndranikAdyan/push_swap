#include <push_swap.h>

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

int sa(stack **a)
{
	if (*a && (*a)->next)
	{
		int		tmp;
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		return 1;
	}
	return 0;
}

int sb(stack **b)
{
	if (*b && (*b)->next)
	{
		int		tmp;
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
		return 1;
	}
	return 0;
}

int ss(stack **a, stack **b)
{
	if (sa(a) && sb(b))
		return 1;
	return 0;	
}

int pa(stack **a, stack **b)
{
	if (*b)
	{
		int		data;
		data = (*b)->data;
		pop(b);
		push(a, data);
		return 1;
	}
	return 0;
}

int pb(stack **a, stack **b)
{
	if (*a)
	{
		int		data;
		data = (*a)->data;
		pop(a);
		push(b, data);
		return 1;
	}
	return 0;
}

int ra(stack **a)
{
	int		data_tmp;
	stack	*tmp;

	if(*a)
		tmp = *a;
	else
		return 0;

	while (tmp && tmp->next)
	{
		data_tmp = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = data_tmp;
		tmp = tmp->next;
	}
	return 1;
}

int rb(stack **b)
{
	int		data_tmp;
	stack	*tmp;

	if(*b)
		tmp = *b;
	else
		return 0;

	while (tmp && tmp->next)
	{
		data_tmp = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = data_tmp;
		tmp = tmp->next;
	}
	return 1;
}

int rr(stack **a, stack **b)
{
	if(ra(a) && rb(b))
		return 1;
	return 0;
}

int rra(stack **a)
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
		return 0;

	tmp = tmp->next;
	while (tmp)
	{
		data_tmp = first->data;
		first->data = tmp->data;
		tmp->data = data_tmp;
		tmp = tmp->next;
	}
	return 1;
}

int rrb(stack **b)
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
		return 0;

	tmp = tmp->next;
	while (tmp)
	{
		data_tmp = first->data;
		first->data = tmp->data;
		tmp->data = data_tmp;
		tmp = tmp->next;
	}
	return 1;
}

int rrr(stack **a, stack **b)
{
	if(rra(a) && rrb(b))
		return 1;
	return 0;
}