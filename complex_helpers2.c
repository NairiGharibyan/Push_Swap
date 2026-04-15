/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:27:50 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/15 16:30:20 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **a, t_node *cheapest_node, t_config *config)
{
	int	size_a;

	size_a = stack_size(*a);
	if (cheapest_node->pos <= size_a / 2)
	{
		while (*a != cheapest_node)
			ra(a, 1, config);
	}
	else
	{
		while (*a != cheapest_node)
			rra(a, 1, config);
	}
}

void	rotate_b(t_node **b, t_node *target_node, t_config *config)
{
	int	size_b;

	size_b = stack_size(*b);
	if (target_node->pos <= size_b / 2)
	{
		while (*b != target_node)
			rb(b, 1, config);
	}
	else
	{
		while (*b != target_node)
			rrb(b, 1, config);
	}
}

t_node	*get_target_in_a(t_node *a, int b_value)
{
	t_node	*current;
	t_node	*target_node;
	long	best_match;

	current = a;
	target_node = NULL;
	best_match = LONG_MAX;
	while (current)
	{
		if (current->value > b_value && current->value < best_match)
		{
			best_match = current->value;
			target_node = current;
		}
		current = current->next;
	}
	if (target_node == NULL)
		target_node = find_min_node(a);
	return (target_node);
}

t_node	*find_min_node(t_node *stack)
{
	long	min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	final_alignment(t_node **a, t_config *config)
{
	t_node	*min_node;
	int		size_a;

	if (!a || !*a)
		return ;
	assign_pos(*a);
	size_a = stack_size(*a);
	min_node = find_min_node(*a);
	if (min_node->pos <= size_a / 2)
	{
		while (*a != min_node)
			ra(a, 1, config);
	}
	else
	{
		while (*a != min_node)
			rra(a, 1, config);
	}
}
