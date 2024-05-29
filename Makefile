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

SRC = push_swap.c
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
