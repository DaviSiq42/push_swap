/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:21:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/26 23:21:14 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	choose(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	def_moves(t_nbrs chosen, t_nbrs target)
{
	int	median_a;
	int	median_b;
	int	moves;

	median_a = chosen.lstsize - chosen.rotations;
	median_b = target.lstsize - target.rotations;
	moves = 0;
	if (chosen.rotations >= chosen.lstsize / 2 && target.rotations >= target.lstsize / 2)
		moves = choose(median_a, median_b);
	else if (chosen.rotations > chosen.lstsize / 2 && target.rotations < target.lstsize / 2)
		moves = median_a + target.rotations;
	else if (chosen.rotations < chosen.lstsize / 2 && target.rotations > target.lstsize / 2)
		moves = median_b + chosen.rotations;
	else
		moves = choose(chosen.rotations, target.rotations);
	return (moves);
}

int	def_cost(t_nbrs chosen, t_nbrs target)
{
	int	median_a;
	int	median_b;
	int	moves;

	median_a = chosen.lstsize - chosen.rotations;
	median_b = target.lstsize - target.rotations;
	moves = 0;
	if (chosen.rotations != 0 && target.rotations != 0)
		moves = def_moves(chosen, target);
	else
	{
		if (chosen.rotations > chosen.lstsize / 2)
			moves = median_a;
		else if (target.rotations > target.lstsize / 2)
			moves = median_b;
		else
			moves = choose(chosen.rotations, target.rotations);
	}
	return (++moves);
}
