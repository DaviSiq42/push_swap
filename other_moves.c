/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:07:39 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/10 16:07:40 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack_a, char c)
{
	t_list	*temp;
	t_list	*tail;
	
	temp = *stack_a;
	tail = ft_lstlast(*stack_a);
	while (temp->next != tail)
		temp = temp->next;
	tail->next = *stack_a;
	temp->next = NULL;
	*stack_a = tail;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_reverse_rotateboth(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a, '\0');
	ft_reverse_rotate(stack_b, '\0');
	ft_printf("rrr\n");
}

void	ft_push(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	if (c == 'a' && head_b)
		ft_lstadd_front(stack_a, head_b);
	else if (c == 'b' && head_a)
		ft_lstadd_front(stack_b, head_a);
}
