/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:18:42 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/27 17:24:26 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
    //printf("a = %d  a_next = %d a_next_next = %d\n", a->el, a->next->el, a->next->next->el);
    ft_swap(&(a->el), &(a->next->el));
    printf("sa\n");
    //printf("a = %d  a_next = %d a_next_next = %d\n", a->el, a->next->el, a->next->next->el);
    //swap la valeur en haut de la pile a avec celle d avant (dc la taille de la pile et la meme - 1)
    //+ imprimer l action sa
}

void    ft_swap_b(t_stack *b)
{
    if (ft_stacksize(b) < 1)
        return ;
    ft_swap(&(b->el), &(b->next->el));
    printf("sb\n");
    //printf("b = %d  b_next = %d\n", (b->el), (b->next->el));
    //swap la valeur en haut de la pile b avec celle d avant 
    //+ imprimer l action sb
}

void ft_swap_ab(t_stack *a, t_stack *b)
{
    if (ft_stacksize(a) < 1 || ft_stacksize(b) < 1)
        return ;
    ft_swap(&(a->el), &(a->next->el));
    ft_swap(&(b->el), &(b->next->el));
    printf("a = %d  a_next = %d\n", (a->el), (a->next->el));
    printf("b = %d  b_next = %d\n", (b->el), (b->next->el));
    printf("ss/n");
}