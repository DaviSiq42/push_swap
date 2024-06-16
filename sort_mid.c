/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:05:01 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/11 16:05:03 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_and_push4(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = find_index(*stack_a, find_min(*stack_a));
	if (i == 0)
		ft_push(stack_a, stack_b, 'b');
	else if (i == 1)
	{
		ft_swap(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else if (i == 2)
	{
		ft_rotate(stack_a, 'a');
		ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else if (i == 3)
	{
		ft_reverse_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		free_list(stack_a);
	check_and_push4(stack_a, stack_b);
	sort_three(stack_a);
	ft_push(stack_a, stack_b, 'a');
}

void	check_and_push5(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = find_index(*stack_a, find_min(*stack_a));
	if (i <= 2)
		check_and_push4(stack_a, stack_b);
	else if (i == 3)
	{
		ft_reverse_rotate(stack_a, 'a');
		ft_reverse_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else if (i == 4)
	{
		ft_reverse_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		free_list(stack_a);
	check_and_push5(stack_a, stack_b);
	check_and_push4(stack_a, stack_b);
	sort_three(stack_a);
	ft_push(stack_a, stack_b, 'a');
	ft_push(stack_a, stack_b, 'a');
}
