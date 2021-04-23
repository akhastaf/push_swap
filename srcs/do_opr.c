/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_opr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:53:29 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/23 15:53:38 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void    do_opr(t_stack **a, t_stack **b, char *opr)
{
    if (!ft_strcmp(opr, "sa"))
        swap(a);
    if (!ft_strcmp(opr, "sb"))
        swap(b);
    if (!ft_strcmp(opr, "pa"))
        push_a(a, b);
    if (!ft_strcmp(opr, "pb"))
        push_b(a, b);
    if (!ft_strcmp(opr, "ra"))
        rotate(a);
    if (!ft_strcmp(opr, "rb"))
        rotate(b);
    if (!ft_strcmp(opr, "rr"))
        rotate_r(a, b);
    if (!ft_strcmp(opr, "rra"))
        reverse_rotate(a);
    if (!ft_strcmp(opr, "rrb"))
        reverse_rotate(b);
    if (!ft_strcmp(opr, "rrr"))
        reverse_rotate_r(a, b);
}