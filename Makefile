# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 13:33:21 by akhastaf          #+#    #+#              #
#    Updated: 2021/06/14 18:41:05 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wall -Wextra -Werror
SRC =	./push_swap.c \
		./srcs/ft_atoi.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_strchr.c \
		./srcs/ft_strdup.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strndup.c \
		./srcs/operations.c \
		./srcs/operations2.c \
		./srcs/stack.c \
		./srcs/ft_strcmp.c \
		./srcs/list.c \
		./srcs/ft_puterror.c \
		./srcs/check_error.c \
		./srcs/get_numbers.c \
		./srcs/is_dup.c \
		./srcs/check_sort.c \
		./srcs/do_opr.c \
		./srcs/get_poflower.c \
		./srcs/get_pofhigher.c \
		./srcs/exec_loop.c \
		./srcs/exec_opr.c \
		./srcs/fill_stack.c \
		./srcs/first.c \
		./srcs/second.c \
		./srcs/copy.c \
		./srcs/from_a_to_b.c \
		./srcs/get_position.c \
		./srcs/is_chunkempty.c

SRC_BONUS = checker_bonus.c \
			srcs/ft_atoi.c \
			srcs/ft_isdigit.c \
			srcs/ft_putendl_fd.c \
			srcs/ft_strchr.c \
			srcs/ft_strdup.c \
			srcs/ft_strjoin.c \
			srcs/ft_strlen.c\
			srcs/ft_strndup.c \
			srcs/gnl_bonus.c \
			srcs/operations.c \
			./srcs/operations2.c \
			srcs/stack.c \
			srcs/ft_strcmp.c \
			srcs/list.c \
			srcs/ft_puterror.c \
			srcs/check_error.c \
			srcs/get_numbers.c \
			srcs/is_dup.c \
			srcs/check_sort.c \
			srcs/do_opr.c


NAME = push_swap

all : $(NAME)

$(NAME): $(SRC)
		@$(C) $(CFLAG) -g $(SRC) -o $(NAME)
		
bonus: $(SRC_BONUS)
		@$(C) $(CFLAG) -g $(SRC_BONUS) -o checker

debug :
		@$(C) $(CFLAG) $(SRC) -o $(NAME) -g -fsanitize=address
		@$(C) $(CFLAG) $(SRC_BONUS) -o checker -g -fsanitize=address

clean : 
		@rm -rf $(NAME) checker
fclean :
		@rm -rf $(NAME) checker

re : fclean all

.PHONY: re fclean clean all