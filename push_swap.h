/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:22:19 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/13 12:12:35 by poscenes         ###   ########.fr       */
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
	int		index;
	t_stack	*next;
};

void		error(void);
long long	ft_atol(const char *str);
t_stack		*stack_new(int value);
int			stack_len(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
void		stack_add_back(t_stack **stack, t_stack *new);
int			parse_arg(int ac, char **av);
void		pa(t_stack **src, t_stack **dst);
void		pb(t_stack **src, t_stack **dst);
void		sa(t_stack **stack, int both);
void		sb(t_stack **stack, int both);
void		ra(t_stack **stack, int both);
void		rb(t_stack **stack, int both);
void		rra(t_stack **stack, int both);
void		rrb(t_stack **stack, int both);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
int			*make_arr(t_stack *stack);
int			*sort_arr(t_stack *stack);
int			*index_arr(t_stack *stack, int *arr);
int			max_index(t_stack **stack);
int			compare(t_stack **stack, int med, int size);
int			func_max(t_stack *stack);
int			func_min(t_stack *stack);
int			is_sorted(t_stack *stack);
void		sort5ex(t_stack **stack_a, t_stack **stack_b, int size);
void		print(t_stack *stack);
void		long_sort(t_stack **stack_a, t_stack **stack_b);
void		init_stack(t_stack **stack_a, int ac, char **av);
void		stack_clear(t_stack *stack);
void		index_stack(t_stack	**stack);
void		sort_3(t_stack **stack);

#endif
