# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 13:33:21 by akhastaf          #+#    #+#              #
#    Updated: 2021/04/21 13:33:22 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wall -Wextra -Werror
SRC_P = srcs/*.c
SRC_C = srcs/*.c

Name= push_swap


$(NAME):
		$(C) $(CFLAG) $(SRC_P) -o $(NAME)
		$(C) $(CFLAG) $(SRC_C) -o chceker

all : $(NAME)

clean : 
		rm -rf $(NAME) chceker
fclean :
		rm -rf $(NAME) chceker

re : fclean all

.PHONY: re fclean clean all