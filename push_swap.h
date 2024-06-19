/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:50:59 by davioliv          #+#    #+#             */
/*   Updated: 2024/05/28 15:52:22 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_nbrs
{
	int	content;
	int	rotations;
	bool	median;
}		t_nbrs;

typedef struct s_utils
{
	int	stack_size;
}		t_utils;

void	ft_swap(t_list **stack_a, char c);
void	ft_swapboth(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack_a, char c);
void	ft_rotateboth(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack_a, char c);
void	ft_reverse_rotateboth(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_a, t_list **stack_b, char c);
void	sort_time(t_list **stack_a, t_list **stack_b);
t_list	*set_stack(char **argv, t_list *stack_a);
long	find_min(t_list *stack);
long	find_max(t_list *stack);
int	find_index(t_list *stack, long nbr);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_it_all(t_list **stack_a, t_list **stack_b);
t_nbrs	check_cost(t_list *stack_a, t_list *stack_b);
int	check_close(t_nbrs nbr_a, t_list *stack_b);
int	check_min_max(t_nbrs nbr_a, t_list *stack_b);
int	check_arg(char **argv);
int	def_moves(t_nbrs *a, t_nbrs *b);
void	check_and_push4(t_list **stack_a, t_list **stack_b);
void	check_and_push5(t_list **stack_a, t_list **stack_b);
void	ft_min_in_first(t_list **stack_a);
void	ft_min_in_mid(t_list **stack_a);
void	ft_min_in_last(t_list **stack_a);
void	free_list(t_list **stack_a);
int	check_order(t_list *stack_a);
void	check_median(t_list *stack, t_nbrs *nbr);
int	check_twins(t_list *stack_a);

#endif
