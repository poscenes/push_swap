/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:57:47 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 12:03:07 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_pusha(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		if (!stack_b)
			break ;
		if ((*stack_b)->index != max_index(stack_b)
			&& !compare(stack_b, max_index(stack_b), stack_len(*stack_b)))
			rb(stack_b, 1);
		else if ((*stack_b)->index != max_index(stack_b)
			&& compare(stack_b, max_index(stack_b), stack_len(*stack_b)))
			rrb(stack_b, 1);
		else if ((*stack_b)->index == max_index(stack_b))
			pa(stack_b, stack_a);
	}
}

static void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = 0;
	while (*stack_a)
	{
		if (n > 1 && (*stack_a)->index <= n)
		{
			pb(stack_a, stack_b);
			n++;
			rb(stack_b, 1);
		}
		else if ((*stack_a)->index <= n + 15)
		{
			pb(stack_a, stack_b);
			n++;
		}
		else if ((*stack_a)->index >= n)
		{
			ra(stack_a, 1);
		}
	}
	sort_to_pusha(stack_a, stack_b);
}

static void	sort_500(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = 0;
	while (*stack_a)
	{
		if (n > 1 && (*stack_a)->index <= n)
		{
			pb(stack_a, stack_b);
			n++;
			rb(stack_b, 1);
		}
		else if ((*stack_a)->index <= n + 30)
		{
			pb(stack_a, stack_b);
			n++;
		}
		else if ((*stack_a)->index >= n)
		{
			ra(stack_a, 1);
		}
	}
	sort_to_pusha(stack_a, stack_b);
}

void	long_sort(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(stack_a);
	if (stack_len(*stack_a) <= 100)
		sort_100(stack_a, stack_b);
	else
		sort_500(stack_a, stack_b);
}
