/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:54:28 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/31 15:36:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static void		set_handler(t_pshandler *h, char *o,
		void (*f)(t_list **, t_list **), int oppo)
{
	ft_bzero(h->ope, sizeof(h->ope));
	ft_strcpy(h->ope, o);
	h->f = f;
	h->oppo = oppo;
}

int				init_handlers(t_ps *ps)
{
	t_pshandler		*h;

	h = ps->handlers;
	set_handler(h, "sa", ps_move_sa, 0x500);
	set_handler(h + 1, "sb", ps_move_sb, 0x300);
	set_handler(h + 2, "ss", ps_move_ss, 0x700);
	set_handler(h + 3, "pa", ps_move_pa, 0x40);
	set_handler(h + 4, "pb", ps_move_pb, 0x80);
	set_handler(h + 5, "ra", ps_move_ra, 0x5);
	set_handler(h + 6, "rb", ps_move_rb, 0x3);
	set_handler(h + 7, "rr", ps_move_rr, 0x7);
	set_handler(h + 8, "rra", ps_move_rra, 0x28);
	set_handler(h + 9, "rrb", ps_move_rrb, 0x18);
	set_handler(h + 10, "rrr", ps_move_rrr, 0x38);
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
