/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:08:17 by mnououal          #+#    #+#             */
/*   Updated: 2026/03/08 12:24:40 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define SIZE 4
#define TRUE 1
#define FALSE 0

struct s_list
{
	int	size;
	int	*array;
};
typedef struct s_list	t_list;

struct s_pov
{
	int	top;
	int	bottom;
	int	left;
	int	right;
};
typedef struct s_pov	t_pov;

void	init_list(t_list *list, int	*array, int size);
void	remove_element(t_list *list, int element);
void	clean_list(t_list *list);
void	clean_matrix_list(int size, t_list building[size][size]);
void	print_matrix_list(int size, t_list building[size][size]);

t_pov	get_pov(int size, int *pov, int x, int y);

int		fill_pov(char *arg, int pov[SIZE*SIZE], int *nr_character);
int		fill_matrix(t_list building[SIZE][SIZE], int pov[SIZE*SIZE]);
int		apply_rules(t_list *building, t_pov pov_to_apply, int x, int y);
int		validation(t_list building[SIZE][SIZE]);
void	reset_array(int *array);

int	main(int argc, char **argv)
{
	int		pov[SIZE * SIZE];
	t_list	builing[SIZE][SIZE];
	int		nr_character;

	//START TO DELETE BEFORE PUSH
	argc = 2;
	argv[1] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	//END TO DELETE BEFORE PUSH

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!fill_pov(argv[1], pov, &nr_character)
		|| !fill_matrix(builing, pov))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_matrix_list(SIZE, builing);
	clean_matrix_list(SIZE, builing);
	return (0);
}

int	fill_pov(char *arg, int pov[SIZE*SIZE], int *nr_character)
{
	int		has_space;

	*nr_character = 0;
	has_space = TRUE;
	while (*arg)
	{
		if (has_space && *arg >= '1' && *arg <= (SIZE + '0'))
		{
			pov[*nr_character] = (int)(*arg - '0');
			*nr_character = *nr_character + 1;
			has_space = FALSE;
		}
		else if (!has_space && *arg == ' ')
			has_space = TRUE;
		else
			return (FALSE);
		arg++;
	}
	if (has_space == 1 || *nr_character != (SIZE * SIZE))
		return (FALSE);

	return (TRUE);
}

int	fill_matrix(t_list building[SIZE][SIZE], int pov[SIZE*SIZE])
{
	int		y;
	int		x;
	int		array[SIZE];

	x = 0;
	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			reset_array(array);
			init_list(&building[y][x], array, SIZE);
			if (!apply_rules(&building[y][x], get_pov(SIZE, pov, x, y), x, y))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	apply_rules(t_list *building, t_pov pov_to_apply, int x, int y)
{
	int	result;

	result = pov_to_apply.top + pov_to_apply.bottom;
	if (result > SIZE + 1 && result > SIZE - 1)
		return (FALSE);
	result = pov_to_apply.left + pov_to_apply.right;
	if (result > SIZE + 1 && result > SIZE - 1)
		return (FALSE);

	if (pov_to_apply.top == SIZE)
	{
		if (y != 0)
			remove_element(building, 1);
		if (y != 1)
			remove_element(building, 2);
		if (y != 2)
			remove_element(building, 3);
		if (y != 3)
			remove_element(building, 4);
	}
	else if (pov_to_apply.bottom == SIZE)
	{
		if (y != 3)
			remove_element(building, 1);
		if (y != 2)
			remove_element(building, 2);
		if (y != 1)
			remove_element(building, 3);
		if (y != 0)
			remove_element(building, 4);
	}
	else if (pov_to_apply.left == SIZE)
	{
		if (x != 0)
			remove_element(building, 1);
		if (x != 1)
			remove_element(building, 2);
		if (x != 2)
			remove_element(building, 3);
		if (x != 3)
			remove_element(building, 4);
	}
	else if (pov_to_apply.bottom == SIZE)
	{
		if (x != 3)
			remove_element(building, 1);
		if (x != 2)
			remove_element(building, 2);
		if (x != 1)
			remove_element(building, 3);
		if (x != 0)
			remove_element(building, 4);
	}
	return (TRUE);
}

void	reset_array(int *array)
{	
	int	x;

	x = 0;
	while (x <= SIZE)
	{
		array[x] = x + 1;
		x++;
	}
}
