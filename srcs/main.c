/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/27 09:40:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

static int				ft_myatoi(char *str, int *a)
{
	unsigned int	res;
	unsigned int	i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-' ? -1 : 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + str[i] - '0';
		if ((sign > 0 && res > 2147483647) || (sign < 0 && res > 2147483648))
			return (0);
		i++;
	}
	*a = sign * res;
	return (str[i] ? 0 : 1);
}

static int				add_elem(t_ps *ps, t_list **l, int data)
{
	static int		count = 0;
	t_list			*elm;

	if (!count || data > ps->maxa)
		ps->maxa = data;
	if (!count || data < ps->mina)
		ps->mina = data;
	if (!(elm = ft_lstnew((void*)&data, sizeof(int))))
		return (0);
	ft_lstpushback(l, elm);
	count++;
	return (1);
}

void					free_int(void *data, size_t size)
{
	(void)size;
	free(data);
}

static void				ps_core(t_ps *ps, t_solver *solver)
{
	if (ft_lstlen(ps->a) <= 5)
	{
		init_bf(ps, solver, &(solver->sol));
		while (!brute_force(ps, solver, 0))
			++solver->max;
	}
	else
		my_algo(ps, solver);
	print_path(solver->path);
	free_path(solver->path);
}

int						main(int argc, char **argv)
{
	t_ps		ps;
	t_solver	solver;
	int			data;
	int			index;

	if (argc == 1)
		return (1);
	ft_bzero(&ps, sizeof(t_ps));
	index = 1;
	while (index < argc)
	{
		if (!ft_myatoi(argv[index++], &data) || is_in_list(ps.a, &data)
				|| !add_elem(&ps, &(ps.a), data))
		{
			ft_lstdel(&(ps.a), free_int);
			ft_fprintf(2, "Error\n");
			return (1);
		}
	}
	init_handlers(&ps);
	ps_core(&ps, &solver);
	return (0);
}
