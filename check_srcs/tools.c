/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:42:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/01 13:59:24 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int					set_opt(t_ps *ps, char **argv, int argc)
{
	int		index;
	int		index2;

	index = 1;
	while (index < argc && ft_strlen(argv[index]) >= 2
			&& argv[index][0] == '-')
	{
		index2 = 1;
		while (argv[index][index2])
		{
			if (argv[index][index2] == 'v')
				ps->opt_v = 1;
			else if (argv[index][index2] == 'c')
				ps->opt_c = 1;
			else if (argv[index][index2] == 'd')
				ps->opt_d = 1;
			else if (argv[index][index2] == 't')
				ps->opt_t = 1;
			else
				return (argv[index][index2] == '-' ? index + 1 : index);
			index2++;
		}
		index++;
	}
	return (index);
}

static int			put_header(t_ps *ps, char *ope)
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

static int			put_lists(t_ps *ps, char *ope)
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

int					ps_print(t_ps *ps, char *ope)
{
	int		d;
	int		index;
	char	up[3];

	if (!(ps->opt_c || ps->opt_v))
		return (0);
	index = -1;
	d = 50;
	usleep((ps->opt_t ? 500000 : 100000));
	while (d--)
		ft_printf("\n\n\n");
	if (ps->opt_d)
	{
		ft_bzero(up, 3 * sizeof(char));
		while (ope[++index])
			up[index] = ft_toupper(ope[index]);
		put_lists(ps, up);
	}
	else
		put_lists(ps, "   ");
	usleep((ps->opt_t ? 500000 : 100000));
	return (1);
}
