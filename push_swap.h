/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:59:35 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/08 14:51:20 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_config
{
	int		algo_type;
	int		bench_mod;
	int		start_idx;
	float	disorder;
}	t_config;

typedef struct s_node
{
	int				value;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

t_node		*new_node(int value);
void	add_back(t_node **head, t_node *new);
t_node		*build_stack(int *arr, int size);
void	free_list(t_node *head);
int     isnum(char *str);
long    atol(const char *nptr);
static int	process_argument(char *arg, t_node **stack_a);
t_node		*parse_arguments(int argc, char **argv);
void    parse_flags(int argc, char **argv, t_config *config)
int		check_duplicate(t_node *head, long num);
int		is_valid_input(char *str, t_node *stack_a)
// sb
#endif
