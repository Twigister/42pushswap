/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:41:58 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/23 11:39:38 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_list *l)
{
	if (l->i > 1)
		ft_swap(l->l + l->i - 1, l->l + l->i - 2);
}

void	sa(t_list *la, t_list *lb, int echo)
{
	(void)lb;
	swap(la);
	if (echo)
		ft_putstr("sa\n");
}

void	sb(t_list *la, t_list *lb, int echo)
{
	(void)la;
	swap(lb);
	if (echo)
		ft_putstr("sb\n");
}

void	ss(t_list *la, t_list *lb, int echo)
{
	swap(la);
	swap(lb);
	if (echo)
		ft_putstr("ss\n");
}
