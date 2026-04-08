#include "push_swap.h"

void    parse_flags(int argc, char **argv, t_config *config)
{
    int     i;

    i = 1;
    while(i < argc)
    {
        if (ft_strcmp(argv[i], "--bench") == 0)
            config->bench_mod = 1;
        else if (ft_strcmp(argv[i], "--simple") == 0)
            config->algo_type = 1;
        else if (ft_strcmp(argv[i], "--medium") == 0)
            config->algo_type = 2;
        else if (ft_strcmp(argv[i], "--complex") == 0)
            config->algo_type = 3;
        else if (ft_strcmp(argv[i], "--adaptive") == 0)
            config->algo_type = 4;
        else
            break;
        i++;
    }
    config->start_idx = i;
}