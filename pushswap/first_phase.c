/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_phase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 04:17:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/01/04 15:38:50 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"
#include <pushswap.h>
#include <stdlib.h>

// Seems OK
static int	get_best_scenario(t_four_scenarios *s)
{
	int	test_len;
	int	res;

	s->len = ft_min(s->ra_c, s->rb_c) + ft_abs(s->ra_c - s->rb_c);
	res = RARB;
	test_len = ft_min(s->rra_c, s->rrb_c) + ft_abs(s->rra_c - s->rrb_c);
	if (test_len < s->len)
	{
		s->len = test_len;
		res = RRARRB;
	}
	test_len = s->ra_c + s->rrb_c;
	if (test_len < s->len)
	{
		s->len = test_len;
		res = RARRB;
	}
	test_len = s->rra_c + s->rrb_c;
	if (test_len < s->len)
	{
		s->len = test_len;
		res = RRARB;
	}
	return (res);
}

static void	calc_cost(t_list *a, t_list *b, int index, t_four_scenarios *s)
{
	int	index_b;

	index_b = b->i - 1;
	s->ra_c = (a->i - 1) - index;
	s->rrb_c = 0;
	s->rra_c = ((a->i) - s->ra_c) * !!s->ra_c;
	if (!is_minmax(a->l[index], b))
	{
		while (!(b->l[index_b] < a->l[index] && \
			a->l[index] < b->l[(index_b + 1) % b->i]))
		{
			++(s->rrb_c);
			index_b = (index_b + 1) % b->i;
		}
	}
	else
	{
		while (b->l[index_b] < b->l[(index_b + 1) % b->i])
		{
			s->rrb_c += 1;
			index_b = (index_b + 1) % b->i;
		}
	}
	s->rb_c = ((b->i) - s->rrb_c) * !!s->rrb_c;
	s->best_scenario = get_best_scenario(s);
}

static void	calc_and_execute_cheapest(t_list *a, t_list *b)
{
	t_four_scenarios	*test;
	t_four_scenarios	*best;
	int					i;

	test = NULL;
	best = NULL;
	i = a->i - 1;
	while (i >= 0)
	{
		if (!test)
			test = malloc(sizeof(t_four_scenarios));
		if (!test)
		{
			free(best);
			return ;
		}
		calc_cost(a, b, i, test);
		if (!best || best->len > test->len)
			ft_swap_ptr((void *)&best, (void *)&test);
		--i;
	}
	free(test);
	execute_scenario(a, b, best);
	pb(a, b, 1);
	free(best);
}

void	sort_first_phase(t_list *a, t_list *b)
{
	int	target;

	target = a->i / 8;
	if (target < 3)
		target = 3;
	pb(a, b, 1);
	if (a->i > 3)
		pb(a, b, 1);
	while (a->i > target)
		calc_and_execute_cheapest(a, b);
}
