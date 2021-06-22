/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_fivehundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:42:00 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/21 17:17:02 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_chunk_fivehundred(t_stack **a, t_stack **b)
{
	int		chunk;
	int		size_chunk;
	int		index;
	t_stack	*tmp_a;
	t_stack	*tmp;

	chunk = 10;
	tmp = *a;
	index = 0;
	while (chunk != 0)
	{
		size_chunk = 50;
		while (size_chunk != 0)
		{
			tmp_a = ft_find_best_pos2(tmp, index);
			tmp = tmp_a;
			ft_push_b(&tmp, b);
			size_chunk--;
		}
		chunk--;
		index += 50;
	}
	ft_sort_b2(b, &tmp);
	*a = tmp;
}

t_stack	*ft_find_best_pos2(t_stack *tmp_a, int index)
{
	int		pos;
	int		rev_pos;
	int		count;
	t_stack	*tmp;

	pos = 0;
	rev_pos = 0;
	count = 0;
	tmp = tmp_a;
	while (!(tmp_a->index >= index && tmp_a->index < index + 50))
	{
		tmp_a = tmp_a->next;
		pos++;
	}
	tmp_a = tmp;
	while (count++ != ft_stacksize(tmp))
	{
		if (tmp_a->index >= index && tmp_a->index < index + 50)
			rev_pos = count;
		tmp_a = tmp_a->next;
	}
	tmp_a = tmp;
	rev_pos = count - rev_pos;
	tmp_a = ft_pos(pos, rev_pos, tmp_a);
	return (tmp_a);
}

void	ft_sort_b2(t_stack **b, t_stack **tmp_a)
{
	t_stack	*tmp_b;
	int		count;
	int		pos;
	int		tmp;

	count = 0;
	tmp = 499;
	tmp_b = *b;
	while (tmp != 0)
	{
		pos = 0;
		tmp_b = *b;
		while (tmp_b->index != tmp)
		{
			tmp_b = tmp_b->next;
			pos++;
		}
		if (tmp_b->index == tmp--)
		{
			ft_pos_sort_b(pos, b);
			ft_push_a(tmp_a, b);
		}
	}
	ft_push_a(tmp_a, b);
}
