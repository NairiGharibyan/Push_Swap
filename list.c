/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:06:55 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/06 19:14:01 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!head || !new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}
