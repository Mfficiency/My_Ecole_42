# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm <mm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 10:32:22 by slosey            #+#    #+#              #
#    Updated: 2021/11/07 19:10:33 by mm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

FILES 		= ft_printf.c \
				./libft/ft_isalnum.c \
				./sources/ft_putstr.c

INCLUDES	= ./includes/ft_printf.h ./libft/libft.h
OBJECTS		= ${FILES:.c=.o}
CC			= gcc -c #$(CFLAGS)
AR			= ar rc
NORM_BIN	= norminette
NORM_FLAGS	= -RCheckForbiddenSourceHeader -RCheckDefine
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -I./${INCLUDES} 

TINCLUDES	= ./includes/ft_printf.h ./tests/testlib.h ./libft/libft.h
CTFLAGS 	= -Wall -Wextra -Werror -I./${TINCLUDES} 
TESTDIR		= tests
TESTFILES	= ${TESTDIR}/ft_main_test.c
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

test :		${NAME}
			${CC} ${CTFLAGS} ${TESTFILES} -L. -lft 

.PHONY:		all clean fclean re test