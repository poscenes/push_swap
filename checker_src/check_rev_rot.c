/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:52 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 20:47:37 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*a)
	{
		if ((*a)->next)
		{
			tmp = *a;
			tmp1 = tmp;
			while (tmp->next->next)
				tmp = tmp->next;
			*a = tmp->next;
			tmp->next = NULL;
			(*a)->next = tmp1;
		}
	}
	return (1);
}

int	check_rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*b)
	{
		if ((*b)->next)
		{
			tmp = *b;
			tmp1 = tmp;
			while (tmp->next->next)
				tmp = tmp->next;
			*b = tmp->next;
			tmp->next = NULL;
			(*b)->next = tmp1;
		}
	}
	return (1);
}

int	check_rrr(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		if ((*a)->next && (*b)->next)
		{
			check_rra(a);
			check_rrb(b);
		}
	}
	return (1);
}
