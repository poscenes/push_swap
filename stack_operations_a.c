/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:04 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 10:40:05 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **src, t_stack **dst)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	tmp_1 = *src;
	*src = (*src)->next;
	tmp_2 = *dst;
	*dst = tmp_1;
	(*dst)->next = tmp_2;
	ft_putendl_fd("pa", 1);
}

void	sa(t_stack **stack, int both)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		if (both)
			ft_putendl_fd("sa", 1);
	}
}

void	ra(t_stack **stack, int both)
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
			ft_putendl_fd("ra", 1);
	}
}

void	rra(t_stack **stack, int both)
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
			ft_putendl_fd("rra", 1);
	}
}
