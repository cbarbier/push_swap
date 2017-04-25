/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:53:52 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/25 13:10:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				is_in_list(t_list *a, int *data)
{
	while (a)
	{
		if (*((int *)(a->content)) == *data)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}

int				dir_to_min(t_ps *ps, t_solver *solver)
{
	t_list		*a;
	int			index;
	int			ln;

	(void)solver;
	a = ps->a;
	ln = ft_lstlen(a);
	index = 0;
	while (a && index <= ln / 2)
	{
		if (*((int *)(a->content)) == ps->mina)
			return (5);
		a = a->next;
		index++;
	}
	return (8);
}
