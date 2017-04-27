/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 09:39:03 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				bf_is_sort(t_ps *ps)
{
	t_list		*a;

	a = ps->a;
	while (a)
	{
		if (a->next && *((int *)(a->content)) > *((int *)(a->next->content)))
			return (0);
		a = a->next;
	}
	return (ps->b ? 0 : 1);
}

int				init_bf(t_ps *ps, t_solver *solver, t_path **start)
{
	int		index;
	t_path	*tmp;
	int		max;

	index = 1;
	ft_bzero(solver, sizeof(t_solver));
	max = NB_MOVE * ft_lstlen(ps->a);
	if (!(*start = (t_path *)ft_memalloc(sizeof(t_path))))
		return (0);
	while (index < max)
	{
		if (!(tmp = (t_path *)ft_memalloc(sizeof(t_path))))
			return (0);
		tmp->next = *start;
		(*start)->prec = tmp;
		*start = tmp;
		index++;
	}
	solver->last = solver->sol;
	return (1);
}

int				brute_force(t_ps *ps, t_solver *solver, int loop)
{
	int			index;
	int			i;

	if (bf_is_sort(ps))
		return (pathcpy(solver, &(solver->path)));
	if (loop > solver->max)
		return (0);
	index = 0;
	i = 0x400;
	while (index < NB_MOVE)
	{
		if ((!loop || !(i & ps->handlers[index].oppo))
				&& ps->handlers[index].f(&(ps->a), &(ps->b)))
		{
			add_to_sol(ps, solver, index);
			if (brute_force(ps, solver, loop + 1))
				return (1);
			remove_from_sol(ps, solver, ps->handlers[index].reverse);
		}
		index++;
		i >>= 1;
	}
	return (0);
}
