/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:55:09 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:08:13 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_opr(t_stack **a, t_stack **b, int chunk, char *opr)
{
	ft_putendl_fd(opr, 1);
	do_opr(a, b, chunk, opr);
}
