/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/29 18:10:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ps_move_ra(t_list **a, t_list **b)
{
	t_list *l

	(void)b;
	if (!(l = *a))
		return ;
	*a = (*a)->next;
	ft_lstpushback(a, l);
}

void		ps_move_rb(t_list **a, t_list **b)
{
	t_list *l

	(void)a;
	if (!(l = *b))
		return ;
	*b = (*b)->next;
	ft_lstpushback(b, l);
}

void		ps_move_rr(t_list **a, t_list **b)
{
	ps_move_ra(a, b);
	ps_move_rb(a, b);
}
