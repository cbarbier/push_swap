/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/30 17:51:32 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

void		ps_move_ra(t_list **a, t_list **b)
{
	t_list *l;

	(void)b;
	if (!(l = *a) || !(l->next))
		return ;
	ft_lstpushback(a, l);
	*a = (*a)->next;
	l->next = 0;
}

void		ps_move_rb(t_list **a, t_list **b)
{
	t_list *l;

	(void)a;
	if (!(l = *b) || !(l->next))
		return ;
	ft_lstpushback(b, l);
	*b = (*b)->next;
	l->next = 0;
}

void		ps_move_rr(t_list **a, t_list **b)
{
	ps_move_ra(a, b);
	ps_move_rb(a, b);
}
