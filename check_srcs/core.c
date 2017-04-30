/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:55:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/28 15:44:09 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int				is_sort(t_ps *ps)
{
	t_list		*a;

	a = ps->a;
	while (a)
	{
		if (a->next && *((int *)(a->content)) > *((int *)(a->next->content)))
			return (0);
		a = a->next;
	}
	return (ps->b ? 0 : 1);
}

int				checker_core(t_ps *ps)
{
	char		*line;

	init_handlers(ps);
	ps_print(ps, "");
	while (get_next_line(0, &line) > 0)
	{
		if (!call_handler(ps, line))
		{
			ft_lstdel(&(ps->a), free_int);
			ft_lstdel(&(ps->b), free_int);
			ft_fprintf(2, "Error\n");
			ft_strdel(&line);
			return (0);
		}
		ps_print(ps, line);;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	get_next_line(-42, 0);
	return (1);
}
