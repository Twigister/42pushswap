/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:03:58 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/12 22:04:53 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

void	dump_list(t_list *l)
{
	int	i;

	i = l->i - 1;
	__builtin_printf("Len: %d | ", l->i);
	while (i >= 0)
	{
		__builtin_printf("[%d]", l->l[i]);
		--i;
	}
	__builtin_printf("\n");
}

void	dump_it(t_list *a, t_list *b)
{
	__builtin_printf("Uh oh\n\t");
	dump_list(a);
	__builtin_printf("\t");
	dump_list(b);
}

void	temp_function_is_bs(t_four_scenarios *s)
{
	__builtin_printf("Cost summary:\n\tra: %d\n\t", s->ra_c);
	__builtin_printf("rb: %d\n\t", s->rb_c);
	__builtin_printf("rra: %d\n\trrb: %d\n", s->rra_c, s->rrb_c);
	__builtin_printf("According to our calculations, \
		the best scenario is %d with %d moves\n", s->best_scenario, s->len);
}
