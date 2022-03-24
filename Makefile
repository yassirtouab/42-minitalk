# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 14:02:36 by ytouab            #+#    #+#              #
#    Updated: 2021/11/20 15:56:24 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

OBJS_CLIENT	= ${CSRCS:.c=.o}
OBJS_SERVER	= ${SSRCS:.c=.o}

SERVEREXE	= server
CLIENTEXE	= client

RM			= rm -f

GCCF		= gcc -Wall -Wextra -Werror

CSRCS		= client.c ft_utils1.c ft_utils2.c\

SSRCS		= server.c ft_utils1.c ft_utils2.c\


.c.o:
		${GCCF} -c $< -o ${<:.c=.o}


$(NAME):	server client


server:	${OBJS_SERVER}
		${GCCF} ${OBJS_SERVER} -o ${SERVEREXE}

client:	${OBJS_CLIENT}
		${GCCF} ${OBJS_CLIENT} -o ${CLIENTEXE}

all:	${NAME}

clean:
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean:	clean
		${RM} ${SERVEREXE} ${CLIENTEXE}

re:		fclean all
