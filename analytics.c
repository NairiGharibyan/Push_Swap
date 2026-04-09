#include "push_swap.h"

double	compute_disorder(t_node *stack_a)
{
	double		mistakes;
	double		total_pairs;
	t_node		*inner;
	t_node		*outer;

	mistakes = 0;
	total_pairs = 0;
	if (!stack_a || !stack_a->next)
		return (0.0);
	outer = stack_a;
	while(outer->next != NULL)
	{
		inner = outer->next;
		while(inner != NULL)
		{
			if(outer->value > inner->value)
				mistakes++;
			total_pairs++;
			inner = inner->next;
		}
	outer = outer->next;
	}
	return (mistakes / total_pairs);
}
void	select_algorithm(t_config *config, t_node *stack_a)
{
	if (!stack_a || !config)
		return ;
	if (config->algo_type != 4)
		return ;
	config->disorder = compute_disorder(stack_a);
	if (config->disorder < 0.2)
		config->algo_type = 1;
	else if (config->disorder < 0.5)
		config->algo_type = 2;
	else
		config->algo_type = 3;
}