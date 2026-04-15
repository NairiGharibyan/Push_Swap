/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:34:07 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/15 15:34:08 by arpbabay         ###   ########.fr       */
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
	t_node *min_node;
	int size_a;

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