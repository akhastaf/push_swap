/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:59:48 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/22 17:48:19 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

void    ft_puterror(void)
{
    ft_putendl_fd("Error", 2);
    exit(1);
}
int     is_dup(int ac, char **av)
{
    int i;
    long t;
    
    t = ft_atoi(av[ac]);
    if (t < MIN_INT || t > MAX_INT)
        return 1;
    if (!av[ac + 1])
        return 0;
    i = ac + 1;
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
        if (!ft_isdigit(av[ac][i]))
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
        ft_putendl_fd("hi", 2);
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

void    do_opr(t_checker *c, char *opr)
{
    if (!ft_strcmp(opr, "sa"))
        swap(&(c->a));
    if (!ft_strcmp(opr, "sb"))
        swap(&(c->b));
    if (!ft_strcmp(opr, "pa"))
        push_a(&(c->a), &(c->b));
    if (!ft_strcmp(opr, "pb"))
        push_b(&(c->a), &(c->b));
    if (!ft_strcmp(opr, "ra"))
        rotate(&(c->a));
    if (!ft_strcmp(opr, "rb"))
        rotate(&(c->b));
    if (!ft_strcmp(opr, "rr"))
        rotate_r(&(c->a), &(c->b));
    if (!ft_strcmp(opr, "rra"))
        reverse_rotate(&(c->a));
    if (!ft_strcmp(opr, "rrb"))
        reverse_rotate(&(c->b));
    if (!ft_strcmp(opr, "rrr"))
        reverse_rotate_r(&(c->a), &(c->b));
}

void    excute_operations(t_checker *c)
{
    t_list  *tmp;

    tmp = c->op;
    while (tmp)
    {
        do_opr(c, tmp->data);
        tmp = tmp->next;
    }
}

// void    check_sort(t_checker *c)
// {
    
// }

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
        // check_sort(c);
        print_stack(c->a);
        
    }
    
}