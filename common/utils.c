/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:42:45 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/14 20:53:28 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	char	*e;

	e = s;
	while (*e)
		++e;
	return (e - s);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
