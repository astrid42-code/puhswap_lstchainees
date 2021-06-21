/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_onehundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:42:12 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/21 15:56:54 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int index;
	t_stack *tmp_a;
	t_stack *tmp;

	chunk = 5;
	tmp = *a;
	index = 0;
	while (chunk != 0)
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			tmp_a = ft_find_best_pos(tmp, index);
			tmp = tmp_a;
	//printf("tmp = %d \n", tmp->el);
			ft_push_b(&tmp, b);
			size_chunk--;
		}
			// if (size_chunk == 0 && index != 0)
			// {
			// 	tmp_a = tmp;
			// 	//printf("tmp_a = %d imdex = %d\n", tmp_a->el, index);
			// 	while (tmp_a->index != 0)
			// 		ft_rev_rot_a(&tmp_a);
			// 	//printf("tmp_a = %d imdex = %d\n", tmp_a->el, index);
			// 	tmp = tmp_a;
			// }
		index += 20;
		chunk--;
	}
	
	ft_sort_b(index, b, &tmp);
	// FT_SORT_LAST:
	// size_chunk = 20;
	// while (size_chunk--)
	// 	ft_rotate_a(&tmp);
	*a = tmp;
}

t_stack	*ft_find_best_pos(t_stack *tmp_a, int index)
{
	int pos;
	int rev_pos;
	int count;
	int size;
	t_stack	*tmp;

	pos = 0;
	rev_pos = 0;
	count = 0;
	size = ft_stacksize(tmp_a);
	//printf("size = %d\n", size);
	tmp = tmp_a;
	while (!(tmp_a->index >= index && tmp_a->index < index + 20))
	{
		tmp_a = tmp_a->next;
		pos++;
		//count++;
	}
	//printf("tmp_a1 = %d pos = %d\n", tmp_a->el, pos);
	tmp_a = tmp;
	while (count != size)
	{
		if (tmp_a->index >= index && tmp_a->index < index + 20)
		{
			rev_pos = count;
	//printf("tmp_a2 = %d\n", tmp_a->el);
		}
		tmp_a = tmp_a->next;
		count++;
	}
	tmp_a = tmp;
	rev_pos = count - rev_pos;
	if (pos <= rev_pos)
	{
		while (pos != 0)
		{
			ft_rotate_a(&tmp_a);
			pos--;
		}
	}
	else
	{
		while (rev_pos > 0)
		{
			ft_rev_rot_a(&tmp_a);
			rev_pos--;
		}
	}
	//printf("tmp_a3 = %d\n", tmp_a->el);
	return (tmp_a);
}

void	ft_sort_b(int index, t_stack **b, t_stack **tmp_a)
{
	t_stack	*tmp_b;
	int count;
	int pos;
	int tmp;
	(void)index;

	count = 0;
	//tmp = index + 19;
	tmp = 99;
	tmp_b = *b;
	//while (tmp != index)
	while (tmp != 0)
	{
		pos = 0;
		tmp_b = *b;
		
		while (tmp_b->index != tmp)
		{
			tmp_b = tmp_b->next;
			pos++;
		}
		if (tmp_b->index == tmp)
		{
			if (pos <= ft_stacksize(*b) / 2)
			{
				while (pos != 0)
				{
					ft_rotate_b(b);
					pos--;
				}
			}
			else if (pos > ft_stacksize(*b) / 2)
			{
				while (pos < ft_stacksize(*b))
				{
					ft_rev_rot_b(b);
					pos++;
				}
			}
			ft_push_a(tmp_a, b);
			tmp--;
		}
	}
		ft_push_a(tmp_a, b);
}