# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 20:08:06 by djang             #+#    #+#              #
#    Updated: 2024/05/11 20:08:08 by djang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRCS = ./ft_utils.c ./server.c
CLIENT_SRCS = ./ft_utils.c ./client.c

SERVER_BONUS_SRCS = ./ft_utils.c ./server_bonus.c
CLIENT_BONUS_SRCS = ./ft_utils.c ./client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CCFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CCFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

%.o : %.c
	$(CC) $(CCFLAGS) -c $^

clean : 
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) \
	$(CLIENT_BONUS_OBJS)

fclean : clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)
$(SERVER_BONUS) : $(SERVER_BONUS_OBJS)
	$(CC) $(CCFLAGS) $(SERVER_BONUS_OBJS) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS)
	$(CC) $(CCFLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT_BONUS)

.PHONY : all clean fclean re bonus
