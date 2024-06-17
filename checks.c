/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:37:32 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/03 19:37:34 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (EXIT_FAILURE);
		stack_a = stack_a->next;
	}
	return (EXIT_SUCCESS);
}

void	check_twins(t_list *stack_a)
{
	long	temp;

	temp = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		if (temp = stack_a->content)
		{
			ft_printf("Error\n");
			free_list(&stack_a);
		}
		temp = stack_a->content;
		stack_a = stack_a->next;
	}
}
