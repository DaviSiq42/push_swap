/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:39:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/05 15:39:15 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if (!stack_a)
		free_list(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap(stack_a, 'a');
}

void	sort_three(t_list **stack_a)
{
	long	smaller;

	smaller = find_min(*stack_a);
	if (!stack_a)
		free_list(stack_a);
	if ((*stack_a)->content == smaller)
		ft_min_in_first(stack_a);
	else if ((*stack_a)->next->content == smaller)
		ft_min_in_mid(stack_a);
	else if ((*stack_a)->next->next->content == smaller)
		ft_min_in_last(stack_a);
}

void	ft_min_in_first(t_list **stack_a)
{
	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_reverse_rotate(stack_a, 'a');
		ft_swap(stack_a, 'a');
	}
}

void	ft_min_in_last(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap(stack_a, 'a');
	ft_reverse_rotate(stack_a, 'a');
}

void	ft_min_in_mid(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->next->content)
		ft_rotate(stack_a, 'a');
	else
		ft_swap(stack_a, 'a');
}
