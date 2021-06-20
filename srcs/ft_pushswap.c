/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:38:26 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/20 14:18:32 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pushswap(t_stack **stack_a, t_stack **stack_b, int ac)
{
    int count;

    count = ac - 1;
    if (count < 5)
    {
        if (count == 1)
            return ;
        else if (count == 2)
            ft_two(stack_a);
        else if (count == 3)
            ft_three(stack_a);
        else if (count == 4)
            ft_four(stack_a, stack_b);
    }
	else if (count != 100 && count != 500)
		ft_under_fifty(stack_a, stack_b);
	else if (count == 100 || count == 500)
	{
		ft_create_index(stack_a);
		if (count == 100)
			ft_sort_chunk_onehundred(stack_a, stack_b);
		else if (count == 500)
			ft_sort_chunk_fivehundred(stack_a, stack_b);
	}
}

void	ft_two(t_stack **a)
{
    if ((*a)->el > (*a)->next->el)
    {
        ft_swap_a(*a);
        return ;
    }
    else 
        return ;
}

void	ft_three(t_stack **a)
{
	if ((*a)->el > (*a)->next->el && (*a)->el < (*a)->next->next->el)
	{
		ft_swap_a(*a);
		return ;
	}
	if ((*a)->el > (*a)->next->el && (*a)->el > (*a)->next->next->el && (*a)->next->el > (*a)->next->next->el)
	{
		ft_swap_a(*a);
		ft_rev_rot_a(a);
		return ;
	}
	if ((*a)->el > (*a)->next->el && (*a)->el > (*a)->next->next->el && (*a)->next->el < (*a)->next->next->el)
	{
		ft_rotate_a(a);
		return ;
	}
	if ((*a)->el < (*a)->next->el && (*a)->el < (*a)->next->next->el && (*a)->next->el > (*a)->next->next->el)
	{
		ft_swap_a(*a);
		ft_rotate_a(a);
		return ;
	}
	if ((*a)->el < (*a)->next->el && (*a)->el > (*a)->next->next->el)
	{
		ft_rev_rot_a(a);
		return ;
	}
	else
		return ;	
}

void	ft_four(t_stack **a, t_stack **b)
{
	ft_push_b(a, b);
	ft_three(a);
	ft_push_a(a, b);
	if ((*a)->el < (*a)->next->el)
		return ;
	else if ((*a)->el > (*a)->next->next->next->el)
		ft_rotate_a(a);
	else if ((*a)->el > (*a)->next->el && (*a)->el < (*a)->next->next->el)
		ft_swap_a(*a);
	else if ((*a)->el > (*a)->next->next->el && 
					(*a)->el < (*a)->next->next->next->el)
	{
		ft_swap_a(*a);
		ft_push_b(a, b);
		ft_three(a);
		ft_push_a(a, b);
	}
	return ;
}

void	ft_under_fifty(t_stack **a, t_stack **b)
{
	int i;
	int middle;

	while (ft_stacksize(*a) > 3)
	{
		middle = ft_stacksize(*a) / 2;
		i = ft_search_min(*a);
		if (i == 0)
			ft_push_b(a, b); 
		else if (i <= middle)
			ft_rotate_a(a);
		else
		{
			ft_rev_rot_a(a);
		}
	}
	ft_three(a);
	while (*b)
		ft_push_a(a, b);
}
