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

int	*manage_numbers(

int	main(int argc, char **argv)
{
	t_stacks	sort;
	int		i;

	i = 0;
	if (argc < 3)
		ft_printf("Not enough arguments");
	else
	{
		sort.stack_a = malloc((argc - 1) * sizeof(int));
		if (!sort.stack_a)
		{
			ft_printf("Error while allocating stack_a");
			return (0);
		}
		while (argv[++i])
			sort.stack_a[i - 1] = argv[i];
	}
	return (0);
}

