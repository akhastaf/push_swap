/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:51:27 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 16:58:34 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	get_numbers(t_stack **a, int ac, char **av)
{
	while (ac > 0)
	{
		if (check_error(ac, av))
		{
			clear_stack(a, free);
			ft_puterror();
		}
		push(a, ft_atoi(av[ac]), 0);
		ac--;
	}
}
