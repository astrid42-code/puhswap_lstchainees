/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/11 14:19:11 by asgaulti         ###   ########.fr       */
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

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int pos;
	int index;
	t_stack *tmp_a;
	t_stack *tmp;
	t_stack *tmp_b;

	chunk = 5;
	tmp = *a;
	index = 0;
	while (chunk != 0)
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			tmp_a = tmp;
			//printf("tmp_a = %d  tmp = %d\n", tmp_a->el, tmp->el);
			pos = 0;
			while (!(tmp_a->index >= index && tmp_a->index < index + 20))
			{
				tmp_a = tmp_a->next;
				pos++;
			}
			if (tmp_a->index >= index && tmp_a->index < index + 20)
			{
				if (pos == 0)
				{
					ft_push_b(&tmp, b);
					//ft_sort_b(b);
					size_chunk--;
				}
				else
				{
					ft_rotate_a(&tmp);
				}
			}
		}
		tmp_b = *b;
	/*	while (tmp_b)
		{
			printf("tmp_b = %d\n", tmp_b->el);
			tmp_b = tmp_b->next;
		}
	*/	index += 20;	
		chunk--;
		printf("chunk = %d\n", chunk);
	}
}



/*

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int		i;
	int		chunk;
	int		size_chunk;
	int		pos;
	t_stack	*tmp_a;
	t_stack *tmp;

	tmp_a = *a;
	chunk = 5;
	i = 0;
	pos = 0;
	while (chunk != 0) // tq j'ai des chunks
	{
		tmp = tmp_a;
		size_chunk = 20;
		while (size_chunk != 0)
		{
			// pb : pos tjrs = a 0!!
		//printf("pos = %d\n", pos);
			if (tmp_a->index > i + 20)
			{
				tmp_a = tmp_a->next;
				pos++;
				printf("el = %d index = %d pos = %d\n", tmp_a->el, tmp_a->index, pos);
			}
			else if ((tmp_a->index >= i && tmp_a->index < i + 20) && pos != 0)
			{
			//pos = ft_pos_index(tmp, i);
				while (pos != 0)
				{	
					ft_rotate_a(&tmp);
				printf("pos = %d el_a = %d\n", pos, tmp_a->el);
			printf("tmp = %d tmp_a = %d\n", tmp->el, tmp_a->el);
					pos--;
					//pos = ft_pos_index(tmp, i);
				}
			}
			if (pos == 0 && (tmp_a->index >= i && tmp_a->index < i + 20))
			{
					ft_push_b(&tmp_a, b);
					printf("b = %d\n", (*b)->el);
					//ft_sort_b();
					size_chunk--;
			}
				//printf("index = %d  pos = %d el = %d\n", tmp_a->index, pos, tmp_a->el);
				if (size_chunk == 0)
				{
					while ((*b)->next != NULL)
					{
						ft_push_a(&tmp_a, b);
					}
					size_chunk = 20;
					while (size_chunk != 0)
					{
						ft_rev_rot_a(&tmp_a);
						size_chunk--;
						printf("el_a = %d\n", tmp_a->el);
				//printf("size_chunk =%d\n", size_chunk);
					}
				}
		}
		i += 20;
		chunk--;
		tmp_a = tmp;
	}
}
*/
	// chunk = ft_stacksize(*a) % 10;
	// if (chunk != 0)
	// {
	// 	while (chunk != 0)
	// 	{
	// 		ft_push_b(a, b);
	// 		//ft_sort_b();
	// 		chunk--;
	// 	/*	if (chunk == 0)
	// 		{
	// 			while (b)
	// 				ft_push_a(a, b);
	// 			chunk = ft_stacksize(a) % 10;
	// 			while (chunk != 0)
	// 			{
	// 				ft_rotate_a(a);
	// 				chunk--;
	// 			}
	// 		}*/
	// 	}
	// }

