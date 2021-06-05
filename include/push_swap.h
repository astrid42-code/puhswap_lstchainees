/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:50:16 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/05 17:21:57 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				el;
	int				index;
	struct s_stack	*next;
}				t_stack;
/*
typedef struct s_first
{
	struct s_stack	*a;
	struct s_stack	*b;
}				t_first;
*/
// protos
int			main(int ac, char **av);
t_stack		*ft_create_lst(int ac, char **av, t_stack **stack_a);
int			ft_check_arg(int ac, char **av);
void		free_lst(t_stack *stack_a);
void		ft_pushswap(t_stack **stack_a, t_stack **stack_b, int ac);

// utils
int			ft_check_doublon(long long nbr, t_stack *stack_a);
t_stack		*ft_create_a(int nbr, t_stack *stack_a);
//void		ft_bzero(void *s, size_t n);
long long	ft_atoll(const char *str);
int			ft_is_sort(t_stack *a);
int			ft_search_min(t_stack *stack);
void		ft_create_index(t_stack **a);
void    	ft_sort_chunk(int i, t_stack **a, t_stack **b);

void		ft_two(t_stack **a);
void		ft_three(t_stack **a);
//void		ft_undersix(int ac, t_stack **a, t_stack **b);
void		ft_four(t_stack **a, t_stack **b);
//void		ft_five(t_stack **a, t_stack **b);
void		ft_under_fifty(t_stack **a, t_stack **b);
void		ft_sort(t_stack **stack_a, t_stack **stack_b, int count);

// protos lst
int			ft_stacksize(t_stack *stack);
void		ft_search_index(t_stack **a, int count);

//void		ft_lstadd_back_stack(t_stack **stack, t_stack *new);
//void		ft_lstadd_front_stack(t_stack **stack, t_stack *new);

// actions
void    	ft_swap(int *a, int *b);
void    	ft_swap_a(t_stack *a);
void    	ft_swap_b(t_stack *b);
void 		ft_swap_ab(t_stack *a, t_stack *b);

void		ft_rotate_a(t_stack **a);
void		ft_rotate_b(t_stack **b);
void		ft_rotate_ab(t_stack **a, t_stack **b);

void		ft_push_a(t_stack **a, t_stack **b);
void		ft_push_b(t_stack **a, t_stack **b);

void		ft_rev_rot_a(t_stack **a);
void		ft_rev_rot_b(t_stack **b);
void		ft_rev_rot_ab(t_stack **a, t_stack **b);
//t_first		*ft_init_a(int ac, char **av);

#endif
