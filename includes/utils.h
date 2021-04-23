/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:40:19 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/23 12:32:53 by akhastaf         ###   ########.fr       */
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

// STACK
int     push(t_stack **stack, int data);
int     pop(t_stack **stack);
int     peek_s(const t_stack *stack);
int     stack_count(t_stack *s);
void    clear_stack(t_stack **stack, void (*f)(void *));
void    print_stack(t_stack *s);

// LIST
t_list	*ft_lstnew(void *data);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstprint(t_list *lst);

// GNL
int		get_next_line(int fd, char **line);
int		ft_readline(int fd, char **str);
char	*ft_checkerror(int fd, char **buff);

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
// long long	ft_atoi(const char *str);
long		ft_atoi(const char *str);
int		ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char  *s1, char  *s2);
size_t		ft_strlen(const char *s);
char		*ft_strndup(const char *s1, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void    ft_puterror(void);


#endif