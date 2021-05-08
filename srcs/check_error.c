/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:53:43 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/02 17:01:10 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int    check_error(int ac, char **av)
{
    int i;

    i = 0;
    while (av[ac][i])
    {
         if (!(av[ac][0] == '+' || av[ac][0] == '-' || ft_isdigit(av[ac][i])))
            return 1;
        i++;
    }
    if (is_dup(ac, av))
        return (1);
    return (0); 
}