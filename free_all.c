/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:09:20 by davioliv          #+#    #+#             */
/*   Updated: 2024/05/29 17:10:19 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (*stack)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
}
