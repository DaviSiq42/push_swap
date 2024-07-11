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

void	sorting(t_nbrs nbr, t_list **stack, char c)
{
	while (nbr.content != (*stack)->content)
	{
		if (nbr.rotations > nbr.lstsize / 2)
			ft_reverse_rotate(stack, c);
		else
			ft_rotate(stack, c);
	}
}

void	finally_sorting(t_nbrs chosen_one, t_nbrs target, t_list **stack_a, t_list **stack_b)
{
	while (chosen_one.content != (*stack_a)->content && target.content != (*stack_b)->content)
	{
		if (chosen_one.rotations > chosen_one.lstsize / 2 && target.rotations > target.lstsize / 2)
			ft_reverse_rotateboth(stack_a, stack_b);
		else if (chosen_one.rotations < chosen_one.lstsize / 2 && target.rotations > target.lstsize / 2)
			ft_rotate(stack_a, 'a');
		else if (chosen_one.rotations > chosen_one.lstsize / 2 && target.rotations < target.lstsize / 2)
			ft_rotate(stack_b, 'b');
		else
			ft_rotateboth(stack_a, stack_b);
	}
	if (chosen_one.content != (*stack_a)->content && target.content == (*stack_b)->content)
		sorting(chosen_one, stack_a, 'a');
	else if (target.content != (*stack_b)->content && chosen_one.content == (*stack_a)->content)
		sorting(target, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
}

t_nbrs	set_target(t_list *stack_b, int chosen)
{
	t_nbrs	target;
	t_list	*head_b;

	head_b = stack_b;
	if (chosen < find_min(stack_b) || chosen > find_max(stack_b))
	{
		target.content = find_max(stack_b);
		target.rotations = find_index(stack_b, target.content);
		target.lstsize = ft_lstsize(stack_b);
		return (target);
	}
	target.content = find_min(stack_b);
	while (head_b)
	{
		if (target.content < head_b->content && chosen > head_b->content)
			target.content = head_b->content;
		head_b = head_b->next;
	}
	target.lstsize = ft_lstsize(stack_b);
	target.rotations = find_index(stack_b, target.content);
	return (target);
}
