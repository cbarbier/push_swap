/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 15:00:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"


int				is_sort(t_ps *ps)
{
	t_list		*a;

	a = ps->a;
	while (a)
	{
		if (a->next && *((int *)(a->content)) > *((int *)(a->next->content)))
			return (0);
		a = a->next;
	}
	return (1);
}

int				my_algo(t_ps *ps, t_solver *solver)
{
	if (*((int *)(ps->a->content)) == ps->maxa)
		apply_move(ps, solver, 5);
	apply_move(ps, solver, 4);
	if (*((int *)(ps->a->content)) == ps->maxa)
		apply_move(ps, solver, 5);
	apply_move(ps, solver, 4);
	if (*((int *)(ps->b->content)) < *((int *)(ps->b->next->content)))
		apply_move(ps, solver, 0);
	while (ft_lstlen(ps->a))
	{
		search_best_move(ps, solver);
		apply_mvto(ps, solver);
		apply_move(ps, solver, 4);
	}
	merge_list(ps, solver);
	return (0);
}
