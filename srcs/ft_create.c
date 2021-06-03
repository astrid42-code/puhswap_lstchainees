/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:38:15 by asgaulti          #+#    #+#             */
/*   Updated: 2021/06/03 17:08:00 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_create_a(int nbr, t_stack *stack_a)
{
	t_stack	*new;
	t_stack *tmp;

	//write(1, "OK\n", 3);
	tmp = stack_a;
	while (stack_a != NULL && stack_a->next != NULL)
		stack_a = stack_a->next;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0); // et non 0 sinon ca detruit la liste et je ne pourrai pas free les precedents maillons
	new->el = nbr;
	new->next = NULL;
	if (tmp == NULL)
		tmp = new;
	else 
		stack_a->next = new;
	return (tmp);
}

// arg a transformer en int
// verifier si < intmin ou > intmax : si oui return 1
// + verifier si doublon en créant la lst chainee à partir de l'arg 1
// si doublon return 1
t_stack	*ft_create_lst(int ac, char **av, t_stack **stack_a)
{
	int				i;
	int				count;
	long long		nbr;
	//t_stack			*tmp;

	*stack_a = NULL;
	i = 1;
	count = ac;
	while (i < count)
	{
		nbr = ft_atoll(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (NULL);
		//printf("i = %d  n = %lld\n", i, nbr);
		if (ft_check_doublon(nbr, *stack_a))
			return (NULL);
		*stack_a = ft_create_a(nbr, *stack_a);
	//printf("s = %d\n", stack_a->el);
		if (!*stack_a)
			return (NULL);
		i++;
	}
/*	tmp = stack_a;
	while (tmp)
	{
		printf("e = %d\n", tmp->el);
		tmp = tmp->next;
	}
*/	return (*stack_a);
}
