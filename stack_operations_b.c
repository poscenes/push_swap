/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:04 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 14:30:42 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	ft_putendl_fd("pb", 1);
}

void	sb(t_stack **b, int both)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *b;
	tmp1 = tmp->next->next;
	*b = (*b)->next;
	(*b)->next = tmp;
	(*b)->next->next = tmp1;
	if (both)
		ft_putendl_fd("sa", 1);
}

void	rb(t_stack **b, int both)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *b;
	tmp1 = *b;
	*b = (*b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp1;
	tmp->next->next = NULL;
	if (both)
		ft_putendl_fd("rb", 1);
}

void	rrb(t_stack **b, int both)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *b;
	tmp1 = tmp;
	while (tmp->next->next)
		tmp = tmp->next;
	*b = tmp->next;
	tmp->next = NULL;
	(*b)->next = tmp1;
	if (both)
		ft_putendl_fd("rrb", 1);
}
