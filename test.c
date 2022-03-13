#include "push_swap.h"

void	drop_in_stack_b(t_stack **stack_a, t_stack **stack_b, int *max, int *min)
{
	int 	median;

	median = get_median(stack_a);
	*min = search_min(*stack_a);
	*max = search_max(*stack_a);
	while (stack_len(*stack_a) != 3)
	{
		if ((*stack_a)->value != *min && (*stack_a)->value != *max
		&& (*stack_a)->value != median)
		{
			if ((*stack_a)->value < median)
				pb(stack_a, stack_b);
			else
			{
				pb(stack_a, stack_b);
				rb(stack_b, 1);
			}
		}
		else
			ra(stack_a, 1);
	}
	if (!a_is_sorted(*stack_a))
		sort_3(stack_a);
}

int		get_flag(t_stack **stack_a, int value)
{
	int		count;
	t_stack	*t;

	t = *stack_a;
	count = 0;
	while (t->next->next)
	{
		count++;
		if (value > t->value && value < t->next->value)
			break ;
		t = t->next;
	}
	if (count > stack_len(*stack_a) - count)
		return (0);
	else
		return (1);
}

void	rotate_in_needed_position(t_stack **stack_a)
{
	int		count;
	t_stack	*t;

	count = 0;
	t = *stack_a;
	while (t)
	{
		count++;
		if (t->value == search_min(*stack_a))
			break ;
		t = t->next;
	}
	if (count > stack_len(*stack_a) - count)
	{
		while ((*stack_a)->value != search_min(*stack_a))
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->value != search_min(*stack_a))
			rra(stack_a, 1);
	}
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b, int value, int range)
{
	while (1)
	{
		if ((value > (*stack_a)->value && value < (*stack_a)->next->value)
			|| (*stack_b)->value == value)
			break ;
		if (get_flag(stack_a, value) && range < stack_len(*stack_b) - range)
		{
			while (!((value > (*stack_a)->value && value < (*stack_a)->next->value)
					 || (*stack_b)->value == value))
			{
				rr(stack_a, stack_b);
			}
			break ;
		}
		else if (!get_flag(stack_a, value) && range >= stack_len(*stack_b) - range)
		{
			while (!((value > (*stack_a)->value && value < (*stack_a)->next->value)
				   || (*stack_b)->value == value))
			{
				rrr(stack_a, stack_b);
			}
			break ;
		}
		else
			break ;
	}
}

void	find_position(t_stack **stack_a, t_stack **stack_b, int comand)
{
	while (1)
	{
		if ((*stack_b)->value > (*stack_a)->value
			&& (*stack_b)->value < (*stack_a)->next->value)
		{
			ra(stack_a, 1);
			pa(stack_a, stack_b);
			break ;
		}
		if (comand)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	find_element_in_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*t1;
	t_stack	*t2;
	int		count;
	int 	min_count;
	int 	value;

	t2 = *stack_b;
	min_count = INT_MAX;
	while (t2)
	{
		t1 = *stack_a;
		count = 0;
		while (t1->next->next)
		{
			count++;
			if (t2->value > t1->value && t2->value < t1->next->value)
				break ;
			t1 = t1->next;
		}
		if (count > stack_len(*stack_a) - count)
			count = stack_len(*stack_a) - count;
		if (count < min_count)
		{
			min_count = count;
			value = t2->value;
		}
		t2 = t2->next;
	}
	t1 = *stack_b;
	count = 0;
	while (t1)
	{
		count++;
		if (value == t1->value)
			break;
		t1 = t1->next;
	}
	double_rotate(stack_a, stack_b, value, count);
	while ((*stack_b)->value != value)
	{
		if (count < stack_len(*stack_b) - count)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	int		min;

	max = search_max(*stack_a);
	min = search_min(*stack_a);
	drop_in_stack_b(stack_a, stack_b, &max, &min);
	while (stack_len(*stack_b))
	{
		find_element_in_stack_b(stack_a, stack_b);
		find_position(stack_a, stack_b, get_flag(stack_a, (*stack_b)->value));
	}
	rotate_in_needed_position(stack_a);
}