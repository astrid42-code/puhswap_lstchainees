/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/01 14:27:06 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	ft_search_index(t_stack **a, int count)
{
	int tmp;
	int	pos;

	//j = ft_stacksize(stack);
	//printf("j = %d\n", j);
	pos = 0;
	tmp = INT_MAX;
	//printf("tmp1 = %d\n", tmp);
	while (a->index != count)
	{
		while (a)
		{
			if (a->el < a->next->el)
			{	
				a->index = pos;
			}
			a = a->next;
		}
		pos++;	
	}
	//printf("c = %d\np = %d\n", count, pos);
	//printf("tmp = %d\nel = %d\npos = %d\n", tmp, stack->el, pos);
	//return (a);
}