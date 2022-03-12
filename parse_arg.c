/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:03:22 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/11 13:12:05 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_ifnum(int ac, char **av)
{
	size_t	j;
	int		i;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (j < ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_ifint(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	check_if_sorted(int ac, char **av)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < ac - 1)
	{
		if (atoi(av[i]) < atoi(av[i + 1]))
			cnt++;
		i++;
	}
	if (cnt == ac - 1)
		return (0);
	else
		return (1);
}

int	parse_arg(int ac, char **av)
{
	return (check_dup(ac, av) && check_ifint(ac, av) && check_ifnum(ac, av)
			&& check_if_sorted(ac, av));
}
