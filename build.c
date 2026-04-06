/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:35:37 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/06 19:47:33 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*build_stack(int *arr, int size)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		add_back(&stack, new_node(arr[i]));
		i++;
	}
	return (stack);
}
