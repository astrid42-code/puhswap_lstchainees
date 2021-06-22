/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/21 17:18:35 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static t_stack	*ft_lower_el(t_stack *lower)
{
	t_stack	*min;

	min = NULL;
	while (lower)
	{
		if ((!min && lower->index == -1) || (min && min->el > lower->el
				&& lower->index == -1))
			min = lower;
		lower = lower->next;
	}
	return (min);
}

void	ft_create_index(t_stack **a)
{
	t_stack	*lower;
	int		index;

	lower = ft_lower_el(*a);
	index = 0;
	while (lower)
	{
		lower->index = index;
		lower = ft_lower_el(*a);
		index++;
	}
}

t_stack	*ft_pos(int pos, int rev_pos, t_stack *tmp_a)
{
	if (pos <= rev_pos)
	{
		while (pos-- != 0)
			ft_rotate_a(&tmp_a);
	}
	else
	{
		while (rev_pos-- > 0)
			ft_rev_rot_a(&tmp_a);
	}
	return (tmp_a);
}

void	ft_pos_sort_b(int pos, t_stack **b)
{
	if (pos <= ft_stacksize(*b) / 2)
		while (pos-- != 0)
			ft_rotate_b(b);
	else if (pos > ft_stacksize(*b) / 2)
		while (pos++ < ft_stacksize(*b))
			ft_rev_rot_b(b);
}
