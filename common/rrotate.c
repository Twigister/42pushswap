/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:59:36 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/23 11:39:29 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rrotate(t_list *l)
{
	int	i;

	i = 0;
	while (i < l->i - 1)
	{
		ft_swap(l->l + i, l->l + i + 1);
		++i;
	}
}

void	rra(t_list *la, t_list *lb, int echo)
{
	(void)lb;
	rrotate(la);
	if (echo)
		ft_putstr("rra\n");
}

void	rrb(t_list *la, t_list *lb, int echo)
{
	(void)la;
	rrotate(lb);
	if (echo)
		ft_putstr("rrb\n");
}

void	rrr(t_list *la, t_list *lb, int echo)
{
	rrotate(lb);
	rrotate(la);
	if (echo)
		ft_putstr("rrr\n");
}
