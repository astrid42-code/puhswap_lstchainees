/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/17 18:05:03 by asgaulti         ###   ########.fr       */
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
	t_stack	*tmp;

	lower = ft_lower_el(*a);
	index = 0;
	while (lower)
	{
		lower->index = index;
		//printf("low = %d\n", lower->index);
		lower = ft_lower_el(*a);
		index++;
	}
	tmp = *a;
	// while (tmp)
	// {
	// 	printf("el = %d index = %d\n", (tmp)->el, (tmp)->index);
	// 	tmp = (tmp)->next;
	// }
}

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int index;
	t_stack *tmp_a;
	t_stack *tmp;
	t_stack *tmp_b;

	chunk = 5;
	tmp = *a;
	index = 0;
//	while (chunk != 0)
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			tmp_a = ft_find_best_pos(tmp, index);
			tmp = tmp_a;
			ft_push_b(&tmp, b);
			size_chunk--;
		}
		printf("size = %d\n", size_chunk);
		//printf("el = %d index = %d\n", tmp->el, tmp->index);
		ft_sort_b(index, b, tmp);
		//*a = tmp;
		//tmp_b = *b;
		//printf("chunk = %d\n", chunk);
	}
	tmp_b = *b;
	tmp = *a;
/*	while (tmp_b)
	{
		ft_push_a(a, &tmp_b);
		(tmp_b) = (tmp_b)->next;
	}
*/	
}

t_stack	*ft_find_best_pos(t_stack *tmp_a, int index)
{
	int pos;
	int rev_pos;
	int count;
	int size;
	t_stack	*tmp;

	pos = 0;
	rev_pos = 50;
	count = 0;
	size = ft_stacksize(tmp_a);
	tmp = tmp_a;
	while (!(tmp_a->index >= index && tmp_a->index < index + 20) && count != size / 2)
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
		if (tmp_a->index >= index && tmp_a->index < index + 20)
		{
			rev_pos = count;
		}
		tmp_a = tmp_a->next;
		count++;
	}
	tmp_a = tmp;
	rev_pos = count - rev_pos;
	//printf("pos = %d  revpos = %d\n", pos, rev_pos);
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
	//printf("el = %d index = %d\n", tmp_a->el, tmp_a->index);
	return (tmp_a);
}

void	ft_sort_b(int index, t_stack **b, t_stack *tmp_a)
{
	t_stack	*tmp_b;
	int count;
	int pos;
	int tmp;

	count = 0;
	tmp = index + 20;
	while (b)
	{
		pos = 0;
		tmp_b = *b;
		
		while (tmp_b->index != tmp - 1)
		{
			tmp_b = tmp_b->next;
			pos++;
		}
		if (tmp_b->index == tmp - 1)
		{
		//printf("pos = %d tmp-index = %d index = %d\n", pos, tmp_b->index, tmp);
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
				while (pos < index - 1)
				{
					ft_rev_rot_b(b);
					pos++;
				}
			}
			ft_push_a(&tmp_a, b);
			tmp--;
		}
	}
	
}