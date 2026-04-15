/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_helpers1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:34:07 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/15 16:34:25 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node *stack)
{
	int		max;
	t_node	*current;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = stack->value;
	max_node = stack;
	current = stack;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

int	calculate_cost(int pos, int size)
{
	int	cost;

	if (pos <= size / 2)
		cost = pos;
	else
		cost = size - pos;
	return (cost);
}

void	set_all_targets(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target;
	long	best_match;

	curr_a = a;
	while (curr_a)
	{
		best_match = LONG_MIN;
		target = NULL;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < curr_a->value && curr_b->value > best_match)
			{
				target = curr_b;
				best_match = curr_b->value;
			}
			curr_b = curr_b->next;
		}
		if (target == NULL)
			target = find_max_node(b);
		curr_a->target_node = target;
		curr_a = curr_a->next;
	}
}

void	rotate_both_up(t_node **a, t_node **b, t_node *cheapest_node,
		t_config *config)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, 1, config);
}

void	rotate_both_down(t_node **a, t_node **b, t_node *cheapest_node,
		t_config *config)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, 1, config);
}
