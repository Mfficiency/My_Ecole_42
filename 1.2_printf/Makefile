# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 10:32:22 by mmeersma          #+#    #+#              #
#    Updated: 2021/11/11 13:01:14 by mmeersma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

FILES 		= ft_printf.c \
				./sources/ft_handle_c.c \
				./sources/ft_handle_i.c \
				./sources/ft_handle_p.c \
				./sources/ft_handle_u.c \
				./sources/ft_handle_x.c \
				./sources/ft_handle_xc.c \
				./sources/ft_itoa_base.c \
				./sources/ft_itoa.c \
				./sources/ft_putchar_count.c \
				./sources/ft_putstr_count.c \
				./sources/ft_str_tolower.c \
				./sources/ft_strdup.c \
				./sources/ft_strlen.c \
				./sources/ft_unsigned_itoa.c 
OBJECTS		= ${FILES:.c=.o}
CC			= gcc -c #$(CFLAGS)
AR			= ar rc
RM 			= rm -f

TINCLUDES	= ./includes/ft_printf.h ./tests/testlib.h
CTFLAGS 	= -Wall -Wextra -Werror -I./${TINCLUDES} 
TESTDIR		= tests
TESTFILES	= ${FILES} \
				./tests/ft_main_test.c 

TESTOBJ		= ${TESTFILES:.c=.o}
TESTNAME	= testfile

${NAME} : 	${OBJECTS}
			${AR} ${NAME} ${OBJECTS} 

%.o: %.c
	$(CC) $< -o $@ 
	
all : 		${NAME}

clean :
			${RM} ${OBJECTS}

fclean: 	clean
			${RM} ${NAME}

re : 		fclean all

test :		${TESTOBJ}
			${AR} ${TESTNAME} ${TESTOBJ} 

.PHONY:		all clean fclean re test