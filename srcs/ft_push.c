/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:32:43 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/26 17:53:49 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	
	if (!b || !a)
		return ;
	tmp = *a;
	*a = *b; // faire pter b sur le 1er el de a
	*b = (*b)->next; // dans b, faire demarrer la liste sur l'el suivant celui qu'on a retire
	(*a)->next = tmp; // le 1er el de a (le 1er de b qu'on a mis comme debut) pointe sur l'ancien 1erel de a qu'on avait stocke dans tmp
	printf("pa\n");
}

void ft_push_b(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	
    if (!a || !b)
        return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
    printf("pb\n");
}
