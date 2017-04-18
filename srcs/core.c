/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/18 19:07:10 by cbarbier         ###   ########.fr       */
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

int				init_solver(t_ps *ps, t_solver *solver)
{
	ft_bzero(solver, sizeof(t_solver));
	solver->max = ft_lstlen(ps->a);
	solver->max *= solver->max;
	return (1);
}

int				solver_core(t_ps *ps, t_solver *solver, int index_handler, int loop)
{
	int 	index;
	int 	i;

	if (loop > solver->max)
		return (0);
	if (is_sort(ps))
	{
		solver->max = loop;
		solver->sol = ft_lstcpy(solver->path);
		return (0);
	}
	put_lists(ps);
	ps->handlers[index_handler].f(&(ps->a), &(ps->b));
	add_to_path(ps, solver);
	index = 0;
	i = 0x400;
	while (index < NB_MOVE)
	{
		if (!(i & ps->handlers[index_handler].oppo))
			if (!solver_core(ps, solver, index, loop + 1))
				remove_from_path(ps, solver);
		index++;
		i >>= 1;
	}
	return (0);
}
