/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/18 17:42:17 by asgaulti         ###   ########.fr       */
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
	//  while (tmp)
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
	// while(tmp)
	// {
	// 	printf("tmpb-el = %d tmpb-index = %d\n", tmp->el, tmp->index);
	//  	tmp = tmp->next;
	// }
	// tmp = *a;
	while (chunk != 0)
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			tmp_a = ft_find_best_pos(tmp, index);
		//printf("el = %d index = %d\n", tmp_a->el, tmp_a->index);
			tmp = tmp_a;
			ft_push_b(&tmp, b);
			size_chunk--;
		}
		ft_sort_b(index, b, &tmp);
		chunk--;
		index += 20;
		//*a = tmp;
		//tmp_b = *b;
		//printf("chunk = %d\n", chunk);
		tmp_b = tmp;
		while (tmp_b)
		{
			printf("tmp = %d\n", tmp_b->el);
		 	tmp_b = tmp_b->next;
		}	
	 }
	//  size_chunk = 20;
	//  while (size_chunk)
	//  {
	// 	 ft_rotate_a(&tmp);
	// 	 tmp = tmp->next;
	// 	 size_chunk--;
	//  }
	// *a = tmp;
	// while (tmp)
	// 	{
	// 		printf("tmp = %d\n", tmp->el);
	// 	 	tmp = tmp->next;
	// 	}	
		//printf("c = %d\n", chunk);
	//tmp_b = *b;
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

void	ft_sort_b(int index, t_stack **b, t_stack **tmp_a)
{
	t_stack	*tmp_b;
	int count;
	int pos;
	int tmp;

	count = 0;
	tmp = index + 19;
	//printf("index = %d\n", index);
	tmp_b = *b;
	// while (tmp_b)
	// {
	// 	printf("tmpb-el = %d tmpb-index = %d\n", tmp_b->el, tmp_b->index);
	// 	tmp_b = tmp_b->next;
	// }
	while (tmp != index)
	{
		pos = 0;
		tmp_b = *b;
		
		while (tmp_b->index != tmp)
		{
			tmp_b = tmp_b->next;
			pos++;
		}
		//printf("pos = %d tmp-index = %d tmp-el = %d\n", pos, tmp_b->index, tmp_b->el);
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
					//printf("b-el1 = %d b-index = %d\n", (*b)->el, (*b)->index);
					ft_rev_rot_b(b);
			//printf("b-el2 = %d b-index = %d\n", (*b)->el, (*b)->index);
					pos++;
				}
			}
			//printf("b-el3 = %d b-index = %d pos = %d tmp+1 = %d\n", (*b)->el, (*b)->index, pos, tmp + 1);
			ft_push_a(tmp_a, b);
			tmp--;
		}
	}
		//printf("b-el2 = %d tmp = %d\n", (*b)->el, tmp);
		ft_push_a(tmp_a, b);
}