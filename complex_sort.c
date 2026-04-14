#include "push_swap.h"

void	assign_pos(t_node *stack)
{
	int     i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

void	set_all_costs(t_node *a, t_node *b)
{
	int		cost_a;
	int		cost_b;
	int		size_a;
	int		size_b;
	t_node	*curr_a;

	assign_pos(a);
	assign_pos(b);
	size_a = stack_size(a);
	size_b = stack_size(b);
	curr_a = a;
	while(curr_a)
	{
	cost_a = calculate_cost(curr_a->pos, size_a);
	cost_b = calculate_cost(curr_a->target_node->pos, size_b);
	curr_a->cost = cost_a + cost_b;
	curr_a = curr_a->next;
	}
}
t_node	*get_cheapest_node(t_node *stack)
{
	long		min;
	t_node	*min_node;
	t_node	*current;

	if (!stack)
		return (NULL);
	min = stack->cost;
	min_node = stack;
	current = stack;
	while (current)
	{
		if (current->cost < min)
		{
			min = current->cost;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
void	rotate_both_up(t_node **a, t_node **b, t_node *cheapest_node, t_config *config)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, 1, config);
}
void	rotate_both_down(t_node **a, t_node **b, t_node *cheapest_node, t_config *config)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, 1, config);
}

void	do_move(t_node **a, t_node **b, t_node *cheapest_node, t_config *config)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	if (cheapest_node->pos <= size_a / 2 && cheapest_node->target_node->pos <= size_b / 2)
		rotate_both_up(a, b, cheapest_node, config);
	else if (cheapest_node->pos > size_a / 2 && cheapest_node->target_node->pos > size_b / 2)
		rotate_both_down(a, b, cheapest_node, config);
	rotate_a(a, cheapest_node, config);
	rotate_b(b, cheapest_node->target_node, config);
	pb(a, b, 1, config);
}

void    complex_sort(t_node **a, t_node **b, t_config *config)
{
    t_node  *cheapest;
    t_node  *target;

    pb(a, b, 1, config);
    pb(a, b, 1, config);
    while (stack_size(*a) > 3)
    {
        set_all_targets(*a, *b);
        set_all_costs(*a, *b);
        cheapest = get_cheapest_node(*a);
        do_move(a, b, cheapest, config);
    }
    sort_three(a, config);
    while (*b)
    {
        target = get_target_in_a(*a, (*b)->value);
        rotate_a(a, target, config);
        pa(a, b, 1, config);
    }
    final_alignment(a, config);
}
