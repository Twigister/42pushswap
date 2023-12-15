/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:09:32 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/23 12:37:40 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_list *l)
{
	int	i;

	i = l->i;
	while (i > 1)
	{
		ft_swap(l->l + i - 1, l->l + i - 2);
		i--;
	}
}

void	ra(t_list *la, t_list *lb, int echo)
{
	(void)lb;
	rotate(la);
	if (echo)
		ft_putstr("ra\n");
}

void	rb(t_list *la, t_list *lb, int echo)
{
	(void)la;
	rotate(lb);
	if (echo)
		ft_putstr("rb\n");
}

void	rr(t_list *la, t_list *lb, int echo)
{
	rotate(lb);
	rotate(la);
	if (echo)
		ft_putstr("rr\n");
}
