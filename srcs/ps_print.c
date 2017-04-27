/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:42:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 18:52:44 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static int		put_header(t_ps *ps, char *ope)
{
	if (ps->opt_c)
	{
		ft_printf("{red}%13s{yel}%7s{grn}%12s\n", "stack a", ope, "stack b");
		ft_printf("\e[0;36m %s\n", "_____________________________________");
	}
	else
	{
		ft_printf("%13s%7s%12s\n", "stack a", ope, "stack b");
		ft_printf(" %s\n", "_____________________________________");
	}
	return (1);
}

int				put_lists(t_ps *ps, char *ope)
{
	t_list	*a;
	t_list	*b;

	a = ps->a;
	b = ps->b;
	put_header(ps, ope);
	while (a || b)
	{
		if (a)
			ft_printf("|%15d  |  ", *((int *)(a->content)));
		else
			ft_printf("|%15c  |  ", ' ');
		if (b)
			ft_printf("%15d  |\n", *((int *)(b->content)));
		else
			ft_printf("%15c  |\n", ' ');
		a = (a ? a->next : 0);
		b = (b ? b->next : 0);
	}
	ft_printf(" %s{no}\n", "_____________________________________");
	return (1);
}

int				ps_print(t_ps *ps, char *ope)
{
	int		d;
	int		index;
	char	up[3];

	if (!(ps->opt_c || ps->opt_v))
		return (0);
	index = -1;
	d = 50;
	usleep(100000);
	while (d--)
		ft_printf("\n\n\n");
	if (ps->opt_c)
	{
		ft_bzero(up, 3 * sizeof(char));
		while (ope[++index])
			up[index] = ft_toupper(ope[index]);
		put_lists(ps, up);
	}
	else
		put_lists(ps, "   ");
	usleep(100000);
	return (1);
}
