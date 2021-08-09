#include "push_swap.h"

void	sort_2_b(t_stack **a, t_stack **b, t_technical *t)
{
	t_stack	*tmp;

	tmp = *b;
	tmp = tmp->next;
	(*b)->curr_tag = SORTED;
	tmp->curr_tag = SORTED;
	if (tmp->expected_pos > (*b)->expected_pos)
	{
		push(a, b, t, A);
		rotate(a, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
	}
	else
	{
		push(a, b, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
	}
	t->as_alg.wanted_el += 2;
}

static void	sort_3_b_utils(t_stack **a, t_stack **b, t_technical *t, int *m) // ???? mb remove
{
	if (m[0] < m[1] && m[1] > m[2] && m[2] > m[0])
	{
		push(a, b, t, A);
		rotate(a, t, A);
		push(a, b, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
	}
	if (m[0] > m[1] && m[1] < m[2] && m[2] > m[0])
	{
		push(a, b, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
	}	
	if (m[0] < m[1] && m[1] > m[2] && m[2] < m[0])
	{
		swap(b, t, B);
		push(a, b, t, A);
		push(a, b, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
	}	
	if (m[0] > m[1] && m[1] < m[2] && m[2] < m[0])
	{
		push(a, b, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
	}	
	if (m[0] > m[1] && m[1] > m[2] && m[2] < m[0])
	{
		push(a, b, t, A);
		push(a, b, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
		rotate(a, t, A);
	}
	if (m[0] < m[1] && m[1] < m[2] && m[2] > m[0])
	{
		push(a, b, t, A);
		rotate(a, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
		push(a, b, t, A);
		rotate(a, t, A);
	}
}

void	sort_3_b(t_stack **a, t_stack **b, t_technical *t)
{
	t_stack	*tmp;
	int		m[3];
	int		i;

	tmp = *b;
	i = 0;
	while (tmp)
	{
		m[i++] = tmp->expected_pos;
		tmp->curr_tag = SORTED; //check if works
		tmp = tmp->next;
	}
	t->as_alg.wanted_el += 3;
	sort_3_b_utils(a, b, t, m);
}