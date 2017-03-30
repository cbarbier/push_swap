/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:07:00 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/30 13:57:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static void		set_handler
		(t_pshandler *h, char *o, void (*f)(t_list **, t_list **))
{
	ft_strcpy(h->ope, o);
	h->f = f;
}
int				init_handlers(t_ps *ps)
{
	t_pshandler		*h;

	h = ps->handlers;
	ft_bzero(h, NB_MOVE * sizeof(t_pshandler));
	set_handler(h, "sa", ps_move_sa);
	set_handler(h + 1, "sb", ps_move_sb);
	set_handler(h + 2, "ss", ps_move_ss);
	set_handler(h + 3, "pa", ps_move_pa);
	set_handler(h + 4, "pb", ps_move_pb);
	set_handler(h + 5, "ra", ps_move_ra);
	set_handler(h + 6, "rb", ps_move_rb);
	set_handler(h + 7, "rr", ps_move_rr);
	set_handler(h + 8, "rra", ps_move_rra);
	set_handler(h + 9, "rrb", ps_move_rrb);
	set_handler(h + 10, "rrr", ps_move_rrr);
	return (1);
}

int				call_handler(t_ps *ps, char *ope)
{
	int			index;

	index = 0;
	while (index < NB_MOVE)
	{
		if (!ft_strcmp(ps->handlers[index].ope, ope))
		{
			ps->handlers[index].f(&(ps->a), &(ps->b));
			return (1);
		}
		index++;
	}
	return (0);
}
