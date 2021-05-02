/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:35:04 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/01 16:48:03 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stack
{
    int data;
    int chunk;
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
}       t_checker;


#endif