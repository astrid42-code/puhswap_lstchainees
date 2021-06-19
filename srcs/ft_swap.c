/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:18:42 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/19 18:51:44 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ft_swap_a(t_stack *a)
{
    if (ft_stacksize(a) < 1)
        return ;
    ft_swap(&(a->el), &(a->next->el));
    ft_swap(&(a->index), &(a->next->index));
    printf("sa\n");
}

void    ft_swap_b(t_stack *b)
{
    if (ft_stacksize(b) < 1)
        return ;
    ft_swap(&(b->el), &(b->next->el));
    ft_swap(&(b->index), &(b->next->index));
    printf("sb\n");
}

void ft_swap_ab(t_stack *a, t_stack *b)
{
    if (ft_stacksize(a) < 1 || ft_stacksize(b) < 1)
        return ;
    ft_swap(&(a->el), &(a->next->el));
    ft_swap(&(a->index), &(a->next->index));
    ft_swap(&(b->el), &(b->next->el));
    ft_swap(&(b->index), &(b->next->index));
    printf("ss/n");
}