/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:09:05 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 11:03:32 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	max;
	int	min;

	max = func_max(*stack);
	min = func_min(*stack);
	while (!is_sorted(*stack))
	{
		if (max == (*stack)->value)
		{
			ra(stack, 1);
			if ((*stack)->value > (*stack)->next->value)
				sa(stack, 1);
		}
		else if (max == (*stack)->next->next->value)
			sa(stack, 1);
		else
		{
			rra(stack, 1);
			if ((*stack)->value > (*stack)->next->value)
				sa(stack, 1);
		}
	}
}

static void	find_n_rot(t_stack **stack, int (*f)(t_stack *))
{
	while ((*stack)->value != f(*stack))
	{
		if ((*stack)->next->value != f(*stack)
			&& (*stack)->next->next->value != f(*stack))
			rra(stack, 1);
		else
			ra(stack, 1);
	}
}

static void	sort_45(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 5)
	{
		find_n_rot(stack_a, func_min);
		pb(stack_a, stack_b);
	}
	find_n_rot(stack_a, func_max);
	pb(stack_a, stack_b);
	while (stack_len(*stack_a) != 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	ra(stack_a, 1);
	if (size == 5)
		pa(stack_b, stack_a);
	if (!is_sorted(*stack_a))
		ra(stack_a, 1);
}

void	sort5ex(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		sort_3(stack_a);
	else
		sort_45(stack_a, stack_b, size);
}
