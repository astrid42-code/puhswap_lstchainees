/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:33:58 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/19 18:51:08 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack *new;
	
	tmp = *a; 
	new = *a;
	while (new->next)
		new = new->next;
	new->next = tmp;
	*a = (*a)->next;
	tmp->next = NULL;
	tmp = *a;
	printf("ra\n");
}

void	ft_rotate_b(t_stack **b)
{
    t_stack	*tmp;
	t_stack *new;
	
	tmp = *b; 
	new = *b;
	while (new->next)
		new = new->next;
	new->next = tmp;
	*b = (*b)->next;
	tmp->next = NULL;	
	printf("rb\n");
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
    t_stack	*tmp_a;
	t_stack *new_a;
	t_stack	*tmp_b;
	t_stack *new_b;
	
	tmp_a = *a; 
	new_a = *a;
	while (new_a)
		new_a = new_a->next;
	new_a->next = tmp_a;
	*a = (*a)->next;
	tmp_a->next = NULL;
	tmp_b = *b; 
	new_b = *b;
	while (new_b)
		new_b = new_b->next;
	new_b->next = tmp_b;
	*b = (*b)->next;
	tmp_b->next = NULL;	
	printf("rr\n");
}