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
void rra(t_node **stack_a, int print_flag)
{
    do_rev_rotate(stack_a);
    if (print_flag == 1)
        write(1, "rra\n", 4);
}
void rrb(t_node **stack_b, int print_flag)
{
    do_rev_rotate(stack_b);
    if (print_flag == 1)
        write(1, "rrb\n", 4);
}
void rrr(t_node **stack_a, t_node **stack_b, int print_flag)
{
    do_rev_rotate(stack_a);
    do_rev_rotate(stack_b);
    if (print_flag == 1)
        write(1, "rrr\n", 4);
}