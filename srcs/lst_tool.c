/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:53:52 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/26 18:37:12 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int				is_in_list(t_list *a, int *data)
{
	while (a)
	{
		if (*((int *)(a->content)) == *data)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}

int				get_sides(t_list *l, int opt)
{
	int			val;
	int			tmp;	
	int			index;

	index = 0;
	val = 0;
	while (l)
	{
		if (!index)
			val = *((int *)(l->content));
		if ((!opt && (tmp = *((int *)(l->content))) < val)
				|| (opt && (tmp = *((int *)(l->content))) > val)) 
			val = tmp; 
		index++;
		l = l->next;
	}
	return (val);
}

int				get_last(t_list *l)
{
	if (!l)
		return (0);
	while(l->next)
	{
		l = l->next;
	}
	return (*((int *)(l->content)));
}
