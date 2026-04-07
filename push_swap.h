/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:59:35 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/07 19:44:37 by nagharib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;


t_node	*new_node(int value);
void	add_back(t_node **head, t_node *new);
t_node	*build_stack(int *arr, int size);
void	free_list(t_node *head);
int     isnum(char *str);
long    atol(const char *nptr);
// sa
// sb
#endif
