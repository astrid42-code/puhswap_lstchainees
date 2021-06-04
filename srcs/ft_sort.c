/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:56 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/04 19:30:16 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
void	ft_sort(t_stack **a, t_stack **b, int count)
{
	(void)b;
	

	copy_a = 
	//lecture et attribution index :
	ft_search_index(a, count);
}

void    ft_search_index(t_stack **a, int size)
{
    t_stack **i;
    t_stack **j;
    t_stack **z;
    int     index;
    
    i = a;
    j = NULL;
    z = i;
    index = 0;
    //printf("che\n");
    while (i)
    {
        j = &(*i)->next;
        while (j && index < size)
        {
            if ((*i)->el > (*j)->el)
            {
                ft_swap(&(*i)->el, &(*j)->el);
        //printf("i = %d j = %d\n", (*i)->el, (*j)->el);
                *i = (*i)->next;
                *j = (*i)->next;
                index++;
				z = i;
				printf("z = %d\n", (*z)->el);
            }
            else if ((*i)->el < (*j)->el)
            {
                *i = (*i)->next;
                *j = (*j)->next;
                index++;
            }
            if (index == size - 1)
            {
                size--;
                //z = i;
            }
            printf("index = %d  c =%d\n", index, size);
        }
        i = z;
    }
}
*/

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
	while (tmp)
	{
		printf("el = %d index = %d\n", (tmp)->el, (tmp)->index);
		tmp = (tmp)->next;
	}
}