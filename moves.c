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

void	ft_rotate(t_list **stack_a, char c)
{
	t_list	*head;
	t_list	*tail;

	head = *stack_a;
	tail = ft_lstlast(*stack_a);
	tail->next = head;
	head->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotateboth(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a, '\0');
	ft_rotate(stack_b, '\0');
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_list **stack_a, char c)
{
	t_list	*head;
	t_list	*tail;
	
	head = *stack_a;
	tail = ft_lstlast(*stack_a);
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next;
	tail->next = head;
	(*stack_a)->next = NULL;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
