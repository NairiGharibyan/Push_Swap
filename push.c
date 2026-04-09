/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:35:37 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/08 17:57:45 by nagharib         ###   ########.fr       */
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

void	pb(t_node **stack_a, t_node **stack_b, int print_flag)
{
	do_push(stack_a, stack_b);
	if (print_flag == 1)
		write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b, int print_flag)
{
	do_push(stack_b, stack_a);
	if (print_flag == 1)
		write(1, "pa\n", 3);
}
