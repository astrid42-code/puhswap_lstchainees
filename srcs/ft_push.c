/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:32:43 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/05/25 16:16:24 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_push_a(int ac, t_data *data)
{
    data->len_a++;
    data->tab_a[data->len_a] = data->tab_b[data->len_b];
    data->len_b--;
    printf("pa\n");
	déplace l él en haut de la pile b vers le haut de la pile a
    + imprimer l action pa
}

void ft_push_b(int ac, t_data *data)
{
    data->len_b++;
    data->tab_b[data->len_b] = data->tab_a[data->len_a];
    data->len_a--;
    printf("pb\n");
	déplace l él en haut de la pile a vers le haut de la pile b
    + imprimer l action pb
}

void ft_pop()
{
    tq il y a un el je le rentre (pop) dans la liste chainee
    while (tab[i])
    {
        pop chaque el dans la pile demandée (ou une fct pour a et une pour b)
        = t_list *a est un tableau d int qui pointe sur la liste chainee (sa taille est ac - 1) 
        et/ou on utilise ft_lst_add_front pour ajouter chaque valeur du tableau d int (a verifier)
    }
}