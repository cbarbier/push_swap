/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/20 09:30:57 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static int		put_lists(t_ps *ps)
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
	solver->last = solver->path;
	return (1);
}

static int		put_path(t_path *p)
{
	ft_printf("path: ");
	while (p && *(p->ope))
	{
		ft_printf("%s ", p->ope);
		p = p->next;
	}
	ft_printf("\n");
	return (1);
}

int				solver_core(t_ps *ps, t_solver *solver, int loop)
{
	int 	index;
	int 	i;

	if (is_sort(ps))
	{
		ft_printf("{grn}>>>>>>>>>>>>>>>>>SORTED<<<<<<<<<<<<<<<<<{no}\n");
		pathcpy(solver, &(solver->sol));
		return (1);
	}
	if (loop > solver->max)
	{
		ft_printf("max reached\n");
		return (0);
	}
	put_path(solver->path);
	index = 0;
	i = 0x400;
	while (index < NB_MOVE)
	{
		ft_printf("core => move: %s  loop: %d max: %d\n", ps->handlers[index].ope, loop, solver->max);
		if (!(i & ps->handlers[index].oppo) && ps->handlers[index].f(&(ps->a), &(ps->b)))
		{
			ft_printf("move done\n");
			put_lists(ps);
			add_to_path(ps, solver, index);
			if (solver_core(ps, solver, loop + 1))
				return (1);
			remove_from_path(ps, solver, ps->handlers[index].reverse);
			put_lists(ps);
		}
		else
			ft_printf("move skipped\n");
		index++;
		i >>= 1;
	}
	return (0);
}
