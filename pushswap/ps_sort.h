/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:27:19 by arlarzil          #+#    #+#             */
/*   Updated: 2023/12/12 22:04:38 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_H
# define PS_SORT_H

# include <pushswap.h>
# define TARGET 100

enum e_scenarios {
	RARB,
	RARRB,
	RRARB,
	RRARRB
};

typedef struct s_four_scenarios {
	int	ra_c;
	int	rb_c;
	int	rra_c;
	int	rrb_c;
	int	best_scenario;
	int	len;
}	t_four_scenarios;

// Algos
void	ps_sort(t_list *a, t_list *b);
void	sort_first_phase(t_list *a, t_list *b);
void	sort_second_phase(t_list *a, t_list *b);

// Utils divers
void	ft_swap_ptr(void **a, void **b);
int		ft_abs(int n);
int		ft_min(int a, int b);
int		get_smallest(t_list *l);
int		get_pos(int n, t_list *l);

int		is_minmax(int n, t_list *l);
void	execute_scenario(t_list *a, t_list *b, t_four_scenarios *s);

// Debug
void	dump_list(t_list *l);
void	dump_it(t_list *a, t_list *b);
void	temp_function_is_bs(t_four_scenarios *s);

#endif
