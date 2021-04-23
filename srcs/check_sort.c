/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:41:05 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/23 15:44:07 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int     check_sort(t_stack *a, t_stack *b)
{
    t_stack *tmp;

    if (b)
        return (0);
    tmp = a;
    while (tmp)
    {
        if (tmp->next && tmp->data > tmp->next->data)
            return (0);
        tmp = tmp->next;
    }
    
    return 1;
}
