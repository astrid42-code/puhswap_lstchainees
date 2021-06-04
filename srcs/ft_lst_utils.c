/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/04 17:07:45 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
void	ft_lstadd_front_stack(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if (*stack == 0)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_lstadd_back_stack(t_stack **stack, t_stack *new)
{
	t_stack *last;

	last = *stack;
	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
*/
int	ft_stacksize(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
