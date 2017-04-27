/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 18:22:23 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				add_to_sol(t_ps *ps, t_solver *solver, int index)
{
	char	*ope;

	ope = ps->handlers[index].ope;
	ft_memcpy(solver->last->ope, ope, 3 * sizeof(char));
	solver->last = solver->last->next;
	ps_print(ps, ope);
	return (1);
}

int				remove_from_sol(t_ps *ps, t_solver *solver, int index_reverse)
{
	ft_bzero(solver->last->ope, 3 * sizeof(char));
	solver->last = solver->last->prec;
	ps->handlers[index_reverse].f(&(ps->a), &(ps->b));
	return (1);
}

int				pathcpy(t_solver *solver, t_path **path)
{
	t_path		*cpy;
	t_path		*tmp;
	t_path		*sol;

	free_path(*path);
	sol = solver->sol;
	cpy = 0;
	while (sol && *(sol->ope))
	{
		tmp = cpy;
		if (!(cpy = ft_memalloc(sizeof(t_path))))
			return (0);
		cpy->prec = tmp;
		ft_memcpy(cpy->ope, sol->ope, 3 * sizeof(char));
		if (!sol->prec)
			*path = cpy;
		else
			tmp->next = cpy;
		sol = sol->next;
	}
	return (1);
}
