/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:32:43 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/20 16:22:58 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !a)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	printf("pa\n");
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !b)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	printf("pb\n");
}
