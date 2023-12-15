/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:23:00 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/07 09:20:40 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ps_sort.h"

static void	sort2(t_list *a)
{
	if (a->l[0] < a->l[1])
		sa(a, NULL, 1);
}

static void	sort3(t_list *a)
{
	if (a->l[2] > a->l[1] && a->l[1] < a->l[0] && a->l[2] < a->l[0])
		sa(a, NULL, 1);
	else if (a->l[2] > a->l[1] && a->l[1] > a->l[0] && a->l[2] > a->l[0])
		sa(a, NULL, 1);
	else if (a->l[2] < a->l[1] && a->l[1] > a->l[0] && a->l[2] < a->l[0])
		sa(a, NULL, 1);
}

void	replace_number_by_indexes(int len, int *list, int *cur)
{
	int	smaller_numbers;
	int	i;

	smaller_numbers = 0;
	i = 0;
	while (i < len)
	{
		if (*cur > list[i])
			++smaller_numbers;
		++i;
	}
	if (cur != list + len - 1)
		replace_number_by_indexes(len, list, cur + 1);
	*cur = smaller_numbers;
}

void	ps_sort(t_list *a, t_list *b)
{
	if (is_sorted(a))
		return ;
	if (a->i == 2)
	{
		sort2(a);
		return ;
	}
	replace_number_by_indexes(a->i, a->l, a->l);
	if (a->i > 3)
		sort_first_phase(a, b);
	sort3(a);
	sort_second_phase(a, b);
}
