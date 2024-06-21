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

int	def_moves(t_nbrs *a, t_nbrs *b)
{
	int	moves;

	moves = 0;
	if (a->rotations > 0 && b->rotations > 0)
	{
		if (a->median == b->median)
		{
			if (a->rotations > b->rotations)
				moves = a->rotations;
			else
				moves = b->rotations;
		}
		else
			moves = a->rotations + b->rotations;
	}
	else if (a->rotations == 0)
		moves = b->rotations;
	else
		moves = a->rotations;
	return (++moves);
}

void	sorting(t_nbrs *nbr, t_list **stack, char c)
{
	while (nbr->rotations--)
	{
		if (nbr->median == true)
			ft_reverse_rotate(stack, c);
		else
			ft_rotate(stack, c);
	}
}

void	finally_sorting(t_nbrs chosen_one, t_nbrs target, t_list **stack_a, t_list **stack_b)
{
	int	smallest;

	if (chosen_one.rotations > target.rotations)
		smallest = target.rotations;
	else
		smallest = chosen_one.rotations;
	if (chosen_one.median != target.median)
	{
		sorting(&chosen_one, stack_a, 'a');
		sorting(&target, stack_b, 'b');
		ft_push(stack_a, stack_b, 'b');
	}
	else
	{
		while (smallest--)
		{
			if (chosen_one.median == true)
				ft_reverse_rotateboth(stack_a, stack_b);
			else
				ft_rotateboth(stack_a, stack_b);
			chosen_one.rotations--;
			target.rotations--;
		}
		if (chosen_one.rotations)
			sorting(&chosen_one, stack_a, 'a');
		else
			sorting(&target, stack_b, 'b');
		ft_push(stack_a, stack_b, 'b');
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->content > find_max(*stack_a) || (*stack_b)->content < find_min(*stack_a))
			target_edges(stack_a, stack_b);
		else
			target_btw(stack_a, stack_b);
	}
}
