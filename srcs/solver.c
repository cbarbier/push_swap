/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:53:52 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/31 17:56:51 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				init_solver(t_ps *ps, t_solver *solver)
{
	ft_bzero(solver, sizeof(t_solver));
	max = ft_lstlen(ps->a);
	max *= max;
	return (1);
}


