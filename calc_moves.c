/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:13:59 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/19 21:14:01 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	def_moves(t_nbrs *a, t_nbrs *b)
{
	int	moves;

	moves = 0;
	if (a->rotations > 0 && b->rotations > 0)
	{
		if (a->median == b->median)
		{
			if (a->rotations < b->rotations)
				moves = a->rotations;
			else
				moves = b->rotations;
		}
		else
			moves = a->rotations + b->rotations;
	}
	else if (a->rotations == 0)
		moves = b->rotations;
	else
		moves = a->rotations;
	return (++moves);
}
