/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:39:41 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 20:34:16 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sa(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*a)
	{
		if ((*a)->next)
		{
			tmp = *a;
			tmp1 = tmp->next->next;
			*a = (*a)->next;
			(*a)->next = tmp;
			(*a)->next->next = tmp1;
		}
	}
	return (1);
}

int	check_sb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*b)
	{
		if ((*b)->next)
		{
			tmp = *b;
			tmp1 = tmp->next->next;
			*b = (*b)->next;
			(*b)->next = tmp;
			(*b)->next->next = tmp1;
		}
	}
	return (1);
}

int	check_ss(t_stack **a, t_stack **b)
{
	if (*b && *a)
	{
		if ((*b)->next && (*a)->next)
		{
			check_sa(a);
			check_sb(b);
		}
	}
	return (1);
}
