/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:13:59 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/19 21:14:01 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	def_cost(t_nbrs *chosen, t_nbrs *target)
{
	int	median_a;
	int	median_b;

	median_a = chosen->lstsize - chosen->rotations;
	median_b = target->lstsize - target->rotations;
	chosen->cost = chosen->rotations + target->rotations;
	if (median_a + target->rotations < chosen->cost)
	{
		chosen->median = true;
		chosen->cost = median_a + target->rotations;
	}
	else if (chosen->rotations + median_b < chosen->cost)
	{
		chosen->cost = chosen->rotations + median_b;
		target->median = true;
	}
	else if (median_a + median_b < chosen->cost)
	{
		chosen->median = true;
		chosen->cost = median_a + median_b;
		target->median = true;
	}
	else
		chosen->median = false;
}

void	sorting(t_nbrs nbr, t_list **stack, char c)
{
	while (nbr.content != (*stack)->content)
	{
		if (nbr.median == true)
			ft_reverse_rotate(stack, c);
		else
			ft_rotate(stack, c);
	}
}

void	finally_sorting(t_nbrs chosen_one, t_nbrs target, t_list **stack_a, t_list **stack_b)
{
	int	min_b;

	min_b = find_min(*stack_b);
	while (chosen_one.content != (*stack_a)->content && target.rotations != (*stack_b)->content)
	{
		if (chosen_one.median == true && target.median == true)
			ft_reverse_rotateboth(stack_a, stack_b);
		else if (chosen_one.median == false && target.median == false)
			ft_rotateboth(stack_a, stack_b);
		else if (chosen_one.median == false && target.median == true)
			ft_rotate(stack_a, 'a');
		else if (chosen_one.median == true && target.median == false)
			ft_rotate(stack_b, 'b');
	}
	if (chosen_one.content != (*stack_a)->content)
		sorting(chosen_one, stack_a, 'a');
	else if (target.content != (*stack_b)->content)
		sorting(target, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	if (chosen_one.content < min_b)
		ft_rotate(stack_b, 'b');
}
