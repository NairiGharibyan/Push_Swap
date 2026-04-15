/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:11:42 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/15 15:33:29 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_buckets(t_config *config)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(config->op_counts[0], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(config->op_counts[1], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(config->op_counts[2], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(config->op_counts[3], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(config->op_counts[4], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(config->op_counts[5], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(config->op_counts[6], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(config->op_counts[7], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(config->op_counts[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(config->op_counts[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(config->op_counts[10], 2);
	ft_putstr_fd("\n", 2);
}

static void	print_dis_perc(double x)
{
	int	x_whole;
	int	dec_part;

	x = x + 0.005;
	x_whole = (int)x;
	dec_part = (int)((x - x_whole) * 100);
	ft_putnbr_fd(x_whole, 2);
	ft_putchar_fd('.', 2);
	if (dec_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
}

static char	*get_algo_name(int type)
{
	if (type == 1)
		return ("[bench] strategy: Simple / O(n^2)");
	if (type == 2)
		return ("[bench] strategy: Medium / O(n sqrt n)");
	if (type == 3)
		return ("[bench] strategy: Complex / O(n log n)");
	return ("[bench] strategy: Adaptive / ");
}

void	print_benchmark(t_config *config)
{
	int		total;
	int		i;
	char	*complex[4];

	complex[1] = "O(n^2)";
	complex[2] = "O(n sqrt n)";
	complex[3] = "O(n log n)";
	total = 0;
	i = -1;
	while (++i < 11)
		total += config->op_counts[i];
	ft_putstr_fd("[bench] disorder: ", 2);
	print_dis_perc(config->disorder * 100.0);
	ft_putstr_fd(get_algo_name(config->algo_type), 2);
	if (config->algo_type == 4 || config->algo_type == 0)
		ft_putstr_fd(complex[config->effective_algo], 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_buckets(config);
}
