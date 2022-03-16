/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:45:31 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 15:03:33 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr_ind(t_stack *s, int *arr)
{
	int	i;

	i = 0;
	if (!s || !arr)
		return (0);
	while (s)
	{
		arr[i] = s->index;
		s = s->next;
		i++;
	}
	return (arr);
}

int	*make_arr_val(t_stack *s, int *arr)
{
	int	i;

	i = 0;
	if (!s || !arr)
		return (0);
	while (s)
	{
		arr[i] = s->value;
		s = s->next;
		i++;
	}
	return (arr);
}

int	*sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!arr || !size)
		return (NULL);
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

int	*arr_copy(int *arr_s, int *arr_d, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr_d[i] = arr_s[i];
		i++;
	}
	return (arr_d);
}

int	find_ind(int *arr, int ind)
{
	int	i;

	i = 0;
	while (arr[i] != ind)
		i++;
	return (i);
}
