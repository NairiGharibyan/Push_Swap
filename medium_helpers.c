/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:51:41 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/15 16:17:19 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a;
	while (current)
	{
		index = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	find_max(t_node *stack)
{
	int		max;
	t_node	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	bring_max_to_top(t_node **stack, t_config *config)
{
	int	max;
	int	index;
	int	size;

	if (!stack || !*stack)
		return ;
	max = find_max(*stack);
	index = get_index(*stack, max);
	size = stack_size(*stack);
	if (index <= size / 2)
	{
		while ((*stack)->value != max)
			rb(stack, 1, config);
	}
	else
	{
		while ((*stack)->value != max)
			rrb(stack, 1, config);
	}
}

void	push_back_to_a(t_node **a, t_node **b, t_config *config)
{
	while (*b)
	{
		bring_max_to_top(b, config);
		pa(a, b, 1, config);
	}
}

int	chunk_size(int s)
{
	int	c;

	c = 0;
	if (s <= 10)
		c = 2;
	else if (s <= 100)
		c = s / 6;
	else
		c = s / 14;
	return (c);
}
