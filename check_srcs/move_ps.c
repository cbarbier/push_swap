/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:52:02 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/29 17:11:31 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		ps_move_sa(t_list **a, t_list **b)
{
	(void)b;
	if (!*a || !(*a)->next)
		return ;
	ft_memswap(&((*a)->content), &((*b)->content));
}

void		ps_move_sa(t_list **a, t_list **b)
{
	(void)b;
	if (!(*b) || !(*b)->next)
		return ;
	ft_memswap(&((*b)->content), &((*b)->content));
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

void		ps_move_pa(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;	
	*b = tmp;
}	
