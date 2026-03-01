/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casparphilipproder <casparphilipproder@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:30:34 by casparphili       #+#    #+#             */
/*   Updated: 2026/03/01 14:12:55 by casparphili      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_print_alphabet(char *c)
{
    write(1, c, 29);
}

int main(void)
{
    ft_print_alphabet("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}