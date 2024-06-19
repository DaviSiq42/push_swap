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

int	check_min_max(t_nbrs *nbr_a, t_list *stack_b)
{
	t_nbrs target;

	target.rotations = find_index(stack_b, find_max(stack_b));
	check_median(stack_b, &target);
	return(def_moves(nbr_a, &target));
}

int	check_close(t_nbrs *nbr_a, t_list *stack_b)
{
	t_list	*temp_b;
	t_nbrs	nbr_b;

	temp_b = stack_b;
	nbr_b.content = find_min(stack_b);
	while (temp_b)
	{
		if (nbr_a->content > temp_b->content)
		{
			if (nbr_b.content < temp_b->content)
				nbr_b.content = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	nbr_b.rotations = find_index(stack_b, nbr_b.content);
	check_median(stack_b, &nbr_b);
	return (def_moves(nbr_a, &nbr_b));
}

t_nbrs	check_cost(t_list *stack_a, t_list *stack_b, t_nbrs *chosen_one)
{
	t_list	*temp_a;
	int	moves;
	int	cheapest;

	temp_a = stack_a;
	cheapest = 0;
	chosen_one->rotations = 0;
	chosen_one->median = false;
	while (temp_a)
	{
		if (temp_a->content > find_max(stack_b) || temp_a->content < find_min(stack_b))
			moves = check_min_max(chosen_one, stack_b);
		else
			moves = check_close(chosen_one, stack_b);
		if (cheapest > moves || chosen_one->rotations == 0)
		{
			cheapest = moves;
			chosen_one->rotations = find_index(stack_a, temp_a->content);
			check_median(stack_a, chosen_one);
			chosen_one->content = temp_a->content;
		}
		temp_a = temp_a->next;
	}
	return (*chosen_one);
}

void	sort_it_all(t_list **stack_a, t_list **stack_b)
{
	t_utils	values;
	t_nbrs	chosen_one;
//	t_nbrs	target;

	if (ft_lstsize(*stack_a) && check_order(*stack_a))
		ft_push(stack_a, stack_b, 'b');
	if (ft_lstsize(*stack_a) && check_order(*stack_a))
		ft_push(stack_a, stack_b, 'b');
	values.stack_size = ft_lstsize(*stack_a);
	while (values.stack_size > 3)
	{
		chosen_one = check_cost(*stack_a, *stack_b, &chosen_one);
		ft_printf ("%d\n", chosen_one.content);
	}
}
