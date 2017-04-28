/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/04/28 18:56:41 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

static int				ft_myatoi(char *str, int *a)
{
	unsigned int	res;
	unsigned int	i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
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

static int				add_elem(t_list **l, int data)
{
	static int		count = 0;
	t_list			*elm;

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

static int				fct(void *content)
{
	int		i;

	i = *((int *)(content));
	return (i % 2 ? 1 : 0);
}

int						main(int argc, char **argv)
{
	t_list		*a;
	int			data;
	int			index;

	if (argc == 1)
		return (1);
	index = 1;
	a = 0;
	while (index < argc)
	{
		if (!ft_myatoi(argv[index++], &data) || !add_elem(&a, data))
		{
			ft_lstdel(&a, free_int);
			ft_fprintf(2, "Error\n");
			return (1);
		}
	}
	ft_lstdelif(&a, free_int, fct); 
	ft_printf("list a :\n");
	while (a)
	{
		ft_printf("%d\n", *((int *)(a->content)));
		a = a->next;
	}
	ft_lstdel(&a, free_int);
	return (0);
}
