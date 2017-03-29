/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/29 17:13:00 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/includes/libft.h"

typedef struct		s_pshandler
{
	char	ope[3];
	void	(*f)(t_list *a, t_list *b);
}					t_pshandler;

typedef struct		s_ps
{
	t_list	*a;
	t_list	*b;
}					t_ps;

void			ps_move_sa(t_list **a, t_list **b)
void			ps_move_sb(t_list **a, t_list **b)
void			ps_move_ss(t_list **a, t_list **b)
void			ps_move_pa(t_list **a, t_list **b)
void			ps_move_pb(t_list **a, t_list **b)
void			ps_move_ra(t_list **a, t_list **b)
void			ps_move_rb(t_list **a, t_list **b)
void			ps_move_rr(t_list **a, t_list **b)
void			ps_move_rra(t_list **a, t_list **b)
void			ps_move_rrb(t_list **a, t_list **b)
void			ps_move_rrr(t_list **a, t_list **b)

#endif
