/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:04 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/11 14:21:36 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp_1;
	t_stack *tmp_2;

	tmp_1 = *src;
	*src = (*src)->next;
	tmp_2 = *dst;
	*dst = tmp_1;
	(*dst)->next = tmp_2;
}

void	swap(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		
	}
}
