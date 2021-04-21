/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:59:48 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/21 17:19:21 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

void    ft_puterror(void)
{
    ft_putendl_fd("Error\n", 2);
    exit(1);
}
int     is_dup(int ac, char **av)
{
    int i;
    int t;
    
    i = ac + 1;
    t = ft_atoi(av[i]);
    // if (t < MIN_INT || t > MAX_INT)
    //     return 1;
    while (av[i])
    {
        if (t == ft_atoi(av[i]))
            return 1;
        i++;
    }
    return 0;
}

int    check_error(int ac, char **av)
{
    int i;

    i = 0;
    while (av[ac][i])
    {
        if (ft_isdigit(av[ac][i]))
            return 1;
        i++;
    }
    if (is_dup(ac, av))
        return 1;
    return 0;
    
}

void     get_numbers(t_stack **a, int ac, char **av)
{
    while (ac > 0)
    {
        if (check_error(ac, av))
        {
            clear_stack(a, free);
            ft_puterror();
        }
        push(a, ft_atoi(av[ac]));
        ac--;
    }
}

int     main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    
    a = NULL;
    b = NULL;
    if (ac > 1)
    {
        get_numbers(&a, ac - 1, av);
        print_stack(a);
    }
    
}