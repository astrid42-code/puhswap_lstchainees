/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/07 19:04:10 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*ft_lower_el(t_stack *lower)
{
	t_stack	*min;

	min = NULL;
	while (lower)
	{
		if ((!min && lower->index == -1) || (min && min->el > lower->el
				&& lower->index == -1))
			min = lower; // min = maillon le + petit
		lower = lower->next;
	}
	return (min);
}

void	ft_create_index(t_stack **a)
{
	t_stack	*lower;
	int		index;
//	t_stack	*tmp;

	lower = ft_lower_el(*a);
	index = 0;
	while (lower)
	{
		lower->index = index;
		//printf("low = %d\n", lower->index);
		lower = ft_lower_el(*a);
		index++;
	}
/*	tmp = *a;
	while (tmp)
	{
		printf("el = %d index = %d\n", (tmp)->el, (tmp)->index);
		tmp = (tmp)->next;
	}*/
}
/*
void    ft_sort(t_stack **a, t_stack **b, int count)
{
	int i;
	int chunk;

	i = 0;
	chunk = 0;
	while (chunk < count)
	{
		chunk = (count / 10);
		ft_sort_chunk(i, a, b);
		//	printf("ch = %d\n", chunk);
		i += 10;
    }
    if (count != 0)
    {
        chunk = count + 1;
        ft_sort_chunk(i, a, b);
    }
}
*/
void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int		i;
	int		chunk;
	int		size_chunk;
	int		pos;
	t_stack	*tmp_a;

	tmp_a = *a;
	chunk = 5;
	i = 0;
	while (chunk != 0) // tq j'ai des chunks
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			//printf("size = %d\n", size_chunk);
			// pb : pos tjrs = a 0!!
			if (tmp_a->index >= i && tmp_a->index < i + 20)
			{
				pos = ft_pos_index(tmp_a, i);
				printf("index = %d  pos = %d el = %d\n", tmp_a->index, pos, tmp_a->el);
				while (pos != 0)
				{	
					ft_rotate_a(&tmp_a);
					pos = ft_pos_index(tmp_a, i);
				}
				if (pos == 0)
				{
					ft_push_b(&tmp_a, b);
					//ft_sort_b();
					size_chunk--;
				}
			/*	if (size_chunk == 0)
				{
					while (b)
						ft_push_a(a, b);
					size_chunk = ft_sizeofchunk();
					while (size_chunk != 0)
					{
						ft_rotate_a(a);
						size_chunk--;
					}
				}
			*/
			}
			else
			{
				tmp_a = tmp_a->next;
			}
		}
		i += 20;
		chunk--;
	}
	chunk = ft_stacksize(*a) % 10;
	if (chunk != 0)
	{
		while (chunk != 0)
		{
			ft_push_b(a, b);
			//ft_sort_b();
			chunk--;
		/*	if (chunk == 0)
			{
				while (b)
					ft_push_a(a, b);
				chunk = ft_stacksize(a) % 10;
				while (chunk != 0)
				{
					ft_rotate_a(a);
					chunk--;
				}
			}*/
		}
	}
}
