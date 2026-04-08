/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:36 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/08 15:20:13 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isnum(char *str)
{
    int i;
    i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while(str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
long	atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		++nptr;
	}
	return ((res) * (sign));
}
void	free_split(char **str)
{
	int		k;

	if (!str)
		return ;
	
	k = 0;
	while (str[k])
	{
		free(str[k]);
		k++;
	}
	free(str);
}
int	is_valid_input(char *str, t_node *stack_a)
{
	long	num;

	if (!isnum(str))
		return (0);
	
	num = atol(str);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	
	if (check_duplicate(stack_a, (int)num))
		return (0);
	return (1);
}
int check_duplicate(t_node *head, long num)
{
    t_node *tmp;

    tmp = head;
    while (tmp)
    {
        if (tmp->value == (int)num)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
static int	process_argument(char *arg, t_node **stack_a)
{
    char	**split_array;
    int		j;

    split_array = ft_split(arg, ' ');
    if (!split_array)
        return (0);
    j = 0;
    while (split_array[j])
    {
        if (!is_valid_input(split_array[j], *stack_a))
        {
            free_split(split_array);
            return (0);
        }
        add_back(stack_a, new_node((int)atol(split_array[j])));
        j++;
    }
    free_split(split_array);
    return (1);
}
t_node	*parse_arguments(int argc, char **argv, t_config *config)
{
    t_node	*stack_a;
    int		i;

    stack_a = NULL;
    i = confif -> start_idx;
    while (i < argc)
    {
        if (!process_argument(argv[i], &stack_a))
        {
            free_list(stack_a);
            return (NULL);
        }
        i++;
    }
    return (stack_a);
}
