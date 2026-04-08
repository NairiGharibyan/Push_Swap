include "push_swap.h"

static void do_rotate(t_node **stack)
{
    t_node      *first;
    t_node      *last;

    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = first->next;
    last = *stack;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = first;
    first->next = NULL;
}
void ra(t_node **stack_a, int print_flag)
{
    do_rotate(stack_a);
    if (print_flag == 1)
        write(1, "ra\n", 3);
}
void rb(t_node **stack_b, int print_flag)
{
    do_rotate(stack_b);
    if (print_flag == 1)
        write(1, "rb\n", 3);
}
void rr(t_node **stack_a, t_node **stack_b, int print_flag)
{
    do_rotate(stack_a);
    do_rotate(stack_b);
    if (print_flag == 1)
        write(1, "rr\n", 3);
}
