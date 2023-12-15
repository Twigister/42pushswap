/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:56:24 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/23 11:34:04 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#define TOO_LARGE 2147483648

long	ft_atol(const char *s)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if ((*s == '-') || (*s == '+'))
		if (*(s++) == '-')
			sign = -1;
	while ('0' <= *s && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (TOO_LARGE);
		++s;
	}
	return (0);
}

int	check_number(char *s)
{
	long	n;

	n = ft_atol(s);
	if ((*s == '-') || (*s == '+'))
		++s;
	while ('0' <= *s && *s <= '9')
		++s;
	return (!*s && n != TOO_LARGE);
}
