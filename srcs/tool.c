/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 18:22:13 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				set_opt(t_ps *ps, char **argv, int argc)
{
	int		index;
	int		index2;

	index = 1;
	while (index < argc && ft_strlen(argv[index]) >= 2
			&& argv[index][0] == '-')
	{
		index2 = 1;
		while (argv[index][index2])
		{
			if (argv[index][index2] == 'v')
				ps->opt_v = 1;
			else if (argv[index][index2] == 'c')
				ps->opt_c = 1;
			else
				return (argv[index][index2] == '-' ? index + 1 : index);
			index2++;
		}
		index++;
	}
	return (index);
}

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
		solver->path = elm;
		solver->last = solver->path;
	}
	else
	{
		solver->last->next = elm;
		solver->last = solver->last->next;
	}
	ps->handlers[index].f(&(ps->a), &(ps->b));
	ps_print(ps, ope);
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
