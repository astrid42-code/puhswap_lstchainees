/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:38:26 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/27 16:54:22 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_pushswap(t_stack **stack_a, t_stack **stack_b, int ac)
{
    int count;
    (void)stack_b;

    count = ac - 1;
    if (count < 6)
    {
        if (count == 1)
            return ;
        else if (count == 2)
            ft_two(stack_a);
        else if (count == 3)
            ft_three(stack_a);
        else if (count == 4 || count == 5)
            ft_undersix(ac, stack_a, stack_b);
    }
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

void		ft_undersix(int ac, t_stack **a, t_stack **b)
{
    if (ac - 1 == 4)
	{	
		ft_push_b(a, b);
		ft_three(a);
		ft_push_a(a, b);
		ft_four(a, b);
	}
	if (ac - 1 == 5)
	{
		ft_push_b(a, b);
		ft_push_b(a, b);
		ft_three(a);
		ft_push_a(a, b);
		ft_four(a, b);
		ft_push_a(a, b);
		ft_five(a, b);
	}
	return ;
}

void	ft_four(t_stack **a, t_stack **b)
{
	if ((*a)->el < (*a)->next->el)
		return ;
	else if ((*a)->el > (*a)->next->next->next->el)
	{
		ft_rotate_a(a);
		//return ;
	}
	else if ((*a)->el > (*a)->next->el && (*a)->el < (*a)->next->next->el)
	{
		ft_swap_a(*a);
		//return ;
	}
	else if ((*a)->el > (*a)->next->next->el && 
					(*a)->el < (*a)->next->next->next->el)
	{
		ft_swap_a(*a);
		ft_push_b(a, b);
		ft_three(a);
		ft_push_a(a, b);
		//return ;
	}
	// un seul return a la fin?
	return ;
}

void	ft_five(t_stack **a, t_stack **b)
{
	if ((*a)->el < (*a)->next->el)
		return ;
	else if ((*a)->el > (*a)->next->next->next->next->el)
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
	else if ((*a)->el > (*a)->next->next->next->el && 
				(*a)->el < (*a)->next->next->next->next->el)
	{
		ft_swap_a(*a);
		ft_push_b(a, b);
		ft_four(a, b);
		ft_push_a(a, b);
	}
	return ;
}
