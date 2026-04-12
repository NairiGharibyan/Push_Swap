/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:30:47 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/12 20:14:11 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack)
{
	int		min;
	t_node	*current;

	if (stack)
		return (0);
	min = stack -> value;
	current = stack;
	while (current)
	{
		if (current->value > min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_index(t_node *stack, int value)
{
	int		index;
	t_node	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	bring_min_to_top(t_node **stack)
{
	int	min;
	int	index;
	int	size;

	min = find_min(*stack);
	index = get_index(*stack, min);
	size = stack_size(*stack);
	if (index <= size / 2)
	{
		while ((*stack)->value != min)
			ra(stack, 1);
	}
	else
	{
		while ((*stack)->value != min)
			rra(stack, 1);
	}
}

void	simple_sort(t_node **a, t_node **b)
{
	while (*a)
	{
		bring_min_to_top(a);
		pb(a, b, 1);
	}
	while (*b)
		pa(a, b, 1);
}
