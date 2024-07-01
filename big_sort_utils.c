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
		chosen->rotations = median_a;
		chosen->median = true;
		chosen->cost = median_a + target->rotations;
	}
	else if (chosen->rotations + median_b < chosen->cost)
	{
		chosen->cost = chosen->rotations + median_b;
		target->rotations = median_b;
		target->median = true;
	}
	else if (median_a + median_b < chosen->cost)
	{
		chosen->rotations = median_a;
		chosen->median = true;
		chosen->cost = median_a + median_b;
		target->rotations = median_b;
		target->median = true;
	}
	else
		chosen->median = false;
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
//	int	min_b;

//	min_b = find_min(*stack_b);
	if (chosen_one.median == target.median)
	{
		while (chosen_one.rotations != 0 && target.rotations != 0)
		{
			if (chosen_one.median == true)
				ft_reverse_rotateboth(stack_a, stack_b);
			else
				ft_rotateboth(stack_a, stack_b);
			chosen_one.rotations--;
			target.rotations--;
		}
	}
	sorting(&chosen_one, stack_a, 'a');
	sorting(&target, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
/*	if (chosen_one.content < min_b)
		ft_rotate(stack_b, 'b');*/
}

void	sending_back(t_nbrs chosen_one, t_nbrs target, t_list **stack_b, t_list **stack_a)
{	
//	int	max_a;

//	max_a = find_max(*stack_a);
	if (chosen_one.median == target.median)
	{
		while (chosen_one.rotations != 0 && target.rotations != 0)
		{
			if (chosen_one.median == true)
				ft_reverse_rotateboth(stack_a, stack_b);
			else
				ft_rotateboth(stack_a, stack_b);
			chosen_one.rotations--;
			target.rotations--;
		}
	}
	sorting(&chosen_one, stack_b, 'b');
	sorting(&target, stack_a, 'a');
	ft_push(stack_a, stack_b, 'a');
/*	if (chosen_one.content > max_a)
		ft_rotate(stack_a, 'a');*/
}

void	find_chosen_b(t_list *stack_a, t_list *stack_b, t_nbrs *chosen, t_nbrs *target)
{
	t_list *head_b;
	int	lower_cost;

	head_b = stack_b;
	lower_cost = INT_MAX;
	chosen->content = head_b->content;
	chosen->rotations = find_index(stack_b, chosen->content);
	while (head_b)
	{
		if (head_b->content > find_max(stack_a))
		{
			chosen->cost++;
			if_limit(chosen, stack_a, target, 0);
		}
		else if (head_b->content < find_min(stack_a))
			if_limit(chosen, stack_a, target, 0);
		else if (head_b->content > find_min(stack_a) && head_b->content < find_max(stack_a))
			if_btw_a(chosen, stack_a, target);
		if (lower_cost > chosen->cost)
		{
			chosen->content = head_b->content;
			lower_cost = chosen->cost;
		}
		head_b = head_b->next;
	}
	chosen->rotations = find_index(stack_b, chosen->content);
	if (chosen->content < find_min(stack_a) || chosen->content > find_max(stack_a))
		if_limit(chosen, stack_a, target, 0);
	else if (chosen->content > find_min(stack_a) && chosen->content < find_max(stack_a))
		if_btw_a(chosen, stack_a, target);
}
