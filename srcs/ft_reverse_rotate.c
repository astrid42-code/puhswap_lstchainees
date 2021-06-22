/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:35:51 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/20 16:49:03 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rot_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = *a;
	new = *a;
	while (new->next->next)
		new = new->next;
	new->next->next = tmp;
	tmp = new->next;
	new->next = NULL;
	*a = tmp;
	printf("rra\n");
}

void	ft_rev_rot_b(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = *b;
	new = *b;
	while (new->next->next)
		new = new->next;
	new->next->next = tmp;
	tmp = new->next;
	new->next = NULL;
	*b = tmp;
	tmp = *b;
	printf("rrb\n");
}

void	ft_rev_rot_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*new_a;
	t_stack	*tmp_b;
	t_stack	*new_b;

	tmp_a = *a;
	new_a = *a;
	while (new_a->next->next)
		new_a = new_a->next;
	new_a->next->next = tmp_a;
	tmp_a = new_a->next;
	new_a->next = NULL;
	*a = tmp_a;
	tmp_a = *a;
	tmp_b = *b;
	new_b = *b;
	while (new_b->next->next)
		new_b = new_b->next;
	new_b->next->next = tmp_b;
	tmp_b = new_b->next;
	new_b->next = NULL;
	*b = tmp_b;
	tmp_b = *b;
	printf("rrr\n");
}
