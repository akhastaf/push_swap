/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:49:56 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/23 14:53:00 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int     is_dup(int ac, char **av)
{
    int i;
    long t;
    
    t = ft_atoi(av[ac]);
    if (t < MIN_INT || t > MAX_INT)
        return (1);
    if (!av[ac + 1])
        return (0);
    i = ac + 1;
    while (av[i])
    {
        if (t == ft_atoi(av[i]))
            return (1);
        i++;
    }
    return (0);
}