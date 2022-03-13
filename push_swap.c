/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:21:46 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 12:13:59 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (ac > 2)
	{
		if (parse_arg(ac, av) == 0)
			error();
		stack_a = NULL;
		stack_b = NULL;
		init_stack(&stack_a, ac, av);
		if (is_sorted(stack_a))
			exit(EXIT_SUCCESS);
		i = stack_len(stack_a);
		if (i <= 5)
			sort5ex(&stack_a, &stack_b, i);
		else
			long_sort(&stack_a, &stack_b);
		print(stack_a);
		if (stack_a)
			stack_clear(stack_a);
		if (stack_b)
			stack_clear(stack_b);
	}
}
