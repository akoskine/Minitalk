# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 12:14:51 by akoskine          #+#    #+#              #
#    Updated: 2024/11/12 14:49:56 by akoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
NAME_S	= server
NAME_C	= client
NAME_SB	= server_bonus
NAME_CB	= client_bonus

CC = cc

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SB = server_bonus.c
SRC_CB = client_bonus.c

OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SB = ${SRC_SB:.c=.o}
OBJ_CB = ${SRC_CB:.c=.o}

LIBFT_D = ./libft
LIBFT = ./libft/libft.a

PRINTF_D = ./printf
PRINTF = ./printf/libftprintf.a

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME_S) $(NAME_C)

$(LIBFT):
	$(MAKE) -C $(LIBFT_D)

$(PRINTF):
	$(MAKE) -C $(PRINTF_D)

$(NAME_S): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ_SERVER) -L $(LIBFT_D) -lft -L $(PRINTF_D) -lftprintf -o $(NAME_S)

$(NAME_C): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ_CLIENT) -L $(LIBFT_D) -lft -L $(PRINTF_D) -lftprintf -o $(NAME_C)

bonus: $(NAME_SB) $(NAME_CB)

$(NAME_SB): $(OBJ_SB) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ_SB) -L $(LIBFT_D) -lft -L $(PRINTF_D) -lftprintf -o $(NAME_SB)

$(NAME_CB): $(OBJ_CB) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ_CB) -L $(LIBFT_D) -lft -L $(PRINTF_D) -lftprintf -o $(NAME_CB)

clean:
	$(MAKE) clean -C $(LIBFT_D)
	$(MAKE) clean -C $(PRINTF_D)
	rm -f ${OBJ_SERVER}
	rm -f ${OBJ_CLIENT}
	rm -f ${OBJ_SB}
	rm -f ${OBJ_CB}

fclean: clean
	$(MAKE) fclean -C $(LIBFT_D)
	$(MAKE) fclean -C $(PRINTF_D)
	rm -f $(NAME_S) $(NAME_C) $(NAME_SB) $(NAME_CB)

re: fclean all

.PHONY:		all clean fclean re bonus