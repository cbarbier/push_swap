/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:12:26 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/26 20:59:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int		rotate_a(t_ps *ps, int val, int option)
{
	t_list	*a;
	int		index;
	int		ln;

	a = ps->a;
	ln = ft_lstlen(a);
	index = 0;
	while (a && ((option && *((int *)(a->content)) != val)
				|| (!option &&  *((int *)(a->content)) < val)))
	{
		index++;
		a = a->next;
	}
	ps->mv_to_do->nb_a = (index <= ln / 2 ? index : ln - index);
	ps->mv_to_do->ope_a = (index <= ln / 2 ? 5 : 8);
	return (1);
}

static int		rotate_b(t_ps *ps)
{
	t_list	*b;
	int		index;
	int		ln;

	b = ps->b;
	ps->minb = get_sides(b, 1);
	ft_fprintf(2, "max b: %d\n\n", ps->minb);
	ln = ft_lstlen(b);
	index = 0;
	while (b)
	{
		if (*((int *)(b->content)) == ps->minb)
			break;
		index++;
		b = b->next;
	}
	ps->mv_to_do->nb_b = (index <= ln / 2 ? index : ln - index);
	ps->mv_to_do->ope_b = (index <= ln / 2 ? 6 : 9);
	return (1);
}

int				merge_list(t_ps *ps, t_solver *solver)
{
	int		index;

	rotate_b(ps);
	ft_fprintf(2, "init merge nb_a: %d ope_a: %d\n", ps->mv_to_do->nb_a, ps->mv_to_do->ope_a);
	ft_fprintf(2, "init merge nb_b: %d ope_b: %d\n", ps->mv_to_do->nb_b, ps->mv_to_do->ope_b);
	apply_mvto(ps, solver);
	put_lists(ps);
	index = 0;
	while (ps->b)
	{
		apply_move(ps, solver, 3);
		index++;
	}
	return (1);
}
