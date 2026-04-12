/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:27 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/10 17:42:53 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
    int     i;
    t_config    config;
    t_node      *stack_a;

    if (argc < 2)
        return (0);
    config.algo_type = 4;   
    config.bench_mode = 0;
    config.start_idx = 1;
    config.disorder = 0.0;
    i = 0;
    while(i < 0)
    {
        config.op_counts[i] = 0;
        i++;
    }

    parse_flags(argc, argv, &config);
    stack_a = parse_arguments(argc, argv, &config);
        if (!stack_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    select_algorithm(&config, stack_a);
    // disorderi stugum
    // solve_push_swap(stack_a); 
    free_list(stack_a);
    return (0);
}
