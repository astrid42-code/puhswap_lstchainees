/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:50:06 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/22 18:49:11 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack **a)
{
	t_stack	*tmp;
	
	tmp = *a;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->el > tmp->next->el)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
 
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (ft_check_arg(ac, av))
	{
		printf("Error\n");
		return (1);
	}
	if (!ft_create_lst(ac, av, &stack_a))
	{
		free_lst(stack_a, stack_b);
		printf("Error\n");
		return (1);
	}
	if (ft_is_sorted(&stack_a) == 0)
	{
		free_lst(stack_a, stack_b);
		return (0);
	}
	ft_pushswap(&stack_a, &stack_b, ac);
	free_lst(stack_a, stack_b);
	return (0);
}
