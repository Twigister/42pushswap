/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:51:03 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/12 23:51:05 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>
#include <unistd.h>

static int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

int	parse_single(const char *ar, t_list *a, t_list *b)
{
	char	**tab;
	int		len;

	tab = ft_split(ar, ' ');
	len = count_tab(tab);
	init(len, a, b);
	while (a->i < len)
	{
		if (!check_number(tab[a->i]))
		{
			write(2, "Error\n", 6);
			free_split(tab);
			return (free_and_exit(a->l, b->l));
		}
		a->l[a->i] = ft_atoi(tab[len - a->i - 1]);
		++(a->i);
	}
	free_split(tab);
	return (1);
}

int	parse_normal(int ac, char **av, t_list *a, t_list *b)
{
	init(ac - 1, a, b);
	while (a->i < ac - 1)
	{
		if (!check_number(av[ac - a->i - 1]))
		{
			write(2, "Error\n", 6);
			return (free_and_exit(a->l, b->l));
		}
		a->l[a->i] = ft_atoi(av[ac - a->i - 1]);
		++(a->i);
	}
	return (1);
}
