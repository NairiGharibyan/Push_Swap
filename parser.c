/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:25:48 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/12 20:13:04 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 11) == 0)
			config->bench_mod = 1;
		else if (ft_strncmp(argv[i], "--simple", 11) == 0)
			config->algo_type = 1;
		else if (ft_strncmp(argv[i], "--medium", 11) == 0)
			config->algo_type = 2;
		else if (ft_strncmp(argv[i], "--complex", 11) == 0)
			config->algo_type = 3;
		else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			config->algo_type = 4;
		else
			break ;
		i++;
	}
	config->start_idx = i;
}
