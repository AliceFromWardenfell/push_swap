/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisa <alisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:48:40 by alisa             #+#    #+#             */
/*   Updated: 2021/08/26 21:48:41 by alisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	*create_inst_node(char *val)
{
	t_inst	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		exit(error());
	if (tmp)
	{
		tmp->instruction = val;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}

void	addinstnode_back(t_inst **lst, t_inst *new)
{
	t_inst	*tmp;

	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->prev = tmp;
}

t_stack	*create_node(int val)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		exit(error());
	if (tmp)
	{
		tmp->val = val;
		tmp->next = NULL;
		tmp->curr_tag = -1;
	}
	return (tmp);
}

void	addnode_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
