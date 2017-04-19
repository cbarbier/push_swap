/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/19 17:44:58 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int		ps_move_rra(t_list **a, t_list **b)
{
	t_list *l;
	t_list *tmp;

	(void)b;
	if (!(l = *a) || !(l->next))
		return (0);
	while (l->next)
	{
		tmp = l;
		l = l->next;
	}
	tmp->next = 0;
	l->next = *a;
	*a = l;
	return (1);
}

int		ps_move_rrb(t_list **a, t_list **b)
{
	t_list *l;
	t_list *tmp;

	(void)a;
	if (!(l = *b) || !(l->next))
		return (0);
	while (l->next)
	{
		tmp = l;
		l = l->next;
	}
	tmp->next = 0;
	l->next = *b;
	*b = l;
	return (1);
}

int		ps_move_rrr(t_list **a, t_list **b)
{
	if (ps_move_rra(a, b) && ps_move_rrb(a, b))
		return (1);
	return (0);
}
