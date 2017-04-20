/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/20 15:05:54 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "../libft/includes/libft.h"
# define NB_MOVE	11

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
typedef struct	s_pshandler
{
	char	ope[3];
	int		(*f)(t_list **a, t_list **b);
	int		oppo;
	int		reverse;
}				t_pshandler;
typedef struct	s_ps
{
	t_pshandler	handlers[NB_MOVE];
	t_list		*a;
	t_list		*b;
}				t_ps;
int				ps_move_sa(t_list **a, t_list **b);
int				ps_move_sb(t_list **a, t_list **b);
int				ps_move_ss(t_list **a, t_list **b);
int				ps_move_pa(t_list **a, t_list **b);
int				ps_move_pb(t_list **a, t_list **b);
int				ps_move_ra(t_list **a, t_list **b);
int				ps_move_rb(t_list **a, t_list **b);
int				ps_move_rr(t_list **a, t_list **b);
int				ps_move_rra(t_list **a, t_list **b);
int				ps_move_rrb(t_list **a, t_list **b);
int				ps_move_rrr(t_list **a, t_list **b);
int				init_handlers(t_ps *ps);
int				call_handler(t_ps *ps, char *ope);
void			free_int(void *data, size_t size);
int				is_sort(t_ps *ps);
int				init_solver(t_ps *ps, t_solver *solver, t_path **start);
int				solver_core(t_ps *ps, t_solver *solver);
int				add_to_path(t_ps *ps, t_solver *solver, int index);
int				remove_from_path(t_ps *ps, t_solver *solver, int i);
int				print_sol(t_solver *solver);
int				pathcpy(t_solver *solver, t_path **sol);
int				free_path(t_path *path);

#endif
