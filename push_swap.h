/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 19:05:38 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/14 15:27:21 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef enum e_ops
{
	SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}	t_ops;

typedef struct s_config
{
	int		algo_type;
	int		bench_mod;
	int		start_idx;
	int		effective_algo;
	int		op_counts[11];
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
t_node		*parse_arguments(int argc, char **argv, t_config *config);
int		chunk_size(int s);
int     isnum(char *str);
int		check_duplicate(t_node *head, long num);
int		stack_size(t_node *stack);
int		is_valid_input(char *str, t_node *stack_a);
int		is_sorted(t_node *stack);
int		get_index(t_node *stack, int value);
int		find_max(t_node *stack);
void	free_list(t_node *head);
void	add_back(t_node **head, t_node *new);
void    parse_flags(int argc, char **argv, t_config *config);
void    select_algorithm(t_config *config, t_node **stack_a, t_node **stack_b);
void	free_split(char **str);
void	print_benchmark(t_config *config);
void	simple_sort(t_node **a, t_node **b, t_config *config);
void	medium_sort(t_node **a, t_node **b, t_config *config);
void	complex_sort(t_node **a, t_node **b, t_config *config);
void	sa(t_node **stack_a, int print_flag, t_config *config);
void	sb(t_node **stack_b, int print_flag, t_config *config);
void	ss(t_node **a, t_node **b, int print_flag, t_config *config);
void	pa(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config);
void	pb(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config);
void	ra(t_node **stack_a, int print_flag, t_config *config);
void	rb(t_node **stack_b, int print_flag, t_config *config);
void	rr(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config);
void	rra(t_node **stack_a, int print_flag, t_config *config);
void	rrb(t_node **stack_b, int print_flag, t_config *config);
void	rrr(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config);
void	assign_index(t_node *a);
void	bring_max_to_top(t_node **stack, t_config *config);
void	push_back_to_a(t_node **a, t_node **b, t_config *config);
void	medium_sort(t_node **a, t_node **b, t_config *config);
long    atol(const char *nptr);
double	compute_disorder(t_node *stack_a);
#endif
