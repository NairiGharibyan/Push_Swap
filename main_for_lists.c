/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:44:41 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/06 19:45:03 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
    int     arr[] = {3, 2, 1};
    t_node  *a;
    t_node  *tmp;

    a = build_stack(arr, 3);

    tmp = a;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }

    free_list(a);
    return (0);
}
