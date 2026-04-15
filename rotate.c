/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:25:14 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/15 17:57:55 by nagharib         ###   ########.fr       */
/*   Updated: 2026/04/15 17:43:25 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **stack_a, int print_flag, t_config *config)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	do_rotate(stack_a);
	config->op_counts[5]++;
	if (print_flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, int print_flag, t_config *config)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	do_rotate(stack_b);
	config->op_counts[6]++;
	if (print_flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config)
{
	if (!*stack_a || !*stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	do_rotate(stack_a);
	do_rotate(stack_b);
	config->op_counts[7]++;
	if (print_flag == 1)
		write(1, "rr\n", 3);
}
