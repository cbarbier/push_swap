/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/26 20:56:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				apply_move(t_ps *ps, t_solver *solver, int index)
{
	t_path	*elm;
	char	*ope;

	ope = ps->handlers[index].ope;
	if (!(elm = ft_memalloc(sizeof(t_path))))
		return (0);
	ft_memcpy(elm->ope, ope, 3 * sizeof(char));
	if (!solver->path)
	{
		solver->last = elm;
		solver->path = solver->path;
	}
	else
		solver->last->next = elm;
	solver->last = solver->last->next;
	ps->handlers[index].f(&(ps->a), &(ps->b));
	return (1);
}

int				apply_mvto(t_ps *ps, t_solver *solver)
{
	t_mvto		*mv;
	int			opt_nb;

	mv = ps->mv_to_do;
	if (mv->ope_a == mv->ope_b - 1)
	{
		opt_nb = (mv->nb_a < mv->nb_b ? mv->nb_a : mv->nb_b);
		mv->nb_a -= opt_nb;
		mv->nb_b -= opt_nb;
		while (opt_nb--)
			apply_move(ps, solver, mv->ope_b + 1);
	}
	while (mv->nb_a--)
		apply_move(ps, solver, mv->ope_a);
	while (mv->nb_b--)
		apply_move(ps, solver, mv->ope_b);
	ft_bzero(mv, sizeof(t_mvto));
	return (1);
}

int				print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%s\n", path->ope);
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
