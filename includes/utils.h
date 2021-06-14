/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:40:19 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 18:34:17 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./structs.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define BUFFER_SIZE 3

int		push(t_stack **stack, int data, int chunk);
int		pop(t_stack **stack);
int		peek_s(const t_stack *stack);
int		stack_count(t_stack *s);
void	clear_stack(t_stack **stack, void (*f)(void *));
void	print_stack(t_stack *s);
t_list	*ft_lstnew(void *data);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstprint(t_list *lst);
int		get_next_line(int fd, char **line);
int		ft_readline(int fd, char **str);
char	*ft_checkerror(int fd, char **buff);
void	swap(t_stack **s);
void	swap_s(t_stack **s1, t_stack **s2);
void	push_a(t_stack **a, t_stack **b, int chunk);
void	push_b(t_stack **a, t_stack **b, int chunk);
void	rotate(t_stack **s);
void	rotate_r(t_stack **s1, t_stack **s2);
void	reverse_rotate(t_stack **s);
void	reverse_rotate_r(t_stack **s1, t_stack **s2);
void	ft_putendl_fd(char *s, int fd);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_puterror(void);
int		is_dup(int ac, char **av);
void	get_numbers(t_stack **a, int ac, char **av);
int		check_error(int ac, char **av);
int		check_sort(t_stack *a, t_stack *b);
void	do_opr(t_stack **a, t_stack **b, int chunk, char *opr);
void	exec_opr(t_stack **a, t_stack **b, int chunk, char *opr);
void	exec_loop(t_stack **a, t_stack **b, char *opr, int i);
#endif
