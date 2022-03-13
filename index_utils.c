/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:40:22 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 10:29:56 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr(t_stack *stack)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * stack_len(stack));
	if (!arr)
	{
		stack_clear(stack);
		error();
	}
	i = 0;
	while (stack && i < stack_len(stack))
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

int	*sort_int_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*sort_arr(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack_len(stack);
	return (sort_int_arr(make_arr(stack), size));
}

int	compare(t_stack **stack, int med, int size)
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * (size + 1));
	if (!arr)
		return (0);
	arr = index_arr(*stack, arr);
	i = size;
	while (arr[size] != med)
		size--;
	i = i - size;
	size = 0;
	while (arr[size] != med)
		size++;
	free(arr);
	if (i < size)
		return (1);
	return (0);
}
