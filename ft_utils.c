/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:39:26 by asgaulti          #+#    #+#             */
/*   Updated: 2021/05/23 20:24:55 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_check_doublon(long long nbr, int index, t_stack *stack_a)
{
	// if (index == 1)
	// 	return (1); // ne pas comparer le premier nbr...
	while (stack_a)
	{
		//printf("nbr = %lld  el = %d \n", nbr, stack_a->element);
		if (nbr == stack_a->element)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_check_arg(int ac, char **av)
{
	int i;
	int	j;

	i = 1;
	if (ac <= 2)
		return (1);
	while (i < ac)
	{
		//printf("av[%d] = %s\n", i, av[i]);
		//printf("i = %d\nac = %d\n", i, ac);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		free_lst(t_stack *stack_a)
{
	while (stack_a) // ou stack_a->element different de null?
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
}