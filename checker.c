/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:59:48 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 17:36:27 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"


void    check_opr(t_checker *c, char *opr)
{
    if (!(!ft_strcmp(opr, "sa") || !ft_strcmp(opr, "sb") || !ft_strcmp(opr, "ss")
    || !ft_strcmp(opr, "pa") || !ft_strcmp(opr, "pb") || !ft_strcmp(opr, "ra")
    || !ft_strcmp(opr, "rb") || !ft_strcmp(opr, "rr") || !ft_strcmp(opr, "rra")
    || !ft_strcmp(opr, "rrb") || !ft_strcmp(opr, "rrr")))
    {
        clear_stack(&(c->a), free);
        clear_stack((&c->b), free);
        ft_lstclear(&(c->op), free);
        ft_puterror();
    }
}

void    get_operations(t_checker *c)
{
    char    *opr; 
    c->op = NULL;
    while (get_next_line(0, &opr) > 0)
    {
        check_opr(c, opr);
        ft_lstadd_back(&(c->op), ft_lstnew(opr));   
    }
}



void    excute_operations(t_checker *c)
{
    t_list  *tmp;

    tmp = c->op;
    while (tmp)
    {
        do_opr(&(c->a), &(c->b), 0, tmp->data);
        tmp = tmp->next;
    }
}

int     main(int ac, char **av)
{
    t_checker *c;
    
    c = malloc(sizeof(t_checker));
    c->a = NULL;
    c->b = NULL;
    if (ac > 1)
    {
        get_numbers(&(c->a), ac - 1, av);
        get_operations(c);
        excute_operations(c);
        if (check_sort(c->a, c->b))
            ft_putendl_fd("OK", 1);
        else
            ft_putendl_fd("KO", 1);
        print_stack(c->a);
        print_stack(c->b);
        // print_stack(c->a);
        clear_stack(&(c->a), free);
        clear_stack(&(c->b), free);
        ft_lstclear(&(c->op), free);
    }
    return (0);
    
}