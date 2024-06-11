/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:08:54 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/05 16:08:55 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_min(t_list *stack)
{
	long	min;

	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	find_min_index(t_list *stack)
{
	int	index;
	long	min;

	min = find_min(stack);
	index = 0;
	while (stack->content != min)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}
