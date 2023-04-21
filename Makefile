# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 19:03:31 by mkaratzi          #+#    #+#              #
#    Updated: 2023/04/05 08:05:14 by mkaratzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
COMPILE_FLAGS = -Wall -Wextra -Werror
SERVER_SRC = server.c
CLIENT_SRC = client.c

CLIENT_NAME = client
MINITALK_SRC = \
	ft_printf_main.c  ft_intdigit.c ft_inthex.c ft_intitoa.c ft_atoi.c\
	ft_intptr.c ft_intputchar.c ft_intstr.c ft_intstrlen.c \
	ft_intutoa.c  ft_intudigits.c \

.PHONY: all clean fclean re

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_SRC:.c=.o) $(MINITALK_SRC:.c=.o)
	gcc  -o $(CLIENT_NAME) $(CLIENT_SRC:.c=.o) $(MINITALK_SRC:.c=.o)

$(CLIENT_SRC:.c=.o): $(CLIENT_SRC)
	gcc  -c $(COMPILE_FLAGS) $(CLIENT_SRC)

$(MINITALK_SRC:.c=.o): $(MINITALK_SRC)
	gcc  -c $(COMPILE_FLAGS) $(MINITALK_SRC)

$(SERVER_NAME): $(SERVER_SRC:.c=.o) $(MINITALK_SRC:.c=.o)
	gcc  -o $(SERVER_NAME) $(SERVER_SRC:.c=.o) $(MINITALK_SRC:.c=.o)

$(SERVER_SRC:.c=.o): $(SERVER_SRC)
	gcc  -c $(COMPILE_FLAGS) $(SERVER_SRC)

clean:
	rm -f $(MINITALK_SRC:.c=.o) $(SERVER_SRC:.c=.o) $(CLIENT_SRC:.c=.o)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all
