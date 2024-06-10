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
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap(stack_a, 'a');
}

void	sort_three(t_list **stack_a)
{
	long	smaller;

	smaller = find_min(*stack_a);
}
