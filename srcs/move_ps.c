/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/20 09:36:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int		ps_move_sa(t_list **a, t_list **b)
{
	(void)b;
	if (!*a || !(*a)->next)
		return (0);
	ft_memswap(&((*a)->content), &((*a)->next->content));
	return (1);
}

int		ps_move_sb(t_list **a, t_list **b)
{
	(void)a;
	if (!(*b) || !(*b)->next)
		return (0);
	ft_memswap(&((*b)->content), &((*b)->next->content));
	return (1);
}

int		ps_move_ss(t_list **a, t_list **b)
{
	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return (0);
	ps_move_sa(a, b);
	ps_move_sb(a, b);
	return (1);
}

int		ps_move_pa(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*b)
		return (0);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	return (1);
}

int		ps_move_pb(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*a)
		return (0);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	return (1);
}
