/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:11:42 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/12 20:10:01 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void     print_dis_perc(double x)
{
    int     x_whole;
    int  dec_part;
    x_whole = x;
    dec_part = (x - x_whole)*100;
    ft_putnbr_fd(x_whole, 2);
    ft_putchar_fd('.', 2);
    if (dec_part < 10)
        ft_putchar_fd('0', 2);
    ft_putnbr_fd(dec_part, 2);
    ft_putstr_fd("%\n", 2);
}
void    print_benchmark(t_config *config)
{
    int     i;
    int     total_ops;
    double  dis_perc;
    char	*algo_names[5];
    char    *complex[4];
    
    complex[1] = "O(n^2)";
    complex[2] = "O(n sqrt n)";
    complex[3] = "O(n log n)";

    algo_names[0] = "[bench] strategy: Adaptive / ";
	algo_names[1] = "[bench] strategy: Simple / O(n^2)\n";
	algo_names[2] = "[bench] strategy: Medium / O(n sqrt n)\n";
	algo_names[3] = "[bench] strategy: Complex / O(n log n)\n";
	algo_names[4] = "[bench] strategy: Adaptive / ";

    total_ops = 0;
    i = 0;
    dis_perc = (config->disorder)*100.0;
    while (i < 11)
    {
        total_ops += config->op_counts[i];
        i++;
    }
    ft_putstr_fd("[bench] disorder: ", 2);
    print_dis_perc(dis_perc);
    ft_putstr_fd(algo_names[config->algo_type], 2);
    if (config->algo_type == 4 || config->algo_type == 0)
        ft_putstr_fd(complex[config->effective_algo], 2);


}