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

int	check_twins(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (temp->content == stack_a->content)
			{
				ft_printf("Error\n");
				free_list(&stack_a);
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (EXIT_SUCCESS);
}

int	check_int_limits(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->content > INT_MAX || temp->content < INT_MIN)
		{
			ft_printf("Error\n");
			free_list(&stack_a);
			exit(EXIT_FAILURE);
		}
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
