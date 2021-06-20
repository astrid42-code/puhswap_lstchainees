/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:39:26 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/20 13:47:13 by asgaulti         ###   ########.fr       */
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

int	ft_check_doublon(long long nbr, t_stack *stack_a)
{
	while (stack_a)
	{
		if (nbr == stack_a->el)
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
	if (ac < 2)
		return (1);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!((av[i][j] >= 48 && av[i][j] <= 57) || av[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		free_lst(t_stack *stack_a)
{
	t_stack	*tmp;
	
	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
}

int	ft_search_min(t_stack *stack)
{
	int count;
	int tmp;
	int	pos;

	count = 0;
	pos = 0;
	tmp = INT_MAX;
	while (stack)
	{
		if (tmp >= stack->el)
		{	
			tmp = stack->el;
			pos = count;
		}
		count++;	
		stack = stack->next;
	}
	return (pos);
}
/*
int	ft_is_sort(t_stack *stack)
{
	t_stack	*tmp;
	tmp = stack;
	while (tmp)
	{
		if (tmp->el < tmp->next->el)
			tmp = tmp->next;
		else if (tmp->el > tmp->next->el)
			return (1);
	}
	return (0);
}
 */