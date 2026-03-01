/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casparphilipproder <casparphilipproder@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:43:57 by casparphili       #+#    #+#             */
/*   Updated: 2026/03/01 16:08:02 by casparphili      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char desc_numbers[10]="0123456789";

void ft_print_numbers(void)
{
    for(int i=10; i >=0; i--)
    {
        write(1, &desc_numbers[i], 1);
    }
    write(1, "\n", 1);
}