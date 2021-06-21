/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:44:01 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/21 13:52:28 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int i;

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

t_stack	*ft_find_best_pos2(t_stack *tmp_a, int index)
{
	int pos;
	int rev_pos;
	int count;
	int size;
	t_stack	*tmp;

	pos = 0;
	rev_pos = 250;
	count = 0;
	size = ft_stacksize(tmp_a);
	tmp = tmp_a;
	while (!(tmp_a->index >= index && tmp_a->index < index + 50) && count != size / 2)
	{
		tmp_a = tmp_a->next;
		pos++;
		count++;
	}
	while (count != size / 2)
	{
		tmp_a = tmp_a->next;
		count++;
	}	
	while (count != size)
	{
		if (tmp_a->index >= index && tmp_a->index < index + 50)
		{
			rev_pos = count;
		}
		tmp_a = tmp_a->next;
		count++;
	}
	tmp_a = tmp;
	rev_pos = count - rev_pos;
	if (pos <= rev_pos)
	{
		while (pos != 0)
		{
			ft_rotate_a(&tmp_a);
			pos--;
		}
	}
	else
	{
		while (rev_pos > 0)
		{
			ft_rev_rot_a(&tmp_a);
			rev_pos--;
		}
	}
	return (tmp_a);
}

void	ft_sort_b2(int index, t_stack **b, t_stack **tmp_a)
{
	t_stack	*tmp_b;
	int count;
	int pos;
	int tmp;

	count = 0;
	//tmp = index + 49;
	tmp = 500;
	tmp_b = *b;
	while (tmp != index)
	{
		pos = 0;
		tmp_b = *b;
		
		while (tmp_b->index != tmp)
		{
			tmp_b = tmp_b->next;
			pos++;
		}
		if (tmp_b->index == tmp)
		{
			if (pos <= ft_stacksize(*b) / 2)
			{
				while (pos != 0)
				{
					ft_rotate_b(b);
					pos--;
				}
			}
			else if (pos > ft_stacksize(*b) / 2)
			{
				while (pos < ft_stacksize(*b))
				{
					ft_rev_rot_b(b);
					pos++;
				}
			}
			ft_push_a(tmp_a, b);
			tmp--;
		}
	}
		ft_push_a(tmp_a, b);
}