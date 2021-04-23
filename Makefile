# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 13:33:21 by akhastaf          #+#    #+#              #
#    Updated: 2021/04/23 15:57:25 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wall -Wextra -Werror
SRC_P = push_swap.c srcs/ft_atoi.c srcs/ft_isdigit.c srcs/ft_putendl_fd.c \
		srcs/ft_strchr.c srcs/ft_strdup.c srcs/ft_strjoin.c srcs/ft_strlen.c\
		srcs/ft_strndup.c srcs/gnl.c srcs/operations.c srcs/stack.c \
		srcs/ft_strcmp.c srcs/list.c srcs/ft_puterror.c srcs/check_error.c \
		srcs/get_numbers.c srcs/is_dup.c srcs/check_sort.c srcs/do_opr.c

SRC_C = checker.c srcs/ft_atoi.c srcs/ft_isdigit.c srcs/ft_putendl_fd.c \
		srcs/ft_strchr.c srcs/ft_strdup.c srcs/ft_strjoin.c srcs/ft_strlen.c\
		srcs/ft_strndup.c srcs/gnl.c srcs/operations.c srcs/stack.c \
		srcs/ft_strcmp.c srcs/list.c srcs/ft_puterror.c srcs/check_error.c \
		srcs/get_numbers.c srcs/is_dup.c srcs/check_sort.c srcs/do_opr.c


NAME = push_swap

all : $(NAME)

$(NAME):
		@$(C) $(CFLAG) $(SRC_P) -o $(NAME)
		@$(C) $(CFLAG) $(SRC_C) -o checker

clean : 
		@rm -rf $(NAME) checker
fclean :
		@rm -rf $(NAME) checker

re : fclean all

.PHONY: re fclean clean all