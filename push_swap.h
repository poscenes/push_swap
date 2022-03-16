/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:22:19 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/16 19:45:39 by poscenes         ###   ########.fr       */
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
void		stack_add(t_stack **stack, t_stack *new_elem);
int			parse_arg(int ac, char **av);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a, int both);
void		sb(t_stack **b, int both);
void		ra(t_stack **a, int both);
void		rb(t_stack **b, int both);
void		rra(t_stack **stack, int both);
void		rrb(t_stack **stack, int both);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
int			compare(t_stack **s, int med, int i);
int			*make_arr_val(t_stack *s, int *arr);
int			*make_arr_ind(t_stack *s, int *arr);
int			find_ind(int *arr, int ind);
int			*arr_copy(int *arr_s, int *arr_d, int size);
int			*sort_arr(int *arr, int size);
int			*make_arr_val(t_stack *s, int *arr);
int			*make_arr_ind(t_stack *s, int *arr);
void		stack_index(t_stack **s, int size);
int			maxind(t_stack *stack);
int			minind(t_stack *stack);
int			is_sorted(t_stack *stack);
void		sort5ex(t_stack **stack_a, t_stack **stack_b, int size);
void		print(t_stack *stack);
void		init_stack(t_stack **stack_a, int ac, char **av);
void		stack_clear(t_stack *stack);
void		longsort(t_stack **a, t_stack **b, int size);

int			check_sa(t_stack **a);
int			check_sb(t_stack **b);
int			check_ss(t_stack **a, t_stack **b);
int			check_rr(t_stack **a, t_stack **b);
int			check_rb(t_stack **b);
int			check_ra(t_stack **a);
int			check_rrr(t_stack **a, t_stack **b);
int			check_rrb(t_stack **b);
int			check_rra(t_stack **a);
int			check_pa(t_stack **a, t_stack **b);
int			check_pb(t_stack **a, t_stack **b);

#endif
