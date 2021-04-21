/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:40:19 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/21 17:14:33 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "./structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define BUFFER_SIZE 3

int     push(t_stack **stack, int data);
int     pop(t_stack **stack);
int     peek_s(const t_stack *stack);
int     stack_count(t_stack *s);
void    clear_stack(t_stack **stack, void (*f)(void *));
void    print_stack(t_stack *s);

// OPERATIONS
void    swap(t_stack **s);
void    swap_s(t_stack **s1, t_stack **s2);
void    push_a(t_stack **a, t_stack **b);
void    push_b(t_stack **a, t_stack **b);
void    rotate(t_stack **s);
void    rotate_r(t_stack **s1, t_stack **s2);
void    reverse_rotate(t_stack **s);
void    reverse_rotate_r(t_stack **s1, t_stack **s2);

// UTILS
void	ft_putendl_fd(char *s, int fd);
long		ft_atoi(const char *str);
int		ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char  *s1, char  *s2);
size_t		ft_strlen(const char *s);
char		*ft_strndup(const char *s1, size_t n);


#endif