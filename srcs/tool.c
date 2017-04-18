/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/31 17:56:49 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				add_to_path(t_ps *ps, t_solver *solver)
{
	t_list *elm;
	char	*ope;

	ope = ps->handler[index].ope;

	if (!(elm = ft_lstnew(((void *)ope, sizeof(int))))
		return (0);
	ft_lstpushback(&(solver->path), elm);
	return (1);
}

int				remove_from_path(t_ps *ps, t_solver *solver)
{
	
}
	
