/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:22:19 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/11 13:01:06 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack	t_stack;

struct s_stack
{
	int		value;
	int		score_a_r;
	int		score_a_rr;
	int		score_b_r;
	int		score_b_rr;
	t_stack	*next;
};

void		error(void);
long long	ft_atol(const char *str);
t_stack		*stack_new(int value);
int			stack_len(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
void		stack_add_back(t_stack **stack, t_stack *new);
t_stack		*stack_min(t_stack *stack);
int			parse_arg(int ac, char **av);

#endif
