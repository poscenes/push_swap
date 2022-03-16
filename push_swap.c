/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:21:46 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 20:37:24 by poscenes         ###   ########.fr       */
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
		i = stack_len(stack_a);
		stack_index(&stack_a, i);
		if (!is_sorted(stack_a))
			exit(EXIT_SUCCESS);
		if (i <= 5)
			sort5ex(&stack_a, &stack_b, i);
		else
			longsort(&stack_a, &stack_b, i);
		if (stack_a)
			stack_clear(stack_a);
		if (stack_b)
			stack_clear(stack_b);
	}
}
