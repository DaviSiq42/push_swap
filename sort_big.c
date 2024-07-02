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

void	if_limit(t_nbrs *chosen, t_list *stack_b, t_nbrs *target, int flag)
{
	if (flag)
		target->content = find_max(stack_b);
	else
		target->content = find_min(stack_b);
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
	target->median = false;
	def_cost(chosen, target);
}

void	find_chosen_a(t_list *stack_a, t_list *stack_b, t_nbrs *chosen, t_nbrs *target)
{
	t_list	*head_a;
	int	lower_cost;
	int	rot;

	head_a = stack_a;
	lower_cost = INT_MAX;
	chosen->content = head_a->content;
	chosen->lstsize = ft_lstsize(stack_a);
	chosen->rotations = 0;
	rot = 0;
	while (head_a)
	{
		if (head_a->content < find_min(stack_b))
		{
//			chosen->cost++;
			if_limit(chosen, stack_b, target, 1);
		}
		else if (head_a->content > find_max(stack_b))
			if_limit(chosen, stack_b, target, 1);
		else if (head_a->content > find_min(stack_b) && head_a->content < find_max(stack_b))
			if_btw(chosen, stack_b, target);
//		ft_printf("%d\n", lower_cost);
		if (lower_cost > chosen->cost || rot == 0)
		{
			chosen->content = head_a->content;
			chosen->rotations = rot;
			lower_cost = chosen->cost;
		}
		head_a = head_a->next;
		rot++;
	}
	if (chosen->content < find_min(stack_b) || chosen->content > find_max(stack_b))
		if_limit(chosen, stack_b, target, 1);
	else if (chosen->content > find_min(stack_b) && chosen->content < find_max(stack_b))
		if_btw(chosen, stack_b, target);
}

void	sort_it_all(t_list **stack_a, t_list **stack_b)
{
	t_nbrs	chosen;
	t_nbrs	target;

	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	chosen.lstsize = ft_lstsize(*stack_a);
	target.lstsize = ft_lstsize(*stack_b);
	chosen.cost = 0;
	chosen.median = false;
	while (chosen.lstsize > 3)
	{
		find_chosen_a(*stack_a, *stack_b, &chosen, &target);
		finally_sorting(chosen, target, stack_a, stack_b);
		chosen.lstsize = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	clean_struct(&chosen);
	clean_struct(&target);
	chosen.lstsize = ft_lstsize(*stack_b);
	target.lstsize = ft_lstsize(*stack_a);
	while (chosen.lstsize)
	{
		find_chosen_b(*stack_a, *stack_b, &chosen, &target);
		sending_back(chosen, target, stack_b, stack_a);
		chosen.lstsize = ft_lstsize(*stack_b);
	}
	finish_sort(stack_a);
}
