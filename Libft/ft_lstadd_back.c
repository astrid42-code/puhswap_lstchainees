/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:45:15 by asgaulti          #+#    #+#             */
/*   Updated: 2020/11/29 10:28:36 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	last = *alst;
	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
