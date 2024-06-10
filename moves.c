/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:54:18 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/02 17:54:26 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack_a, char c)
{
	long	buf;

	buf = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = buf;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	ft_swapboth(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a, '\0');
	ft_swap(stack_b, '\0');
	ft_printf("ss\n");
}

/*void	ft_rotate(t_list **stack_a, char c)
{
	t_list	*head;
	t_list	*tail;*/
