/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casparphilipproder <casparphilipproder@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:45 by casparphili       #+#    #+#             */
/*   Updated: 2026/03/01 14:32:18 by casparphili      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char alphabet[26]="abcdefghijklmnopqrstuvwxyz";
void ft_print_reverse_alphabet(void)
{
    for (int i=25; i >= 0; i--)
    {
        write(1, &alphabet[i], 1);
    }
    write(1, "\n", 1);
}

int main(void)
{
    ft_print_reverse_alphabet();
    return 0;
}
