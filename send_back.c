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

static void	sort_limit(t_list **stack_a, t_list **stack_b, int size)
{
	int	position;

	position = find_index(*stack_a, find_min(*stack_a));
	while ((*stack_a)->content != find_min(*stack_a))
	{
		if (position > size / 2)
			ft_reverse_rotate(stack_a, 'a');
		else
			ft_rotate(stack_a, 'a');
	}
	ft_push(stack_a, stack_b, 'a');
}

static void	sort_btw(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head_a;
	int		position;
	int		target;

	target = find_max(*stack_a);
	head_a = *stack_a;
	while (head_a)
	{
		if (target > head_a->content && (*stack_b)->content < head_a->content)
			target = head_a->content;
		head_a = head_a->next;
	}
	position = find_index(*stack_a, target);
	while ((*stack_a)->content != target)
	{
		if (position > size / 2)
			ft_reverse_rotate(stack_a, 'a');
		else
			ft_rotate(stack_a, 'a');
	}
	ft_push(stack_a, stack_b, 'a');
}

void	sending_back(t_list **stack_b, t_list **stack_a)
{
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_a);
		if ((*stack_b)->content > find_max(*stack_a)
			|| (*stack_b)->content < find_min(*stack_a))
			sort_limit(stack_a, stack_b, size);
		else if ((*stack_b)->content < find_max(*stack_a)
			&& (*stack_b)->content > find_min(*stack_a))
			sort_btw(stack_a, stack_b, size);
	}
}
