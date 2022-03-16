/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_and_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:29:21 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 17:51:35 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int ac, char **av)
{
	while (ac != 1)
	{
		stack_add(stack_a, stack_new(ft_atoi(av[ac - 1])));
		ac--;
	}
}

void	stack_index(t_stack **s, int size)
{
	t_stack		*tmp;
	int			k;
	int			*arr;
	int			*arr1;

	k = 0;
	tmp = *s;
	arr = malloc(sizeof(int) * (size + 1));
	arr1 = malloc(sizeof(int) * (size + 1));
	if (!arr || !arr1)
		return ;
	arr = make_arr_val(tmp, arr);
	arr1 = arr_copy(arr, arr1, size);
	arr = sort_arr(arr, size);
	while (tmp)
	{
		tmp->index = find_ind(arr, arr1[k]);
		tmp = tmp->next;
		k++;
	}
	free(arr);
	free(arr1);
}

int	compare(t_stack **s, int index, int i)
{
	int		k;
	int		*arr;

	arr = malloc(sizeof(int) * (i + 1));
	if (!arr)
		return (0);
	arr = make_arr_ind(*s, arr);
	k = i;
	while (arr[i] != index)
		i--;
	k = k - i;
	i = 0;
	while (arr[i] != index)
		i++;
	free(arr);
	if (k < i)
		return (1);
	return (0);
}
