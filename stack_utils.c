/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:49:09 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/15 20:52:41 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_node **a, t_node **b, t_config *config)
{
	while (stack_size(*a) > 3)
	{
		bring_min_to_top(a, config);
		pb(a, b, 1, config);
	}
	sort_three(a, config);
	pa(a, b, 1, config);
	pa(a, b, 1, config);
}

void	sort_three(t_node **a, t_config *config)
{
	t_node	*highest;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	highest = find_max_node(*a);
	if (*a == highest)
		ra(a, 1, config);
	else if ((*a)->next == highest)
		rra(a, 1, config);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1, config);
}
