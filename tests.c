/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:57:16 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/24 16:57:19 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_limit(t_nbrs *chosen, t_list *stack_b, t_nbrs *target)
{
	target->content = find_max(stack_b);
	target->lstsize = ft_lstsize(stack_b);
	target->rotations = find_index(stack_b, target->content);
	target->median = false;
	def_cost(chosen, target);
}

void	if_btw(t_nbrs *chosen, t_list *stack_b, t_nbrs *target)
{
	t_list	*head_b;

	target->content = find_min(stack_b);
	target->lstsize = ft_lstsize(stack_b);
	head_b = stack_b;
	while (head_b)
	{
		if (target->content < head_b->content && chosen->content > head_b->content)
			target->content = head_b->content;
		head_b = head_b->next;
	}
	target->rotations = find_index(stack_b, target->content);
	def_cost(chosen, target);
}

void	find_chosen(t_list *stack_a, t_list *stack_b, t_nbrs *chosen, t_nbrs *target)
{
	t_list	*head_a;
	int	lower_cost;

	head_a = stack_a;
	lower_cost = INT_MAX;
	chosen->content = head_a->content;
	chosen->rotations = find_index(stack_a, chosen->content);
	while (head_a)
	{
		if (head_a->content < find_min(stack_b))
		{
			chosen->cost++;
			if_limit(chosen, stack_b, target);
		}
		else if (head_a->content > find_max(stack_b))
			if_limit(chosen, stack_b, target);
		else if (head_a->content > find_min(stack_b) && head_a->content < find_max(stack_b))
			if_btw(chosen, stack_b, target);
		if (lower_cost > chosen->cost)
		{
			chosen->content = head_a->content;
			lower_cost = chosen->cost;
		}
		head_a = head_a->next;
	}
	chosen->rotations = find_index(stack_a, chosen->content);
	if (chosen->content < find_min(stack_b) || chosen->content > find_max(stack_b))
		if_limit(chosen, stack_b, target);
	else if (chosen->content > find_min(stack_b) && chosen->content < find_max(stack_b))
		if_btw(chosen, stack_b, target);
}

void	sort_it_all(t_list **stack_a, t_list **stack_b)
{
	t_nbrs	chosen;
	t_nbrs	target;

	chosen.lstsize = ft_lstsize(*stack_a);
	target.lstsize = ft_lstsize(*stack_b);
	chosen.cost = 0;
	chosen.median = false;
	while (chosen.lstsize > 3)
	{
		find_chosen(*stack_a, *stack_b, &chosen, &target);
		finally_sorting(chosen, target, stack_a, stack_b);
		chosen.lstsize = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	target.lstsize = ft_lstsize(*stack_b);
	while (target.lstsize)
	{
		find_chosen(*stack_b, *stack_a, &target, &chosen);
		sending_back(chosen, target, stack_b, stack_a);
		target.lstsize = ft_lstsize(*stack_b);
	}
}
