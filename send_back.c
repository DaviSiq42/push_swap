/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:18:43 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/21 14:18:47 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_sort(t_list **stack_a)
{
	int	i;

	i = find_index(*stack_a, find_min(*stack_a));
	while (check_order(*stack_a))
	{
		if (i > ft_lstsize(*stack_a) / 2)
			ft_reverse_rotate(stack_a, 'a');
		else
			ft_rotate(stack_a, 'a');
	}
}

void	if_btw_a(t_nbrs *chosen, t_list *stack_a, t_nbrs *target)
{
	t_list	*head_a;

	target->content = find_max(stack_a);
	target->lstsize = ft_lstsize(stack_a);
	head_a = stack_a;
	while (head_a)
	{
		if (target->content > head_a->content && chosen->content < head_a->content)
			target->content = head_a->content;
		head_a = head_a->next;
	}
	target->rotations = find_index(stack_a, target->content);
	target->median = false;
	def_cost(chosen, target);
}

void	sending_back(t_nbrs chosen_one, t_nbrs target, t_list **stack_b, t_list **stack_a)
{
	while (chosen_one.content != (*stack_b)->content && target.rotations != (*stack_a)->content)
	{
		if (chosen_one.median == true && target.median == true)
			ft_reverse_rotateboth(stack_a, stack_b);
		else if (chosen_one.median == false && target.median == false)
			ft_rotateboth(stack_a, stack_b);
		else if (chosen_one.median == false && target.median == true)
			ft_rotate(stack_b, 'b');
		else if (chosen_one.median == true && target.median == false)
			ft_rotate(stack_a, 'a');
	}
	if (chosen_one.content != (*stack_b)->content)
		sorting(chosen_one, stack_b, 'b');
	else if (target.content != (*stack_a)->content)
		sorting(target, stack_a, 'a');
	ft_push(stack_a, stack_b, 'a');
}

void	find_chosen_b(t_list *stack_a, t_list *stack_b, t_nbrs *chosen, t_nbrs *target)
{
	t_list *head_b;
	int	lower_cost;

	head_b = stack_b;
	lower_cost = INT_MAX;
	chosen->content = head_b->content;
	chosen->rotations = find_index(stack_b, chosen->content);
	chosen->lstsize = ft_lstsize(stack_b);
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
