/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:59:35 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/09 19:12:44 by nagharib         ###   ########.fr       */
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
t_node		*build_stack(int *arr, int size);
t_node		*parse_arguments(int argc, char **argv);
int     isnum(char *str);
int		check_duplicate(t_node *head, long num);
int		is_valid_input(char *str, t_node *stack_a)
void	free_list(t_node *head);
void	add_back(t_node **head, t_node *new);
void    parse_flags(int argc, char **argv, t_config *config)
void	sa(t_node **stack_a, int print_flag);
void	sb(t_node **stack_b, int print_flag);
void	ss(t_node **a, t_node **b, int print_flag);
void	pb(t_node **stack_a, t_node **stack_b, int print_flag);
void	pa(t_node **stack_a, t_node **stack_b, int print_flag);
long    atol(const char *nptr);
static int	process_argument(char *arg, t_node **stack_a);
#endif
