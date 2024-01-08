/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_phase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:30:31 by arlarzil          #+#    #+#             */
/*   Updated: 2024/01/08 14:13:43 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

static void	calc_and_execute_cheapest(t_list *a, t_list *b)
{
	int	i;
	int	cur_nb;

	i = 0;
	cur_nb = b->l[b->i - 1];
	if (is_minmax(b->l[b->i - 1], a))
		while (a->l[(a->i - 1 + i) % a->i] > a->l[(a->i + i) % a->i])
			++i;
	else
		while (a->l[(a->i - 1 + i) % a->i] < cur_nb
			|| a->l[(a->i + i) % a->i] > cur_nb)
			++i;
	if (i < a->i / 2)
		while (i--)
			rra(a, b, 1);
	else
		while (i++ < a->i)
			ra(a, b, 1);
	pa(a, b, 1);
}

static void	final_phase(t_list *a)
{
	int	min_index;

	min_index = a->i - 1;
	while (a->l[min_index] != 0)
		--min_index;
	if (min_index >= a->i / 2)
		while (a->l[a->i - 1])
			ra(a, NULL, 1);
	else
		while (a->l[a->i - 1])
			rra(a, NULL, 1);
}

void	sort_second_phase(t_list *a, t_list *b)
{
	if (a->i == 0)
		pa(a, b, 1);
	while (b->i)
		calc_and_execute_cheapest(a, b);
	final_phase(a);
}
