# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhimanen <jhimanen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 18:23:34 by jhimanen          #+#    #+#              #
#    Updated: 2020/01/21 19:29:05 by jhimanen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = libft/libft.a src/main.c src/fillit.c src/validator.c src/prototypes.c

OBJECT = $(SRC:.c=.o)

LIBFT = libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(LIBFT)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJECT) $(SRCS)

clean:
	@/bin/rm -f $(OBJECT)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
