# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 16:52:08 by davioliv          #+#    #+#              #
#    Updated: 2024/05/29 16:52:12 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c moves.c sort_small.c utils.c free_all.c other_moves.c sort_mid.c checks.c sort_big.c big_sort_utils.c send_back.c
NAME = push_swap
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE = make -C
RM = rm -f
LIBDIR = libft
LIB = -L ${LIBDIR} -lft

all:	${NAME}

$(NAME):	${OBJ}
	${MAKE} ${LIBDIR}
	${CC} ${CFLAGS} ${OBJ} ${LIB} -o ${NAME}

clean:
	${MAKE} ${LIBDIR} clean
	${RM} ${OBJ}

fclean:	clean
	${MAKE} ${LIBDIR} fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all re fclean clean
