/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/26 20:14:00 by cbarbier         ###   ########.fr       */
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
		put_lists(ps);
		search_best_move(ps, solver);
		ft_printf("best move : %d\n", ps->mv_to_do->val);
		apply_mvto(ps, solver);
		apply_move(ps, solver, 4);
	}
	ft_fprintf(2, "end of sorting , a is sorted\n");
	put_lists(ps);
	merge_list(ps, solver);
	return (0);
}
