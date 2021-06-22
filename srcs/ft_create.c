/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:38:15 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/20 16:17:46 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_a(int nbr, t_stack *stack_a)
{
	t_stack	*new;
	t_stack	*tmp;

	tmp = stack_a;
	while (stack_a != NULL && stack_a->next != NULL)
		stack_a = stack_a->next;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->el = nbr;
	new->index = -1;
	new->next = NULL;
	if (tmp == NULL)
		tmp = new;
	else
		stack_a->next = new;
	return (tmp);
}

t_stack	*ft_create_lst(int ac, char **av, t_stack **stack_a)
{
	int				i;
	int				count;
	long long		nbr;

	*stack_a = NULL;
	i = 1;
	count = ac;
	while (i < count)
	{
		nbr = ft_atoll(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (NULL);
		if (ft_check_doublon(nbr, *stack_a))
			return (NULL);
		*stack_a = ft_create_a(nbr, *stack_a);
		if (!*stack_a)
			return (NULL);
		i++;
	}
	return (*stack_a);
}
