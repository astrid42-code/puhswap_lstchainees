/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/02 17:52:42 by asgaulti@st      ###   ########.fr       */
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

void	ft_search_index(t_stack *a, int count)
{
	int tmp;
	int	pos;
	//int count;

	//j = ft_stacksize(stack);
	//count = 0;
	pos = 0;
	tmp = INT_MAX;
	a->index = 0;
	//printf("tmp1 = %d\n", tmp);
	while (a->index != count)
	{
		while (a)
		{
			if (tmp >= a->el)
			{	
				tmp = a->el;
				//a->index = pos;
			}
			a = a->next;
			//pos++;
		//puts("che");
		
		}
		a->index++;
		//pos++;
		printf("index = %d pos= %d tmp = %d\n", a->index, pos, tmp);	
	}
	printf("pos= %d  a->el = %d\n", pos, a->el);
	//printf("tmp = %d\nel = %d\npos = %d\n", tmp, stack->el, pos);
	//return (a);
}