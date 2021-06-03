/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:39:26 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/03 16:08:59 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	// if (index == 1)
	// 	return (1); // ne pas comparer le premier nbr...
	while (stack_a)
	{
		//printf("nbr = %lld  el = %d \n", nbr, stack_a->el);
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
		//printf("av[%d] = %s\n", i, av[i]);
		//printf("i = %d\nac = %d\n", i, ac);
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
	
	while (stack_a) // ou stack_a->el different de null?
	{
		tmp = stack_a->next;
		//printf("stack_a = %d\n", stack_a->el);
		free(stack_a);
		//puts("che3");
		stack_a = tmp;
		//puts("che4");
	}
}

int	ft_search_min(t_stack *stack)
{
	int count;
	int tmp;
	int	pos;

	count = 0;
	//j = ft_stacksize(stack);
	//printf("j = %d\n", j);
	pos = 0;
	tmp = INT_MAX;
	//printf("tmp1 = %d\n", tmp);
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
	//printf("c = %d\np = %d\n", count, pos);
	//printf("tmp = %d\nel = %d\npos = %d\n", tmp, stack->el, pos);
	return (pos);
}

int	ft_is_sort(t_stack *stack)
{
	//printf("che\n");
	while (stack)
	{
		if (stack->el < stack->next->el)
			stack = stack->next;
		else if (stack->el > stack->next->el)
			return (1);
	}
	return (0);
}
 