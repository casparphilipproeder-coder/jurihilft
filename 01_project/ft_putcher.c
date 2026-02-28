/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casparphilipproder <casparphilipproder@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:51:11 by casparphili       #+#    #+#             */
/*   Updated: 2026/02/28 20:58:25 by casparphili      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char *c)
{
    write(1, c, 11);
}

int main(void)
{
    ft_putchar("Pushin, P\n");
}