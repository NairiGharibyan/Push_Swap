/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:27 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/07 21:09:46 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
    t_config    config;
    t_node      *stack_a;

    config.algo_type = 4;   
    config.bench_mode = 0;
    config.start_idx = 1;
    config.disorder = 0.0;

    if (argc < 2)
        return (0);
    stack_a = parse_arguments(argc, argv);
    if (!stack_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    // disorderi stugum
    // solve_push_swap(stack_a); 
    free_list(stack_a);
    return (0);
}
