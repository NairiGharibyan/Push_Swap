/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:10:47 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/11 20:11:01 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     do_rev_rotate(t_node **stack)
{
    t_node      *last;
    t_node      *scnd_last;

    if (!*stack || !(*stack)->next)
        return ;

    last = *stack;
    while(last->next != NULL)
    {
        scnd_last = last;
        last = last->next;

    }
    scnd_last->next = NULL;
    last->next = *stack;
    *stack = last;
}
void rra(t_node **stack_a, int print_flag, t_config *config)
{
    do_rev_rotate(stack_a);
    config->op_counts[RRA]++;
    if (print_flag == 1)
        write(1, "rra\n", 4);
}
void rrb(t_node **stack_b, int print_flag, t_config *config)
{
    do_rev_rotate(stack_b);
    config->op_counts[RRB]++;
    if (print_flag == 1)
        write(1, "rrb\n", 4);
}
void rrr(t_node **stack_a, t_node **stack_b, int print_flag, t_config *config)
{
    do_rev_rotate(stack_a);
    do_rev_rotate(stack_b);
    config->op_counts[RRR]++;
    if (print_flag == 1)
        write(1, "rrr\n", 4);
}
