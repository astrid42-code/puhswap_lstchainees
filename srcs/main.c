/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:50:06 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/27 11:10:47 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_arg(ac, av))
	{
		printf("Error\n");
		return (1); // (1 pour faux et non 0!!!)
	}
	if (!ft_create_lst(ac, av, &stack_a))
	{
		//puts("che");
		free_lst(stack_a);
		printf("Error\n");
		return (1);
	}
	ft_pushswap(&stack_a, &stack_b, ac);
	while (stack_a)
	{
		printf("a = %d\n", stack_a->el);
		stack_a = stack_a->next;
	}
//puts("che2");
	free_lst(stack_a);
	if (stack_b)
		free_lst(stack_b);
	puts("GG");
	return (0);
}
