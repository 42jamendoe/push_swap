# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 18:29:24 by jamendoe          #+#    #+#              #
#    Updated: 2022/11/12 18:29:30 by jamendoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORY = ft_split.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strjoin.c \
			ft_isdigit.c \
			ft_strncmp.c \
			ft_strchr.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

MANDATORYO = $(MANDATORY:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -std=c99

REMOVE = rm -rf

AR = ar crs

all: $(NAME)

$(NAME): $(MANDATORYO)
	$(AR) $(NAME) $(MANDATORYO)

clean:
	$(REMOVE) $(MANDATORYO)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

