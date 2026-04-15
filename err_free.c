/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:32:25 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/15 18:16:24 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head -> next;
		free(tmp);
	}
}

void	error_exit(t_node *a, t_node *b)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	write(2, "Error\n", 6);
	exit(1);
}
