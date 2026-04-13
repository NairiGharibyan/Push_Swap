/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:27 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/13 14:29:24 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_node		*stack_a;
	int			i;

	if (argc < 2)
		return (0);

	config.algo_type = 4;
	config.bench_mod = 0;
	config.start_idx = 1;
	config.disorder = 0.0;
	i = 0;
	while (i < 11)
		config.op_counts[i++] = 0;

	parse_flags(argc, argv, &config);
	stack_a = parse_arguments(argc, argv, &config);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	config.disorder = compute_disorder(stack_a);
	select_algorithm(&config, stack_a);
	if (config.bench_mod == 1)
		print_benchmark(&config);
	return (free_list(stack_a), 0);
}
