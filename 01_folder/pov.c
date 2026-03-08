/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:10:06 by mnououal          #+#    #+#             */
/*   Updated: 2026/03/08 11:29:53 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_pov
{
	int	top;
	int	bottom;
	int	left;
	int	right;
};
typedef struct s_pov	t_pov;

t_pov	get_pov(int size, int *pov, int x, int y)
{
	t_pov	dto;

	dto.top = pov[x];
	dto.bottom = pov[x + size];
	dto.left = pov[y + size * 2];
	dto.right = pov[y + size * 3];
	return (dto);
}
