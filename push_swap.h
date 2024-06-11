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

void	ft_swap(t_list **stack_a, char c);
void	ft_swapboth(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack_a, char c);
void	ft_rotateboth(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack_a, char c);
void	ft_reverse_rotateboth(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_a, t_list **stack_b, char c);
void	check_stack(t_list **stack_a, t_list **stack_b);
t_list	*set_stack(char **argv, t_list *stack_a);
long	find_min(t_list *stack);
int	find_min_index(t_list *stack);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	check_and_push(t_list **stack_a, t_list **stack_b);
void	ft_min_in_first(t_list **stack_a);
void	ft_min_in_mid(t_list **stack_a);
void	ft_min_in_last(t_list **stack_a);
void	free_list(t_list **stack_a);
/*typedef struct s_ps
{
	
}		t_ps;*/

#endif
