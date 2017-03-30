/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/30 17:44:40 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

void		ps_move_rra(t_list **a, t_list **b)
{
	t_list *l;
	t_list *tmp;

	(void)b;
	if (!(l = *a) || !(l->next))
		return ;
	while (l->next)
	{
		tmp = l;
		l = l->next;
	}
	tmp->next = 0;
	l->next = *a;
	*a = l;
}

void		ps_move_rrb(t_list **a, t_list **b)
{
	t_list *l;
	t_list *tmp;

	(void)a;
	if (!(l = *b) || !(l->next))
		return ;
	while (l->next)
	{
		tmp = l;
		l = l->next;
	}
	tmp->next = 0;
	l->next = *b;
	*b = l;
}

void		ps_move_rrr(t_list **a, t_list **b)
{
	ps_move_rra(a, b);
	ps_move_rrb(a, b);
}
