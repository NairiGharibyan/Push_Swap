/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:39:10 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/08 17:32:37 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psuh_swap.h"

static void	do_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack_a, int print_flag)
{
	do_swap(stack_a);
	if (print_flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, int print_flag)
{
	do_swap(stack_b);
	if (print_flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int print_flag)
{
	do_swap(a);
	do_swap(b);
	if (print_flag == 1)
		write(1, "ss\n", 3);
}
