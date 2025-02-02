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

long	find_max(t_list *stack)
{
	long	max;

	max = stack->content;
	while (stack != NULL)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	find_index(t_list *stack, long nbr)
{
	int		index;
	t_list	*temp;

	index = 0;
	temp = stack;
	while (temp->content != nbr)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

/*void	check_median(t_list *stack, t_nbrs *nbr)
{
	if (find_index(stack, nbr->content) > ft_lstsize(stack) / 2)
		nbr->median = true;
	else
		nbr->median = false;
}

void	clean_struct(t_nbrs *stru, t_list *stack)
{
	stru->content = '\0';
	stru->median = false;
	stru->rotations = '\0';
	stru->lstsize = ft_lstsize(stack);
	stru->cost = 0;
}*/
