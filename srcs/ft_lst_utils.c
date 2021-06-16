/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/15 15:23:50 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
/*
int	ft_pos_index(t_stack *a, int i)
{
	int pos;

	pos = 0;
	//printf("el = %d\n", a->el);
	while (!(a->index >= i && a->index < i + 20))
	{
	//printf("index = %d\n", a->index);
		a = a->next;
		pos++;
	}
	//printf("pos = %d\n", pos);
	return (pos);
}*/