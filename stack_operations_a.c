/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:04 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 14:30:21 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_putendl_fd("pa", 1);
}

void	sa(t_stack **a, int both)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	tmp1 = tmp->next->next;
	*a = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = tmp1;
	if (both)
		ft_putendl_fd("sa", 1);
}

void	ra(t_stack **a, int both)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	tmp1 = *a;
	*a = (*a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp1;
	tmp->next->next = NULL;
	if (both)
		ft_putendl_fd("ra", 1);
}

void	rra(t_stack **a, int both)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	tmp1 = tmp;
	while (tmp->next->next)
		tmp = tmp->next;
	*a = tmp->next;
	tmp->next = NULL;
	(*a)->next = tmp1;
	if (both)
		ft_putendl_fd("rra", 1);
}
