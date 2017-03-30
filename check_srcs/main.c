/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/30 20:47:20 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
		if (res > 2147483647 || (sign < 0 && res > 2147483648))
			return (0);
		i++;
	}
	*a = sign * res;
	return (str[i] ? 0 : 1);
}

static int				add_elem(t_list **l, int data)
{
	t_list *elm;

	if (!(elm = ft_lstnew((void*)&data, sizeof(int))))
		return (0);
	ft_lstpushback(l, elm);
	return (1);
}

void					free_int(void *data, size_t size)
{
	(void)size;
	free(data);
}

int						main(int argc, char **argv)
{
	t_ps		ps;
	int			data;
	int			index;

	if (argc == 1)
		return (1);
	ft_bzero(&ps, sizeof(t_ps));
	index = 1;
	while (index < argc)
	{
		if (!ft_myatoi(argv[index++], &data) || !add_elem(&(ps.a), data))
		{
			ft_lstdel(&(ps.a), free_int);
			ft_fprintf(2, "Error\n");
			while (1);
			return (0);
		}
	}
	if (!checker_core(&ps))
	{
		while (1);
		return (1);
	}
	if (is_sort(&ps))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstdel(&(ps.a), free_int);
	ft_lstdel(&(ps.b), free_int);
	while (1);
	return (0);
}
