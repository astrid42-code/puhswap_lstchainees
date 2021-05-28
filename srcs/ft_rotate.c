/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:33:58 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/28 18:07:00 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack *new;
	
	tmp = *a; 
	//printf("tmp_el = %d\n", tmp->el);
	new = *a;
	//puts("che");
	while (new->next)
	{	new = new->next;
		//printf("new_el = %d\n", new->el);
	}
	new->next = tmp; // tmp etant le 1er el
	*a = (*a)->next;
	tmp->next = NULL;
/*	tmp = *a;
	while (tmp)
	{
			printf("A = %d\n", tmp->el);
		tmp = tmp->next;
	}
*/	printf("ra\n");
	//return (tmp);
}

void	ft_rotate_b(t_stack **b)
{
    t_stack	*tmp;
	t_stack *new;
	
	tmp = *b; 
	printf("tmp_el = %d\n", tmp->el);
	new = *b;
	while (new->next)
	{	new = new->next;
		printf("new_el = %d\n", new->el);
	}
	new->next = tmp; // tmp etant le 1er el
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
	{	new_a = new_a->next;
	printf("tmp_el = %d\n", tmp_a->el);
	}
	new_a->next = tmp_a;
	*a = (*a)->next;
	tmp_a->next = NULL;
	tmp_b = *b; 
	printf("tmp_el = %d\n", tmp_b->el);
	new_b = *b;
	while (new_b)
		new_b = new_b->next;
	new_b->next = tmp_b;
	*b = (*b)->next;
	tmp_b->next = NULL;	
	printf("rr\n");
}