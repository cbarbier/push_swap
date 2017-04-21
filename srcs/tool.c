/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/21 14:01:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				add_to_path(t_ps *ps, t_solver *solver, int index)
{
	char	*ope;

	ope = ps->handlers[index].ope;
	ft_printf("ope: %s\n", ope);
	ft_memcpy(solver->last->ope, ope, 3 * sizeof(char));
	solver->last = solver->last->next;
	return (1);
}

int				remove_from_path(t_ps *ps, t_solver *solver, int index_reverse)
{
	ft_bzero(solver->last->ope, 3 * sizeof(char));
	solver->last = solver->last->prec;
	ps->handlers[index_reverse].f(&(ps->a), &(ps->b));
	return (1);
}

int				print_sol(t_solver *solver)
{
	t_path		*sol;

	sol = solver->sol;
	if (!sol)
		return (0);
	while (sol && *(sol->ope))
	{
		ft_printf("%s\n", sol->ope);
		sol = sol->next;
	}
	return (1);
}

int				pathcpy(t_solver *solver, t_path **sol)
{
	t_path		*cpy;
	t_path		*tmp;
	t_path		*path;

	free_path(*sol);
	path = solver->path;
	cpy = 0;
	while (path && *(path->ope))
	{
		tmp = cpy;
		if (!(cpy = ft_memalloc(sizeof(t_path))))
			return (0);
		cpy->prec = tmp;
		ft_memcpy(cpy->ope, path->ope, 3 * sizeof(char));
		if (!path->prec)
			*sol = cpy; 
		else
			tmp->next = cpy;
		path = path->next;
	}
	return (1);
}

int				free_path(t_path *path)
{
	t_path		*tmp;

	while (path)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
	return (1);
}
