#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				element;
	struct s_stack	*next;
}				t_stack;

typedef struct s_first
{
	struct s_stack	*a;
	struct s_stack	*b;
}				t_first;

// protos
int			main(int ac, char **av);
t_stack		*ft_create_lst(int ac, char **av, t_stack *stack_a);
int			ft_check_arg(int ac, char **av);
void		free_lst(t_stack *stack_a);
void		ft_pushswap(t_stack *stack_a, t_stack *stack_b);

int			ft_check_doublon(long long nbr, int index, t_stack *stack_a);
t_stack		*ft_create_a(int nbr, t_stack *stack_a);
void		ft_bzero(void *s, size_t n);
long long	ft_atoll(const char *str);

//t_first		*ft_init_a(int ac, char **av);
#endif
