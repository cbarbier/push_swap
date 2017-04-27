/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:25:08 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 07:54:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static int		calc_move_helper(t_mvto *tmp, t_ps *ps, t_list *b, int lnb)
{
	int		index;
	int		bf;
	int		cr;

	index = 0;
	bf = get_last(ps->b);
	while (b)
	{
		cr = *((int *)(b->content));
		if (cr > bf && (tmp->val < ps->minb || tmp->val > ps->maxb))
			break ;
		else if (tmp->val < bf && tmp->val > cr)
			break ;
		index++;
		bf = cr;
		b = b->next;
	}
	tmp->nb_b = (index <= lnb / 2 ? index : lnb - index);
	tmp->ope_b = (index <= lnb / 2 ? 6 : 9);
	return (1);
}

static int		calc_move(t_ps *ps, t_mvto *tmp, int index, int *l)
{
	int		opti;

	opti = 0;
	tmp->nb_a = (index <= l[0] / 2 ? index : l[0] - index);
	tmp->ope_a = (index <= l[0] / 2 ? 5 : 8);
	calc_move_helper(tmp, ps, ps->b, l[1]);
	if (tmp->ope_a == tmp->ope_b - 1)
		opti = (tmp->nb_a < tmp->nb_b ? tmp->nb_a : tmp->nb_b);
	tmp->tot = tmp->nb_a + tmp->nb_b - opti + 1;
	if (!index || tmp->tot < ps->mv_to_do->tot)
		return (1);
	return (0);
}

int				search_best_move(t_ps *ps, t_solver *solver)
{
	int			lns[2];
	int			index;
	t_mvto		tmp;
	t_list		*a;

	(void)solver;
	lns[0] = ft_lstlen(ps->a);
	lns[1] = ft_lstlen(ps->b);
	index = 0;
	a = ps->a;
	ps->lastb = get_last(ps->b);
	ps->minb = get_sides(ps->b, 0);
	ps->maxb = get_sides(ps->b, 1);
	while (a)
	{
		ft_bzero(&tmp, sizeof(t_mvto));
		tmp.val = *((int *)(a->content));
		if (calc_move(ps, &tmp, index, lns))
			ft_memcpy(ps->mv_to_do, &tmp, sizeof(t_mvto));
		index++;
		a = a->next;
	}
	return (1);
}
