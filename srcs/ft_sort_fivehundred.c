/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_fivehundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:42:00 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/21 13:59:16 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_chunk_fivehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int index;
	t_stack *tmp_a;
	t_stack *tmp;

	chunk = 10;
	tmp = *a;
	index = 0;
    // size_chunk = 50;
    // while (size_chunk != 0)
	// {
	// 	tmp_a = ft_find_best_pos2(tmp, index);
	// 	tmp = tmp_a;
	// 	ft_push_b(&tmp, b);
	// 	size_chunk--;
	// 	if (size_chunk == 0 && index != 0)
	// 	{
	// 		tmp_a = tmp;
	// 		while (tmp_a->index != 0)
	// 			ft_rev_rot_a(&tmp_a);
	// 		tmp = tmp_a;
    //     }
	// }
	//ft_sort_b2(index, b, &tmp);
	while (chunk != 0)
	{
		size_chunk = 50;
		while (size_chunk != 0)
		{
			tmp_a = ft_find_best_pos2(tmp, index);
			tmp = tmp_a;
			ft_push_b(&tmp, b);
			size_chunk--;
			// if (size_chunk == 0 && index != 0)
			// {
			// 	tmp_a = tmp;
			// 	while (tmp_a->index != 0)
			// 	{
			// 		ft_rev_rot_a(&tmp_a);
			// 	}
			// 	tmp = tmp_a;
			// }
		}
		chunk--;
		index += 50;		
	}
		ft_sort_b2(index, b, &tmp);
	
	// FT_SORT_LAST:
	// size_chunk = 50;
	// while (size_chunk)
	// {
	// 	ft_rotate_a(&tmp);
	// 	size_chunk--;
	// }
	*a = tmp;
}

t_stack	*ft_find_best_pos3(t_stack *tmp_a, int index)
{
	int pos;
	int rev_pos;
	int count;
	int size;
	t_stack	*tmp;

	pos = 0;
	rev_pos = 250;
	count = 0;
	size = ft_stacksize(tmp_a);
	tmp = tmp_a;
	while (!(tmp_a->index >= index && tmp_a->index < index + 45) && count != size / 2)
	{
		tmp_a = tmp_a->next;
		pos++;
		count++;
	}
	while (count != size / 2)
	{
		tmp_a = tmp_a->next;
		count++;
	}	
	while (count != size)
	{
		if (tmp_a->index >= index && tmp_a->index < index + 45)
		{
			rev_pos = count;
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
	return (tmp_a);
}

void	ft_sort_b3(int index, t_stack **b, t_stack **tmp_a)
{
	t_stack	*tmp_b;
	int count;
	int pos;
	int tmp;

	count = 0;
	tmp = index + 44;
	tmp_b = *b;
	while (tmp != index)
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