/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/24 16:20:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int		put_lists(t_ps *ps)
{
	t_list	*a;
	t_list	*b;

	a = ps->a;
	b = ps->b;
	ft_fprintf(2, "{red}%15s\t{grn}%15s\n{no}", "stack a", "stack b");
	while (a || b)
	{
		if (a)
			ft_fprintf(2, "%15d\t", *((int *)(a->content)));
		else
			ft_fprintf(2, "%15c\t", ' ');
		if (b)
			ft_fprintf(2, "%15d\n", *((int *)(b->content)));
		else
			ft_fprintf(2, "%15c\n", ' ');
		a = (a ? a->next : 0);
		b = (b ? b->next : 0);
	}
	return (1);
}

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

int				init_solver(t_ps *ps, t_solver *solver, t_path **start)
{
	int		index;
	t_path	*tmp;

	index = 1;
	ft_bzero(solver, sizeof(t_solver));
	if (!(*start = (t_path *)ft_memalloc(sizeof(t_path))))
		return (0);
	while (index < solver->max)
	{
		if (!(tmp = (t_path *)ft_memalloc(sizeof(t_path))))
			return (0);
		tmp->next = *start;
		(*start)->prec = tmp;
		*start = tmp;
		index++;
	}
	solver->topa = (int)(*((int *)(ps->a->content)));
	solver->last = solver->path;
	return (1);
}

int				solver_core(t_ps *ps, t_solver *solver)
{
	int		a1;
	int		a2;

	while (!is_sort(ps))
	{
		a1 = (int)(*((int *)(ps->a->content)));
		a2 = (int)(*((int *)(ps->a->next->content)));
		if (a1 != ps->maxa && a1 > a2)
		{
			ps->handlers[0].f(&(ps->a), &(ps->b));
			add_to_path(ps, solver, 0);
		}
		a1 = (int)(*((int *)(ps->a->content)));
		a2 = (int)(*((int *)(ps->a->next->content)));
		if (a1 == ps->mina)
		{
			ps->handlers[4].f(&(ps->a), &(ps->b));
			add_to_path(ps, solver, 4);
			ps->mina = get_mina(ps, ps->a);
		}
		else
		{
			ps->handlers[5].f(&(ps->a), &(ps->b));
			add_to_path(ps, solver, 5);
		}
	}
	while (ps->b)
	{
		ps->handlers[3].f(&(ps->a), &(ps->b));
		add_to_path(ps, solver, 3);
	}
	return (0);
}
