/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:35:04 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/22 16:47:03 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stack
{
    int data;
    struct s_stack  *next;
} t_stack;

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct s_checker
{
    t_stack *a;
    t_stack *b;
    t_list  *op;
    char    **opr_str;
}       t_checker;


#endif