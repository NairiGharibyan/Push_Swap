/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sa_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:27:54 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/07 19:34:02 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a -> top;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	a -> top = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	write(1, "sb\n", 3);
}
