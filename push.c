/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:35:37 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/15 15:29:30 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pb(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config)
{
	do_push(stack_a, stack_b);
	config->op_counts[4]++;
	if (print_flag == 1)
		write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config)
{
	do_push(stack_b, stack_a);
	config->op_counts[3]++;
	if (print_flag == 1)
		write(1, "pa\n", 3);
}
