/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:24:49 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/12 23:51:25 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <pushswap.h>
#include "get_next_line.h"
#include "pushswap_checker.h"

static char	*prep_str(char *s)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = s;
	while (*s)
	{
		if (*s == '\n')
			*s = 0;
		else
			++s;
	}
	return (ret);
}

static int	run_simu(t_list *a, t_list *b)
{
	const void *(funcs)[] = {sa, sb, ss, pa, pb, rra, rrb, rrr, ra, rb, rr};
	const char *(comps)[] = {"sa", "sb", "ss", "pa", "pb", \
		"rra", "rrb", "rrr", "ra", "rb", "rr", NULL};
	int (i);
	char *(s) = prep_str(get_next_line(0));
	while (s && s[0])
	{
		i = 0;
		while (1)
		{
			if (comps[i] == NULL)
				return (ERROR);
			else if (!ft_strcmp(s, comps[i]))
			{
				((void (*)(t_list *, t_list *, int))(funcs[i]))(a, b, 0);
				break ;
			}
			++i;
		}
		free(s);
		s = prep_str(get_next_line(0));
	}
	free(s);
	return (is_sorted(a) && b->i == 0);
}

static int	fill_tab(t_list *a, t_list *b, int ac, char **av)
{
	int	ret;

	if (ac == 2)
		ret = parse_single(av[1], a, b);
	else
		ret = parse_normal(ac, av, a, b);
	if (ret == 1)
		return (SUCCESS);
	return (ERROR);
}

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	int		simu_res;

	if (fill_tab(&a, &b, ac, av) == ERROR)
		return (free_and_exit(a.l, b.l));
	if (ac > 1 && !check_dubs(a.l, a.i))
		simu_res = run_simu(&a, &b);
	else
		simu_res = -1;
	if (simu_res == ERROR)
		write(2, "Error\n", 6);
	else if (simu_res == SUCCESS)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_and_exit(a.l, b.l));
}
