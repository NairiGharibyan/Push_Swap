/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:49:09 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/15 00:14:30 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_node **a, t_config *config)
{
    t_node  *highest;

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
