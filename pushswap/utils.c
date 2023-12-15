/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:06:56 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/12 22:06:57 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_swap_ptr(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
