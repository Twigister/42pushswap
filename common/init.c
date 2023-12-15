/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:01:41 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/06 21:40:38 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

int	init(size_t list_size, t_list *a, t_list *b)
{
	a->l = malloc(sizeof(int) * (list_size));
	b->l = malloc(sizeof(int) * (list_size));
	a->i = 0;
	b->i = 0;
	if (!a->l || !b->l)
	{
		free(a->l);
		free(b->l);
		return (0);
	}
	return (1);
}
