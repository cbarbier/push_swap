/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/30 17:51:59 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

void		ps_move_sa(t_list **a, t_list **b)
{
	(void)b;
	if (!*a || !(*a)->next)
		return ;
	ft_memswap(&((*a)->content), &((*a)->next->content));
}

void		ps_move_sb(t_list **a, t_list **b)
{
	(void)a;
	if (!(*b) || !(*b)->next)
		return ;
	ft_memswap(&((*b)->content), &((*b)->next->content));
}

void		ps_move_ss(t_list **a, t_list **b)
{
	ps_move_sa(a, b);
	ps_move_sb(a, b);
}

void		ps_move_pa(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void		ps_move_pb(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
