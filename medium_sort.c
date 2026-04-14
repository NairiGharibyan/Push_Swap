/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:43:59 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/14 21:44:17 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_node **a, t_node **b, t_config *config)
{
	int	size;
	int	chunk;
	int	pushed;

	assign_index(*a);
	size = stack_size(*a);
	chunk = chunk_size(size);
	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, 1, config);
			rb(b, 1, config);
			pushed++;
		}
		else if ((*a)->index <= (pushed + chunk))
		{
			pb(a, b, 1, config);
			pushed++;
		}
		else
			ra(a, 1, config);
	}
	push_back_to_a(a, b, config);
}
