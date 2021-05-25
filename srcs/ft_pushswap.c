/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:38:26 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/25 18:07:45 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_pushswap(t_stack *stack_a, t_stack *stack_b, int ac)
{
    int count;
    (void)stack_b;

    count = ac - 1;
    if (count < 6)
    {
        if (count == 1)
            return ;
        else if (count == 2)
            ft_two(&stack_a);
        else if (count == 3)
            ft_three(&stack_a);
/*        else if (count == 4 || count == 5)
            ft_undersix(stack_a, stack_b);
*/    }
/*    else
        ft_sort(stack_a, stack_b);
*/
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
/*	if ((*a)->el > (*a)->next->el && (*a)->el > (*a)->next->next->el && (*a)->next->el > (*a)->next->next->el)
	{
		ft_swap_a(a);
		ft_rev_rot_a(a);
		return ;
	}
*/	if ((*a)->el > (*a)->next->el && (*a)->el > (*a)->next->next->el && (*a)->next->el < (*a)->next->next->el)
	{
		ft_rotate_a(a);
		return ;
	}
	if ((*a)->el < (*a)->next->el && (*a)->el < (*a)->next->next->el && (*a)->next->el < (*a)->next->next->el)
	{
		ft_swap_a(*a);
		ft_rotate_a(a);
		return ;
	}
/*	if ((*a)->el < (*a)->next->el && (*a)->el > (*a)->next->next->el)
	{
		ft_swap_a(*a);
		ft_rev_rot_a(a);
		return ;
	}
*/	else
		return ;	
}
/*
void		ft_undersix(t_stack *stack_a, t_stack *stack_b)
{
    
}

*/