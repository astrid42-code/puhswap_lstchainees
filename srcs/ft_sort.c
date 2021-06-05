/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/05 18:34:53 by asgaulti         ###   ########.fr       */
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

void    ft_sort_chunk(int i, t_stack **a, t_stack **b)
{
    t_stack *tmp1;
    t_stack *tmp2;
    int     count_up;
    int     count_down;
    (void)b;
    (void)i;

    count_up = 0;
    count_down = ft_stacksize(*a);
    tmp1 = *a;
    tmp2 = *a;
    while (tmp1->next)
        tmp1 = tmp1->next;
    //printf("tmp_a = %d  a = %d\n", tmp_a->el, (*a)->el);
    while ((*a)->index >= i && (*a)->index < i + 10)
    {
        if ((*a)->index < i + 10)
            break;
        a = (*a)->next;
        count_up++;
    }
    while (tmp_a->index >= i && tmp_a->index < i + 10)
    {
        if (tmp_a->index < i + 10)
            break;
        tmp_a = (tmp_a)->next;
        count_down--;
    }
    printf("i = %d cu = %d  cd = %d\n", i, count_up, count_down);
}