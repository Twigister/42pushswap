/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_checker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:21 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/23 11:18:05 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_CHECKER_H
# define PUSHSWAP_CHECKER_H

enum e_simu_return {
	SUCCESS = 1,
	FAILURE = 0,
	ERROR = -1
};

int	ft_strcmp(const char *a, const char *b);

#endif
