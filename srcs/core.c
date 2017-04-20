/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/20 16:29:04 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int		put_lists(t_ps *ps)
{
	t_list	*a;
	t_list	*b;

	a = ps->a;
	b = ps->b;
	ft_printf("{red}%15s\t{grn}%15s\n{no}", "stack a", "stack b");
	while (a || b)
	{
		if (a)
			ft_printf("%15d\t", *((int *)(a->content)));
		else
			ft_printf("%15c\t", ' ');
		if (b)
			ft_printf("%15d\n", *((int *)(b->content)));
		else
			ft_printf("%15c\n", ' ');
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
	return (ps->b ? 0 : 1);
}

int				init_solver(t_ps *ps, t_solver *solver, t_path **start)
{
	int		index;
	t_path	*tmp;

	index = 1;
	ft_bzero(solver, sizeof(t_solver));
	solver->max = ft_lstlen(ps->a) * NB_MOVE;
	ft_printf("solver->max: %zd\n", solver->max);
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
	solver->last = solver->path;
	return (1);
}

int				solver_core(t_ps *ps, t_solver *solver)
{
	while (!is_sort(ps))
	{
		if ((int)(ps->a->content) > (int)(ps->a->next->content))
		{
			ps->handlers[0].f(&(ps->a), &(ps->b));
			add_to_path(ps, solver, 0);
		}
		ps->handlers[5].f(&(ps->a), &(ps->b));
		add_to_path(ps, solver, 5);
	}
	pathcpy(solver, &(solver->sol));
	return (0);
}
