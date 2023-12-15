/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:19:10 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/07 09:12:14 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>

typedef struct s_list {
	int	*l;
	int	i;
}	t_list;

int		check_dubs(const int *l, size_t len);
int		check_number(const char *s);
int		ft_atoi(const char *s);
int		is_sorted(t_list *a);

int		init(size_t size, t_list *a, t_list *b);
int		free_and_exit(int *a, int *b);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_swap(int *n1, int *n2);	

void	sa(t_list *la, t_list *lb, int echo);
void	sb(t_list *la, t_list *lb, int echo);
void	ss(t_list *la, t_list *lb, int echo);
void	pa(t_list *la, t_list *lb, int echo);
void	pb(t_list *la, t_list *lb, int echo);
void	ra(t_list *la, t_list *lb, int echo);
void	rb(t_list *la, t_list *lb, int echo);
void	rr(t_list *la, t_list *lb, int echo);
void	rra(t_list *la, t_list *lb, int echo);
void	rrb(t_list *la, t_list *lb, int echo);
void	rrr(t_list *la, t_list *lb, int echo);

char	**ft_split(const char *s, char c);
char	**free_split(char **tab);

int		parse_normal(int ac, char **av, t_list *a, t_list *b);
int		parse_single(const char *ar, t_list *a, t_list *b);

#endif
