#include "../include/push_swap.h"

static t_stack	*ft_lower_el(t_stack *lower)
{
	t_stack	*min;

	min = NULL;
	while (lower)
	{
		if ((!min && lower->index == -1) || (min && min->el > lower->el
				&& lower->index == -1))
			min = lower; // min = maillon le + petit
		lower = lower->next;
	}
	return (min);
}

void	ft_create_index(t_stack **a)
{
	t_stack	*lower;
	int		index;
	t_stack	*tmp;

	lower = ft_lower_el(*a);
	index = 0;
	while (lower)
	{
		lower->index = index;
		//printf("low = %d\n", lower->index);
		lower = ft_lower_el(*a);
		index++;
	}
	tmp = *a;
	// while (tmp)
	// {
	// 	printf("el = %d index = %d\n", (tmp)->el, (tmp)->index);
	// 	tmp = (tmp)->next;
	// }
}
/*
void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int pos;
	int index;
	t_stack *tmp_a;
	t_stack *tmp;
	t_stack *tmp_b;

	chunk = 5;
	tmp = *a;
	index = 0;
	while (chunk != 0)
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			tmp_a = tmp;
			pos = 0;
			while (!(tmp_a->index >= index && tmp_a->index < index + 20))
			{
				tmp_a = tmp_a->next;
				pos++;
			}
			if (tmp_a->index >= index && tmp_a->index < index + 20)
			{
				if (pos == 0)
				{
					ft_push_b(&tmp, b);
					ft_sort_b(b);
					size_chunk--;
				}
				else
				{
					ft_rotate_a(&tmp);
				}
			}
			if (size_chunk == 0)
			{
				size_chunk = 20;
				tmp_a = tmp;
					//printf("el_a = %d\n", (*a)->el);
				while (size_chunk != 0)
				//while (*b && (*b)->next)
				{
					ft_push_a(&tmp, b);
					size_chunk--;
					//printf("el_a = %d\n", tmp->el);
				}
				printf("1 el_a = %d next = %d\n", tmp->el, tmp->next->el);
				size_chunk = 20;
				//tmp = *a;
				//tmp_a = *a;
				while (size_chunk != 0)
				{
					ft_rotate_a(&tmp);
				printf("el_a = %d next = %d\n", tmp->el, tmp->next->el);
					size_chunk--;
			//printf("size_chunk =%d\n", size_chunk);
				}
				
			}
			//printf("tmp = %d\n", tmp->el);
		}
		*a = tmp;
		tmp_b = *b;
		// while (tmp_b)
		// {
		// 	printf("tmp_b = %d\n", tmp_b->el);
		// 	tmp_b = tmp_b->next;
		// }
		index += 20;	
		chunk--;
		//printf("chunk = %d\n", chunk);
	}
	tmp_b = *b;
	tmp = *a;
	while (tmp_b)
	{
		ft_push_a(a, &tmp_b);
		(tmp_b) = (tmp_b)->next;
	}
	// *a = tmp;
	// faire pter *a sur tmp_a?
}
*/


/*

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int		i;
	int		chunk;
	int		size_chunk;
	int		pos;
	t_stack	*tmp_a;
	t_stack *tmp;

	tmp_a = *a;
	chunk = 5;
	i = 0;
	pos = 0;
	while (chunk != 0) // tq j'ai des chunks
	{
		tmp = tmp_a;
		size_chunk = 20;
		while (size_chunk != 0)
		{
			// pb : pos tjrs = a 0!!
		//printf("pos = %d\n", pos);
			if (tmp_a->index > i + 20)
			{
				tmp_a = tmp_a->next;
				pos++;
				printf("el = %d index = %d pos = %d\n", tmp_a->el, tmp_a->index, pos);
			}
			else if ((tmp_a->index >= i && tmp_a->index < i + 20) && pos != 0)
			{
			//pos = ft_pos_index(tmp, i);
				while (pos != 0)
				{	
					ft_rotate_a(&tmp);
				printf("pos = %d el_a = %d\n", pos, tmp_a->el);
			printf("tmp = %d tmp_a = %d\n", tmp->el, tmp_a->el);
					pos--;
					//pos = ft_pos_index(tmp, i);
				}
			}
			if (pos == 0 && (tmp_a->index >= i && tmp_a->index < i + 20))
			{
					ft_push_b(&tmp_a, b);
					printf("b = %d\n", (*b)->el);
					//ft_sort_b();
					size_chunk--;
			}
				//printf("index = %d  pos = %d el = %d\n", tmp_a->index, pos, tmp_a->el);
				if (size_chunk == 0)
				{
					while ((*b)->next != NULL)
					{
						ft_push_a(&tmp_a, b);
					}
					size_chunk = 20;
					while (size_chunk != 0)
					{
						ft_rev_rot_a(&tmp_a);
						size_chunk--;
						printf("el_a = %d\n", tmp_a->el);
				//printf("size_chunk =%d\n", size_chunk);
					}
				}
		}
		i += 20;
		chunk--;
		tmp_a = tmp;
	}
}
*/

void	ft_sort_b(t_stack **b)
{
	t_stack *tmp_b;
	int	pos;
//	int	count;
	int middle;
//	int index;
	
	pos = 1;
	tmp_b = *b;
	middle = ft_stacksize(tmp_b) / 2;
		// while (tmp_b)
		// {
		// 	//printf("tmp_b = %d\n", tmp_b->el);
		// 	tmp_b = tmp_b->next;
		// }
		// tmp_b = *b;
	//printf("size = %d\n", ft_stacksize(tmp_b));
	if (ft_stacksize(tmp_b) == 1)
		return ;
	if (ft_stacksize(tmp_b) == 2)
	{
		//printf("el = %d  index = %d el->next = %d  index->next = %d\n", tmp_b->el, tmp_b->index, tmp_b->next->el, tmp_b->next->index);
		if ((tmp_b)->el < (tmp_b)->next->el)
    	{
        	ft_swap_b(tmp_b);
        	//return ;
    	}
		//printf("el = %d  index = %d el->next = %d  index->next = %d\n", tmp_b->el, tmp_b->index, tmp_b->next->el, tmp_b->next->index);
    	// else 
        // 	return ;
	}
/*	else
	{
		//puts("che");
		// if (tmp_b->index == 0)
		// {	
		// 	ft_rotate_b(&tmp_b);
		// }
		//else
		{
			index = tmp_b->index;
			//printf("el = %d  index = %d el->next = %d  index->next = %d\n", tmp_b->el, tmp_b->index, tmp_b->next->el, tmp_b->next->index);
			while (tmp_b && tmp_b->next && index < tmp_b->next->index)
			{
				pos++;
				//printf("pos = %d\n", pos);
				tmp_b = tmp_b->next;
				//printf("el2 = %d\n", tmp_b->el);
			}
			if (pos == ft_stacksize(tmp_b))
			{	ft_rotate_b(&tmp_b);
			}
			else if (pos == 1)
				return ;
			else
			{tmp_b = *b;
			if (pos <= middle)
			{
				count = 0;
				// if (pos == 1)
				// 	ft_swap_b(tmp_b);
				// else
				{
					while (pos > 1)
					{
						ft_swap_b(tmp_b);
						ft_rotate_b(&tmp_b);
						pos--;
						count++;
					}
					// if (pos == 1)
					// 	ft_swap_b(tmp_b);
					while (count != 0)
					{
						ft_rev_rot_b(&tmp_b);
						count--;
					}
				}
			}
			else if (pos > middle)
			{
				count = 1;
				if (pos == ft_stacksize(tmp_b))
					ft_rotate_b(&tmp_b);
				else
				{
					while (pos < ft_stacksize(tmp_b))
					{
						ft_rev_rot_b(&tmp_b);
						ft_swap_b(tmp_b);
						pos++;
						//printf("pos2 = %d\n", pos);
						count++;
					}
					//if (pos == 1)
					//	ft_swap_b(tmp_b);
					while (count != 0)
					{
						ft_rev_rot_b(&tmp_b);
						count--;
					}
				}
			}
			}
		}
	}
*/	*b = tmp_b;
		while (tmp_b)
		{
			printf("tmp_b = %d\n", tmp_b->el);
			tmp_b = tmp_b->next;
		}
	return ;
}

void	ft_sort_chunk_onehundred(t_stack **a, t_stack **b)
{
	int chunk;
	int size_chunk;
	int index;
	int el;
	t_stack *tmp_a;
	t_stack *tmp;
	t_stack *tmp_b;

	chunk = 5;
	tmp = *a;
	index = 0;
//	while (chunk != 0)
	{
		size_chunk = 20;
		while (size_chunk != 0)
		{
			tmp_a = ft_find_best_pos(tmp, index);
			tmp = tmp_a;
			el = tmp_a->index;
			if (b && ft_stacksize(*b) >= 3)
			{	ft_prepare_b(el, b);
		printf("el = %d index = %d \n", tmp->el, tmp->index);
			ft_push_b(&tmp, b);
			}
			else
			{
				ft_push_b(&tmp, b);
			ft_sort_b(b);
			}
			size_chunk--;
		}
		*a = tmp;
		tmp_b = *b;
	/*	while (tmp_b)
		{
			printf("tmp_b = %d\n", tmp_b->el);
		 	tmp_b = tmp_b->next;
		}
		index += 20;	
		chunk--;
*/		//printf("chunk = %d\n", chunk);
	}
	tmp_b = *b;
	tmp = *a;
	while (tmp_b)
	{
		ft_push_a(a, &tmp_b);
		(tmp_b) = (tmp_b)->next;
	}
	
}

t_stack	*ft_find_best_pos(t_stack *tmp_a, int index)
{
	int pos;
	int rev_pos;
	int count;
	int size;
	t_stack	*tmp;

	pos = 0;
	rev_pos = 50;
	count = 0;
	size = ft_stacksize(tmp_a);
	tmp = tmp_a;
	while (!(tmp_a->index >= index && tmp_a->index < index + 20) && count != size / 2)
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
		if (tmp_a->index >= index && tmp_a->index < index + 20)
		{
			rev_pos = count;
		}
		tmp_a = tmp_a->next;
		count++;
	}
	tmp_a = tmp;
	rev_pos = count - rev_pos;
	//printf("pos = %d  revpos = %d\n", pos, rev_pos);
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
			//printf("el = %d index = %d revpos = %d\n", tmp_a->el, tmp_a->index, rev_pos);
		}
	}
	return (tmp_a);
}

void	ft_prepare_b(int index, t_stack **b)
{
	t_stack *tmp_b;
	
	tmp_b = *b;
	while (tmp_b)
	{
		if (tmp_b->index > index)
			ft_rotate_b(&tmp_b);
		printf("index = %d tmp_indx = %d \n", index, tmp_b->index);
		tmp_b = tmp_b->next;
	}
/*	while (tmp_b->index > index)
	{
		ft_rotate_b(&tmp_b);
		printf("index = %d tmp_indx = %d \n", index, tmp_b->index);
		tmp_b = tmp_b->next;
	}
*/	*b = tmp_b;
}