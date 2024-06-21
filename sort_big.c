/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:11:13 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/14 15:11:15 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_min_max(t_nbrs nbr_a, t_list *stack_b)
{
	t_nbrs target;

	target.content = find_max(stack_b);
	target.rotations = find_index(stack_b, target.content);
	check_median(stack_b, &target);
	if (target.median == true)
		target.rotations = ft_lstsize(stack_b) - target.rotations;
	return(def_moves(&nbr_a, &target));
}

int	check_close(t_nbrs nbr_a, t_list *stack_b)
{
	t_list	*temp_b;
	t_nbrs	nbr_b;

	temp_b = stack_b;
	nbr_b.content = find_min(stack_b);
	while (temp_b)
	{
		if (nbr_a.content > temp_b->content)
		{
			if (nbr_b.content < temp_b->content)
				nbr_b.content = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	nbr_b.rotations = find_index(stack_b, nbr_b.content);
	check_median(stack_b, &nbr_b);
	if (nbr_b.median == true)
		nbr_b.rotations = ft_lstsize(stack_b) - nbr_b.rotations;
	return (def_moves(&nbr_a, &nbr_b));
}

t_nbrs	check_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_a;
	t_nbrs	chosen_one;
	int	moves;
	int	cheapest;

	temp_a = stack_a;
	cheapest = 0;
	chosen_one.rotations = 0;
	while (temp_a)
	{
		if (temp_a->content > find_max(stack_b) || temp_a->content < find_min(stack_b))
			moves = check_min_max(chosen_one, stack_b);
		else
			moves = check_close(chosen_one, stack_b);
		if (cheapest > moves || chosen_one.rotations == 0)
		{
			cheapest = moves;
			chosen_one.content = temp_a->content;
			chosen_one.rotations = find_index(stack_a, temp_a->content);	
			check_median(stack_a, &chosen_one);
			if (chosen_one.median == true)
				chosen_one.rotations = ft_lstsize(stack_a) - chosen_one.rotations;
		}
		temp_a = temp_a->next;
	}
	return (chosen_one);
}

t_nbrs	find_target(long chosen_one, t_list *stack_b)
{
	t_nbrs	target;
	t_list	*temp;

	temp = stack_b;
	if (chosen_one > find_max(stack_b) || chosen_one < find_min(stack_b))
	{
		target.content = find_max(stack_b);
		target.rotations = find_index(stack_b, target.content);
		check_median(stack_b, &target);
		if (target.median == true)
			target.rotations = ft_lstsize(stack_b) - target.rotations;
		return (target);
	}
	target.content = find_min(stack_b);
	while (temp)
	{
		if (chosen_one > temp->content)
		{
			if (target.content < temp->content)
				target.content = temp->content;
		}
		temp = temp->next;
	}
	target.rotations = find_index(stack_b, target.content);
	check_median(stack_b, &target);
	if (target.median == true)
		target.rotations = ft_lstsize(stack_b) - target.rotations;
	return (target);
}

void	sort_it_all(t_list **stack_a, t_list **stack_b)
{
	t_utils	values;
	t_nbrs	chosen_one;
	t_nbrs	target;

	if (ft_lstsize(*stack_a) && check_order(*stack_a))
		ft_push(stack_a, stack_b, 'b');
	if (ft_lstsize(*stack_a) && check_order(*stack_a))
		ft_push(stack_a, stack_b, 'b');
	values.stack_size = ft_lstsize(*stack_a);
	while (values.stack_size > 3)
	{
		chosen_one = check_cost(*stack_a, *stack_b);
		target = find_target(chosen_one.content, *stack_b);
		finally_sorting(chosen_one, target, stack_a, stack_b);
		values.stack_size = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	if (check_order(*stack_a))
		finish_sort(stack_a);
}
