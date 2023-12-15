/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:24:49 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/07 08:16:47 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <pushswap.h>
#include "ps_sort.h"

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;

	if (ac != 2 && !parse_normal(ac, av, &a, &b))
		return (0);
	else if (ac == 2 && !parse_single(av[1], &a, &b))
		return (0);
	if (ac > 1 && !check_dubs(a.l, a.i))
		ps_sort(&a, &b);
	else
		write(2, "Error\n", 6);
	return (free_and_exit(a.l, b.l));
}
