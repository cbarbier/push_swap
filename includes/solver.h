/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/26 20:14:15 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "../libft/includes/libft.h"
# define NB_MOVE	11
typedef struct	s_mvto
{
	int			nb_a;
	int			ope_a;
	int			nb_b;
	int			ope_b;
	int			val;
	int			tot;
}				t_mvto;
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
	int			topa;
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
	int			maxa;
	int			mina;
	int			minb;
	int			maxb;
	int			lastb;
	t_mvto		mv_to_do[1];
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
int				my_algo(t_ps *ps, t_solver *solver);
int				apply_move(t_ps *ps, t_solver *solver, int index);
int				apply_mvto(t_ps *ps, t_solver *solver);
int				remove_from_path(t_ps *ps, t_solver *solver, int i);
int				print_path(t_path *path);
int				free_path(t_path *path);
int				is_in_list(t_list *a, int *data);
int				put_lists(t_ps *ps);
int				get_sides(t_list *l, int opt);
int				search_best_move(t_ps *ps, t_solver *solver);
int				merge_list(t_ps *ps, t_solver *solver);
int				get_last(t_list *l);

#endif
