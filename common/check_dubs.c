/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dubs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:26:33 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/23 12:33:09 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	check_dubs(const int *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (l[i] == l[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
