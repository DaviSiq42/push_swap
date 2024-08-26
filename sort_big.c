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

int	if_limit(t_nbrs chosen, t_list *stack_b)
{
	t_nbrs	target;

	target.content = find_max(stack_b);
	target.lstsize = ft_lstsize(stack_b);
	target.rotations = find_index(stack_b, target.content);
	return (def_cost(chosen, target));
}

int	if_btw(t_nbrs chosen, int nbr_a, t_list *stack_b)
{
	t_list	*head_b;
	t_nbrs	target;

	target.content = find_min(stack_b);
	target.lstsize = ft_lstsize(stack_b);
	head_b = stack_b;
	while (head_b)
	{
		if (nbr_a > head_b->content && target.content < head_b->content)
			target.content = head_b->content;
		head_b = head_b->next;
	}
	target.rotations = find_index(stack_b, target.content);
	return (def_cost(chosen, target));
}

t_nbrs	find_chosen_a(t_list *stack_a, t_list *stack_b, t_nbrs a_test)
{
	t_list	*head_a;
	t_nbrs	chosen;
	int		lower_cost;

	head_a = stack_a;
	lower_cost = 0;
	chosen.lstsize = ft_lstsize(stack_a);
	while (head_a != NULL)
	{
		if (head_a->content < find_min(stack_b)
			|| head_a->content > find_max(stack_b))
			chosen.cost = if_limit(a_test, stack_b);
		else if (head_a->content > find_min(stack_b)
			&& head_a->content < find_max(stack_b))
			chosen.cost = if_btw(a_test, head_a->content, stack_b);
		if (lower_cost > chosen.cost || a_test.rotations == 0)
		{
			lower_cost = chosen.cost;
			chosen.rotations = a_test.rotations;
			chosen.content = head_a->content;
		}
		head_a = head_a->next;
		a_test.rotations++;
	}
	return (chosen);
}

void	sort_it_all(t_list **stack_a, t_list **stack_b)
{
	t_nbrs	chosen;
	t_nbrs	target;
	t_nbrs	a_test;

	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	a_test.lstsize = ft_lstsize(*stack_a);
	a_test.rotations = 0;
	while (a_test.lstsize > 3)
	{
		chosen = find_chosen_a(*stack_a, *stack_b, a_test);
		target = set_target(*stack_b, chosen.content);
		finally_sorting(chosen, target, stack_a, stack_b);
		a_test.lstsize = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	sending_back(stack_b, stack_a);
	finish_sort(stack_a);
}
