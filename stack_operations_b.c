/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:04 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 10:40:11 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **src, t_stack **dst)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	tmp_1 = *src;
	*src = (*src)->next;
	tmp_2 = *dst;
	*dst = tmp_1;
	(*dst)->next = tmp_2;
	ft_putendl_fd("pb", 1);
}

void	sb(t_stack **stack, int both)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		if (both)
			ft_putendl_fd("sb", 1);
	}
}

void	rb(t_stack **stack, int both)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		last = stack_last(*stack);
		last->next = first;
		first->next = NULL;
		*stack = second;
		if (both)
			ft_putendl_fd("rb", 1);
	}
}

void	rrb(t_stack **stack, int both)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		tmp->next = NULL;
		if (both)
			ft_putendl_fd("rrb", 1);
	}
}