# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 20:03:21 by dsayumi-          #+#    #+#              #
#    Updated: 2023/06/13 20:13:02 by dsayumi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = CC

RM = rm -f

SRCS = \
		get_next_line.c \
		get_next_line_utils.c

FLAGS = -Wall -Werror - Wextra

INCLUDE = ./include

OBJS = $(SRCS:.c = .o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I$(INCLUDE) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
