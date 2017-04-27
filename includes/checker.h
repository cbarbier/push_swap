/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 17:25:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/includes/libft.h"
# define NB_MOVE	11
# define DEBUG		1

typedef struct	s_pshandler
{
	char	ope[3];
	void	(*f)(t_list **a, t_list **b);
	int		oppo;
	int		reverse;
}				t_pshandler;

typedef struct	s_ps
{
	t_pshandler	handlers[NB_MOVE];
	t_list		*a;
	t_list		*b;
}				t_ps;

void			ps_move_sa(t_list **a, t_list **b);
void			ps_move_sb(t_list **a, t_list **b);
void			ps_move_ss(t_list **a, t_list **b);
void			ps_move_pa(t_list **a, t_list **b);
void			ps_move_pb(t_list **a, t_list **b);
void			ps_move_ra(t_list **a, t_list **b);
void			ps_move_rb(t_list **a, t_list **b);
void			ps_move_rr(t_list **a, t_list **b);
void			ps_move_rra(t_list **a, t_list **b);
void			ps_move_rrb(t_list **a, t_list **b);
void			ps_move_rrr(t_list **a, t_list **b);
int				init_handlers(t_ps *ps);
int				call_handler(t_ps *ps, char *ope);
void			free_int(void *data, size_t size);
int				is_sort(t_ps *ps);
int				checker_core(t_ps *ps);

#endif
