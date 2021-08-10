#include "push_swap.h"

void	fill_stack_and_arr(t_stack **a, t_technical *t, int argc, char **argv)
{
	int		i;
	int		checked_val;

	i = 1;
	t->sorted_arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!t->sorted_arr)
		exit(error());
	*a = create_node(check_argv(*a, argv[i]));
	t->sorted_arr[i - 1] = check_argv(*a, argv[i]);
	while (++i < argc)
	{
		checked_val = check_argv(*a, argv[i]);
		addnode_back(a, create_node(checked_val));
		t->sorted_arr[i - 1] = checked_val;
	}
	t->a_num = i - 1;
	t->b_num = 0;
}

void	assign_expected_positions(t_stack *a, t_technical *t)
{
	int		i;

	while (a)
	{
		i = 0;
		while ((a)->val != t->sorted_arr[i])
			i++;
		(a)->expected_pos = i + 1;
		a = (a)->next;
	}
}
