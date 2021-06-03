/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/03 18:16:24 by asgaulti         ###   ########.fr       */
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

void	ft_search_index(t_stack **a, int count)
{
	int tmp;
	int tmpind = 0;
	int minval = 0;
	int currcount = 0;
	t_stack	*tmp_a;
	//int count;

	//j = ft_stacksize(stack);
	//count = 0;
	//pos = 0;
	tmp = INT_MAX;
	tmp_a = *a;
	while (tmp_a)
	{
		tmp_a->index = 0;
		tmp_a = tmp_a->next;
	}
	tmp_a = *a;
	while (tmp_a && currcount <= count)
	{
		while (tmp_a)
		{
			//printf("tmp = %d\n", tmp);
			if (tmp == tmp_a->el && tmp > minval){
				tmpind++;
				tmp_a->index = tmpind;
				minval = tmp;
				tmp = INT_MAX;
				
				currcount++;
				printf("%d, %d, %d\n", tmp, minval, tmp_a->index);
			}
			
			if (tmp > (tmp_a)->el)
			{
				if (tmp == minval)
					tmp_a = (tmp_a)->next;
				tmp = (tmp_a)->el;
				printf("index = %d tmp = %d minval = %d\n", (tmp_a)->index, tmp, minval);	
			}
			tmp_a = (tmp_a)->next;
			//pos++;
		}
		tmp_a = *a;
	}
while (tmp_a)
	{
		printf("hello: %d  ind: %d\n", tmp_a->el, tmp_a->index);
		tmp_a = tmp_a->next;
	}	
	//printf("tmp = %d\nel = %d\npos = %d\n", tmp, stack->el, pos);
	// a = tmp_a;
	//return (a);
}