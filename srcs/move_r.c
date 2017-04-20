/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/20 09:33:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int		ps_move_ra(t_list **a, t_list **b)
{
	t_list *l;

	(void)b;
	if (!(l = *a) || !(l->next))
		return (0);
	ft_lstpushback(a, l);
	*a = (*a)->next;
	l->next = 0;
	return (1);
}

int		ps_move_rb(t_list **a, t_list **b)
{
	t_list *l;

	(void)a;
	if (!(l = *b) || !(l->next))
		return (0);
	ft_lstpushback(b, l);
	*b = (*b)->next;
	l->next = 0;
	return (1);
}

int		ps_move_rr(t_list **a, t_list **b)
{
	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return (0);
	ps_move_ra(a, b);
	ps_move_rb(a, b);
	return (1);
}
