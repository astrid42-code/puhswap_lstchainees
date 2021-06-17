/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/16 21:27:11 by astridgault      ###   ########.fr       */
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

void	ft_sort_b(t_stack **b)
{
	t_stack *tmp_b;
	int	pos;
//	int	count;
	int middle;
//	int index;
	
	pos = 1;
	tmp_b = *b;
	middle = ft_stacksize(tmp_b) / 2;
		// while (tmp_b)
		// {
		// 	//printf("tmp_b = %d\n", tmp_b->el);
		// 	tmp_b = tmp_b->next;
		// }
		// tmp_b = *b;
	//printf("size = %d\n", ft_stacksize(tmp_b));
	if (ft_stacksize(tmp_b) == 1)
		return ;
	if (ft_stacksize(tmp_b) == 2)
	{
		//printf("el = %d  index = %d el->next = %d  index->next = %d\n", tmp_b->el, tmp_b->index, tmp_b->next->el, tmp_b->next->index);
		if ((tmp_b)->el < (tmp_b)->next->el)
    	{
        	ft_swap_b(tmp_b);
        	//return ;
    	}
		//printf("el = %d  index = %d el->next = %d  index->next = %d\n", tmp_b->el, tmp_b->index, tmp_b->next->el, tmp_b->next->index);
    	// else 
        // 	return ;
	}
	*b = tmp_b;
		while (tmp_b)
		{
			printf("tmp_b = %d\n", tmp_b->el);
			tmp_b = tmp_b->next;
		}
	return ;
}

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int index;
	int el;
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
			el = tmp_a->index;
			if (b && ft_stacksize(*b) >= 2)
			{	ft_prepare_b(el, b);
		printf("el = %d index = %d \n", tmp->el, tmp->index);
			ft_push_b(&tmp, b);
			}
			else
			{
				ft_push_b(&tmp, b);
			ft_sort_b(b);
			}
		tmp_b = *b;
		while (tmp_b)
		{
			printf("tmp_b = %d\n", tmp_b->el);
		 	tmp_b = tmp_b->next;
		}
			size_chunk--;
		}
		*a = tmp;
		index += 20;	
		chunk--;
		//printf("chunk = %d\n", chunk);
	}
	tmp_b = *b;
	tmp = *a;
	while (tmp_b)
	{
		ft_push_a(a, &tmp_b);
		(tmp_b) = (tmp_b)->next;
	}
	
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
			//printf("el = %d index = %d revpos = %d\n", tmp_a->el, tmp_a->index, rev_pos);
		}
	}
	return (tmp_a);
}

void	ft_prepare_b(int index, t_stack **b)
{
	t_stack *tmp_b;
	
	tmp_b = *b;
	while (tmp_b && tmp_b->next != NULL)
	{
		if (tmp_b->index > index && tmp_b->index < tmp_b->next->index)
			ft_rotate_b(&tmp_b);
		tmp_b = tmp_b->next;
		printf("index = %d tmp_indx = %d \n", index, tmp_b->index);
	}
	*b = tmp_b;
}