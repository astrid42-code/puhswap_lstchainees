#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	if (ft_check_arg(ac, av))
	{
		printf("Error\n");
		return (1); // (1 pour faux et non 0!!!)
	}
	if (!ft_create_lst(ac, av, stack_a))
	{
		free_lst(stack_a);
		printf("Error\n");
		return (1);
	}
	// lancer les actions :
//	ft_pushswap(stack_a, stack_b);
	//free_lst(stack_a);
	puts("GG");
	return (0);
}
