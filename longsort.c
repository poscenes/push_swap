/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:57:47 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 18:00:54 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_push_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (!b)
			break ;
		if ((*b)->index != maxind(*b) && !compare(b, maxind(*b), stack_len(*b)))
			rb(b, 1);
		else if ((*b)->index != maxind(*b)
			&& compare(b, maxind(*b), stack_len(*b)))
			rrb(b, 1);
		else if ((*b)->index == maxind(*b))
			pa(a, b);
	}
}

static void	sort_100(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (*a)
	{
		if (i > 1 && (*a)->index <= i)
		{
			pb(a, b);
			i++;
			rb(b, 1);
		}
		else if ((*a)->index <= i + 15)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i)
			ra(a, 1);
	}
	sort_push_a(a, b);
}

static void	sort_500(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (*a)
	{
		if (i > 1 && (*a)->index <= i)
		{
			pb(a, b);
			i++;
			rb(b, 1);
		}
		else if ((*a)->index <= i + 30)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i)
			ra(a, 1);
	}
	sort_push_a(a, b);
}

void	longsort(t_stack **a, t_stack **b, int size)
{
	if (size <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}
