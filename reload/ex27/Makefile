# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 17:06:46 by zqiu              #+#    #+#              #
#    Updated: 2024/06/11 17:06:54 by zqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = main.c

OFILES = main.o

all : $(NAME)


$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OFILES)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
