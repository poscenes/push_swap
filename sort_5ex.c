/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:09:05 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 18:01:27 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack **s)
{
	if ((*s)->next->index < (*s)->index)
		sa(s, 1);
}

static void	sort_3(t_stack **s)
{
	if ((*s)->index == maxind(*s))
		ra(s, 1);
	if ((*s)->index == minind(*s) && (*s)->next->index == maxind(*s))
	{
		rra(s, 1);
		sa(s, 1);
	}
	if ((*s)->index != minind(*s) && (*s)->index > (*s)->next->index)
		sa(s, 1);
	if ((*s)->index != minind(*s) && (*s)->index < (*s)->next->index)
		rra(s, 1);
}

static void	sort_4(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*a)->index > minind(*a) && !compare(a, minind(*a), stack_len(*a)))
			ra(a, 1);
		else if ((*a)->index > minind(*a)
			&& compare(a, minind(*a), stack_len(*a)))
			rra(a, 1);
		else
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->index != minind(*a))
		sa(a, 1);
	while (*b)
		pa(a, b);
}

static void	sort_5(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((*a)->index > minind(*a) && !compare(a, minind(*a), stack_len(*a)))
			ra(a, 1);
		else if ((*a)->index > minind(*a)
			&& compare(a, minind(*a), stack_len(*a)))
			rra(a, 1);
		else
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->index != minind(*a))
		sa(a, 1);
	while (*b)
		pa(a, b);
}

void	sort5ex(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
