/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: nagharib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:59:35 by nagharib          #+#    #+#             */
/*   Updated: 2026/04/06 19:47:07 by nagharib         ###   ########.fr       */
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
#endif
=======
/*   By: arpbabay <arpbabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:22:15 by arpbabay          #+#    #+#             */
/*   Updated: 2026/04/06 22:25:37 by arpbabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int     isnum(char *str);
long    atol(const char *nptr);
>>>>>>> b8333332e6e1e37a1e78059311d092f484c1788f
