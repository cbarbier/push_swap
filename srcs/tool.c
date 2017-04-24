/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/24 14:33:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				add_to_path(t_ps *ps, t_solver *solver, int index)
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

int				get_mina(t_ps *ps, t_list *a)
{
	int			min;
	int			tmp;

	min = ps->maxa;
	while (a)
	{
		if ((tmp = *((int *)(a->content))) < min)
			min = tmp; 
		a = a->next;
	}
	return (min);
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
