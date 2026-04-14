/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:11:15 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/15 00:13:25 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack_a)
{
	double		mistakes;
	double		total_pairs;
	t_node		*inner;
	t_node		*outer;

	mistakes = 0;
	total_pairs = 0;
	if (!stack_a || !stack_a->next)
		return (0.0);
	outer = stack_a;
	while(outer->next != NULL)
	{
		inner = outer->next;
		while(inner != NULL)
		{
			if(outer->value > inner->value)
				mistakes++;
			total_pairs++;
			inner = inner->next;
		}
	outer = outer->next;
	}
	return (mistakes / total_pairs);
}
void    select_algorithm(t_config *config, t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a || !config)
		return ;
	if (config->algo_type == 4)
	{
		config->disorder = compute_disorder(*stack_a);
	if (config->disorder < 0.2)
		config->effective_algo = 1;
	else if (config->disorder < 0.5)
		config->effective_algo = 2;
	else
		config->effective_algo = 3;
	}
	else
		config->effective_algo = config->algo_type;
	if (config->effective_algo == 1)
		simple_sort(stack_a, stack_b, config);
	else if (config->effective_algo == 2)
		medium_sort(stack_a, stack_b, config);
	else if (config->effective_algo == 3)
		complex_sort(stack_a, stack_b, config);
}
