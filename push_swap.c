/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:50:40 by davioliv          #+#    #+#             */
/*   Updated: 2024/05/28 16:15:20 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_stack(t_list **stack_a)
{
	int	l;

	if (!stack_a)
		free_list(stack_a);
	l = ft_lstsize(*stack_a);
	if (l == 2)
		sort_two(stack_a);
/*	if (l == 3)
		sort_three(stack_a);*/
}

t_list	*set_stack(char **argv, t_list *stack_a)
{
	t_list	*head;
	int	i;

	i = 2;
	stack_a = NULL;
	head = NULL;
	stack_a = ft_lstnew(ft_atoi(argv[i - 1]));
	head = stack_a;
	while (argv[i])
	{
		stack_a->next = ft_lstnew(ft_atoi(argv[i]));
		stack_a = stack_a->next;
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
//	t_list	*stack_b;

	stack_a = NULL;
//	stack_b = ft_lstnew(NULL);
	if (argc < 2)
		ft_printf("Not enough arguments");
	else
		stack_a = set_stack(argv, stack_a);
	check_stack(&stack_a);
	free_list(&stack_a);
	return (0);
}

