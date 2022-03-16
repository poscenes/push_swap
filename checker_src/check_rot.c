/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:33:46 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 20:34:35 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*a)
	{
		if ((*a)->next)
		{
			tmp = *a;
			tmp1 = *a;
			*a = (*a)->next;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = tmp1;
			tmp->next->next = NULL;
		}
	}
	return (1);
}

int	check_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*b)
	{
		if ((*b)->next)
		{
			tmp = *b;
			tmp1 = *b;
			*b = (*b)->next;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = tmp1;
			tmp->next->next = NULL;
		}
	}
	return (1);
}

int	check_rr(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		if ((*a)->next && (*b)->next)
		{
			check_ra(a);
			check_rb(b);
		}
	}
	return (1);
}
