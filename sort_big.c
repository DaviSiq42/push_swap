/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:11:13 by davioliv          #+#    #+#             */
/*   Updated: 2024/06/14 15:11:15 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rotations(t_list *stack_a, t_list *stack_b, t_nbrs *candidate)
{
	if (stack_a->content < find_min(stack_b))
		candidate->moves =+ 2;
	else if (stack_a->content > find_max(stack_b))
		candidate->moves++;
	if (stack_a->content > find_min(stack_b) && stack_a->content < find_max(stack_b))
		
int	check_cost(t_list *stack_a, t_list *stack_b)
{
	t_nbrs	chosen_one;

	while (stack_a->next)
	{
		check_rotations(stack_a, stack_b, chosen_one);
			

void	sort_it_all(t_list **stack_a, t_list **stack_b)
{
	t_utils	values;

	if (ft_lstsize(*stack_a) && check_order(*stack_a))
		ft_push(stack_a, stack_b, 'b');
	if (ft_lstsize(*stack_a) && check_order(*stack_a))
		ft_push(stack_a, stack_b, 'b');
	values.stack_size = ft_lstsize(*stack_a);
	while (values.stack_size > 3)
	{
		
