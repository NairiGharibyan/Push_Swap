/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:27 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/15 20:55:30 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_node		*stack_a;
	t_node		*stack_b;

	if (argc < 2)
		return (0);
	init_config(&config);
	parse_flags(argc, argv, &config);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv, &config);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	config.disorder = compute_disorder(stack_a);
	if (is_sorted(stack_a))
		return (free_list(stack_a), free_list(stack_b), 0);
	else if (stack_size(stack_a) <= 5)
		sort_5(&stack_a, &stack_b, &config);
	else
		select_algorithm(&config, &stack_a, &stack_b);
	if (config.bench_mod == 1)
		print_benchmark(&config);
	return (free_list(stack_a), free_list(stack_b), 0);
}
