/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:51:12 by arlarzil          #+#    #+#             */
/*   Updated: 2024/01/04 14:51:13 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	get_pos(int n, t_list *l)
{
	int	i;

	i = 0;
	while (l->l[i] != n)
		++i;
	return (l->i - (i + 1));
}

int	get_smallest(t_list *l)
{
	int	i;
	int	ret;

	i = 1;
	ret = l->l[0];
	while (i < l->i)
	{
		if (l->l[i] < ret)
			ret = l->l[i];
		++i;
	}
	return (ret);
}
