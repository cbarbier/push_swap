/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/30 16:48:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NB_MOVE	11
# include "../libft/includes/libft.h"

typedef struct		s_pshandler
{
	char	ope[3];
	void	(*f)(t_list **a, t_list **b);
}					t_pshandler;

typedef struct		s_ps
{
	t_pshandler	handlers[NB_MOVE];
	t_list		*a;
	t_list		*b;
}					t_ps;

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

#endif
