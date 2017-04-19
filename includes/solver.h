/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/19 14:26:33 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "push_swap.h"
# include "../libft/includes/libft.h"

typedef struct	s_path
{
	char			ope[3];
	struct s_path	*prec;
	struct s_path	*next;
}				t_path;
typedef struct	s_solver
{
	t_path		*sol;
	t_path		*path;
	t_path		*last;
	int			max;
}				t_solver;
int				init_solver(t_ps *ps, t_solver *solver, t_path **start);
int				solver_core(t_ps *ps, t_solver *solver, int i, int l);
int				add_to_path(t_ps *ps, t_solver *solver, int index);
int				remove_from_path(t_ps *ps, t_solver *solver, int i);
int				print_sol(t_solver *solver);
int				pathcpy(t_solver *solver, t_path **sol);
int				free_path(t_path *path);

#endif
