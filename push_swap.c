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

void	sort_time(t_list **stack_a, t_list **stack_b)
{
	int	l;

	if (!stack_a)
		free_list(stack_a);
	l = ft_lstsize(*stack_a);
	if (l == 2)
		sort_two(stack_a);
	if (l == 3)
		sort_three(stack_a);
	if (l == 4)
		sort_four(stack_a, stack_b);
	if (l == 5)
		sort_five(stack_a, stack_b);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < 0 || argv[i][j] > 9)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
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
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || check_arg(argv))
		ft_printf("Error\n");
	else
		stack_a = set_stack(argv, stack_a);
	check_twins(stack_a);
	check_order(stack_a);
	sort_time(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}

