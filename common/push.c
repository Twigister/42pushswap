/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:53:34 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/14 19:58:57 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_list *source, t_list *dest)
{
	if (!source->i)
		return ;
	source->i--;
	dest->l[dest->i] = source->l[source->i];
	dest->i++;
}

void	pa(t_list *la, t_list *lb, int echo)
{
	push(lb, la);
	if (echo)
		ft_putstr("pa\n");
}

void	pb(t_list *la, t_list *lb, int echo)
{
	push(la, lb);
	if (echo)
		ft_putstr("pb\n");
}
