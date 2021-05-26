/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:32:43 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/26 16:13:11 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	
	if (!b)
		return ;
	tmp = *a;
	*a = *b;
	a->next = tmp;
	printf("pa\n");
}

void ft_push_b(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	
    if (!a)
        return ;
	tmp = *b;
	*b = *a;
	b->next = tmp;
    printf("pb\n");
}
