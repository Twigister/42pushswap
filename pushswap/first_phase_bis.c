/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_phase_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:14:39 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/12 22:14:40 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

int	is_minmax(int n, t_list *l)
{
	int	bigger_exists;
	int	smaller_exists;
	int	i;

	i = 0;
	bigger_exists = 0;
	smaller_exists = 0;
	while (i < l->i)
	{
		if (l->l[i] < n)
		{
			if (bigger_exists)
				return (0);
			smaller_exists = 1;
		}
		else if (l->l[i] > n)
		{
			if (smaller_exists)
				return (0);
			bigger_exists = 1;
		}
		++i;
	}
	return (1);
}

static void	execute_scenario_part2(t_list *a, t_list *b, t_four_scenarios *s)
{
	int	i;

	i = 0;
	if (s->best_scenario == RRARB)
	{
		while (i++ < s->rra_c)
			rra(a, b, 1);
		i = 0;
		while (i++ < s->rb_c)
			rb(a, b, 1);
	}
	else
	{
		while (i++ < ft_min(s->rra_c, s->rrb_c))
			rrr(a, b, 1);
		i = 0;
		if (s->rra_c > s->rrb_c)
			while (i++ < s->rra_c - s->rrb_c)
				rra(a, b, 1);
		else
			while (i++ < s->rrb_c - s->rra_c)
				rrb(a, b, 1);
	}
}

void	execute_scenario(t_list *a, t_list *b, t_four_scenarios *s)
{
	int	i;

	i = 0;
	if (s->best_scenario == RARB)
	{
		while (i++ < ft_min(s->ra_c, s->rb_c))
			rr(a, b, 1);
		i = 0;
		if (s->ra_c > s->rb_c)
			while (i++ < s->ra_c - s->rb_c)
				ra(a, b, 1);
		else
			while (i++ < s->rb_c - s->ra_c)
				rb(a, b, 1);
	}
	else if (s->best_scenario == RARRB)
	{
		while (i++ < s->ra_c)
			ra(a, b, 1);
		i = 0;
		while (i++ < s->rrb_c)
			rrb(a, b, 1);
	}
	else
		execute_scenario_part2(a, b, s);
}
