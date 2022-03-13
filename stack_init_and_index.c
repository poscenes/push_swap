/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_and_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:29:21 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 11:47:55 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		stack_add_back(stack_a, stack_new(ft_atoi(av[i])));
		i++;
	}
}

int	*index_arr(t_stack *stack, int *arr)
{
	int	i;

	if (!stack || !arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->index;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	find_index(int elem, int *sort)
{
	int	i;

	i = 0;
	while (sort[i] != elem)
		i++;
	return (i);
}

void	index_stack(t_stack	**stack)
{
	int		*arr_sort;
	int		*arr_nosort;
	int		i;
	t_stack	*tmp;

	arr_sort = make_arr(*stack);
	arr_nosort = sort_arr(*stack);
	tmp = *stack;
	i = 0;
	while (*stack)
	{
		(*stack)->index = find_index(arr_nosort[i], arr_sort);
		*stack = (*stack)->next;
		i++;
	}
	free(arr_nosort);
	free(arr_sort);
	*stack = tmp;
}

int	max_index(t_stack **stack)
{
	int		ind;
	t_stack	*tmp;

	ind = (*stack)->index;
	while (*stack)
	{
		if (ind < (*stack)->index)
			ind = (*stack)->index;
		*stack = (*stack)->next;
	}
	*stack = tmp;
	return (ind);
}
