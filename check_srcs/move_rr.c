/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/29 17:22:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ps_move_rra(t_list **a, t_list **b)
{
	t_list *l

	(void)b;
	l = *a;
	if (!l)
		return ;
	while (l->next)
		l = l->next;
	ft_memswap(&((*a)->content), &(l->content));
}

void		ps_move_rrb(t_list **a, t_list **b)
{
	t_list *l

	(void)a;
	l = *b;
	if (!l)
		return ;
	while (l->next)
		l = l->next;
	ft_memswap(&((*b)->content), &(l->content));
}

void		ps_move_rrr(t_list **a, t_list **b)
{
	ps_move_rra(a, b);
	ps_move_rrb(a, b);
}
