/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:38:26 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/03 16:16:10 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
/*	else if (count < 50)
		ft_under_fifty(stack_a, stack_b);
*/	else
	{
        ft_sort(stack_a, stack_b, count);
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
/*
void		ft_undersix(int ac, t_stack **a, t_stack **b)
{
	
	else if (ac - 1 == 5)
	{
		ft_push_b(a, b);
		ft_push_b(a, b);
		ft_three(a);
		//if ((*b)->el > (*b)->next->el)
		//	ft_swap_b(*b);
		ft_push_a(a, b);
		ft_four(a, b);
		ft_push_a(a, b);
		ft_five(a, b);
	}
	return ;
}
*/
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
/*
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
*/
void	ft_under_fifty(t_stack **a, t_stack **b)
{
	int i;
	int middle;

	 // ou juste faire ac - 1!
	//printf("m = %d\n", middle);
	
	while (ft_stacksize(*a) > 3/* || ft_is_sort(a) == 1*/)
	{
		middle = ft_stacksize(*a) / 2;
		//printf("el1 = %d\n", (*a)->el);
		i = ft_search_min(*a); //(fct qui renvoie la position du plus petit nbr)
		//printf("middle = %d i = %d\n", middle, i);
		//printf("i3 = %d\n", i);
		if (i == 0)
			ft_push_b(a, b); 
		else if (i <= middle) //(place dans 1ere moitie)
			ft_rotate_a(a);
		else
		{
			ft_rev_rot_a(a);
		}
	}
	ft_three(a); // ranger les trois nombres restants
	while (*b)
	{
		// tq il reste des nombres dans b, je les push dans a ( ils rentrent dans l'ordre du plus grand au plus petit)
		ft_push_a(a, b);
	}
//		puts("che");
}

void	ft_sort(t_stack **a, t_stack **b, int count)
{
	(void)b;

	//lecture et attribution index :
	ft_search_index(a, count);
}