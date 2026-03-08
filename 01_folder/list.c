/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 07:04:45 by mnououal          #+#    #+#             */
/*   Updated: 2026/03/08 12:09:55 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

struct s_list
{
	int	size;
	int	*array;
};
typedef struct s_list	t_list;

void	init_list(t_list *list, int	*array, int size)
{
	int	i;

	list->size = size;
	list->array = malloc(sizeof(int) * list->size);
	i = 0;
	while (i < list->size)
	{
		list->array[i] = array[i];
		i++;
	}
}

void	remove_element(t_list *list, int element)
{
	int	*new_array;
	int	i;
	int	j;

	new_array = malloc(sizeof(int) * list->size - 1);
	i = 0;
	j = 0;
	while (i < list->size)
	{
		if (list->array[i] == element && i == j)
			i++;
		new_array[j] = list->array[i];
		i++;
		j++;
	}
	if (i == j)
	{
		free(new_array);
		return ;
	}
	free(list->array);
	list->size = list->size - 1;
	list->array = new_array;
}

void	clean_list(t_list *list)
{
	free(list->array);
	list->size = 0;
	list->array = NULL;
}

void	clean_matrix_list(int size, t_list building[size][size])
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			clean_list(&building[y][x]);
			x++;
		}
		y++;
	}
}

void	print_matrix_list(int size, t_list building[size][size])
{
	int		c;
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			c = building[y][x].array[0] + '0';
			write(1, &c, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
