/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:27 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/06 23:30:26 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
    int     i;
    int     j;
    char    **split_array;
    int     checkednum;

    i = 1;
    while(i < argc)
    {
        split_array = ft_split(argv[i], ' ');
        i++;
        j = 0;
        while(split_array[j])
        {
            if (isnum(split_array[j]))
            {
                checkednum = atol(split_array[j]);
                if (checkednum < INT_MIN || chekedum > INT_MAX)
                        write(2, "error\n", 7);
                    return (0);
            }
            j++;
        }
    }
}