# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:25:27 by tpaaso            #+#    #+#              #
#    Updated: 2023/01/02 12:08:26 by tpaaso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = libft/libft.a src/main.c src/find.c src/validate.c src/map.c

LIBFT = libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
	@make -C $(LIBFT)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) -I $(LIBFT)

clean:
	@make  clean -C $(LIBFT)
	@/bin/rm -f $(OBJECT)
	@make -C $(LIBFT) clean

fclean: clean
	@make  fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

